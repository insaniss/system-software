#include <iostream>
#include <pthread.h>
#include <unistd.h>

#include "producer_consumer.h"

struct producer_argument {
  int id;
  int *shared;

  producer_argument(int id, int *shared)
      : id(id), shared(shared) {};
};

struct consumer_argument {
  int id;
  int sleep_limit;
  int *shared;

  consumer_argument(int id, int sleep_limit, int *shared)
      : id(id), sleep_limit(sleep_limit), shared(shared) {}
};

struct interruptor_argument {
  int id;
  pthread_t *consumers;
  int count;

  interruptor_argument(int id, pthread_t *consumers, int count)
      : id(id), consumers(consumers), count(count) {}
};

static bool debug = false;

static void print_debug_message(int id, int sum) {
  if (debug) std::fprintf(stderr, "tid=%d tsum=%d\n", id, sum);
}

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cv_producer = PTHREAD_COND_INITIALIZER;
static pthread_cond_t cv_consumer = PTHREAD_COND_INITIALIZER;
static pthread_key_t tid;
static pthread_barrier_t barrier;

static bool ready = false;
static bool finished = false;

// 1 to 3+N thread ID
static int get_tid() {
  auto value = (int *) pthread_getspecific(tid);
  return value ? *value : -1;
}

// read data, loop through each value and update the value, notify consumer,
// wait for consumer to process
static void *producer_routine(void *arg) {
  auto *val = static_cast<producer_argument *>(arg);

  pthread_setspecific(tid, new int(val->id));

  while (std::cin >> *val->shared) {
    pthread_mutex_lock(&mutex);
    ready = true;
    pthread_cond_signal(&cv_consumer);
    while (ready) {
      pthread_cond_wait(&cv_producer, &mutex);
    }
    pthread_mutex_unlock(&mutex);
  }

  finished = true;
  pthread_mutex_lock(&mutex);
  pthread_cond_broadcast(&cv_consumer);
  pthread_mutex_unlock(&mutex);
  return nullptr;
}

// for every update issued by producer, read the value and add to sum
// return pointer to result (for particular consumer)
static void *consumer_routine(void *arg) {
  auto *val = static_cast<consumer_argument *>(arg);
  int sum = 0;

  pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, nullptr);
  pthread_barrier_wait(&barrier);
  pthread_setspecific(tid, new int(val->id));

  while (!finished) {
    pthread_mutex_lock(&mutex);
    while (!finished && !ready) {
      pthread_cond_wait(&cv_consumer, &mutex);
    }
    if (ready) {
      sum += *val->shared;
      ready = false;
      print_debug_message(get_tid(), sum);
    }
    pthread_cond_signal(&cv_producer);
    pthread_mutex_unlock(&mutex);

    usleep(std::rand() % val->sleep_limit);
  }

  return new int(sum);
}

// interrupt random consumer while producer is running
static void *consumer_interruptor_routine(void *arg) {
  auto *val = static_cast<interruptor_argument *>(arg);

  pthread_barrier_wait(&barrier);
  pthread_setspecific(tid, new int(val->id));

  while (!finished) {
    pthread_cancel(val->consumers[std::rand() % val->count]);
  }

  return nullptr;
}

// start N threads and wait until they're done
// return aggregate sum of value
int run_threads(int n, int limit, bool debug_enabled) {
  debug = debug_enabled;
  pthread_t producer_tid, interruptor_tid, *consumer_tid = new pthread_t[n];
  int shared_value, *sum, result = 0;

  pthread_key_create(&tid, nullptr);
  pthread_barrier_init(&barrier, nullptr, n + 1);

  pthread_create(&producer_tid, nullptr, producer_routine,
                 new producer_argument(1, &shared_value));
  pthread_create(&interruptor_tid, nullptr, consumer_interruptor_routine,
                 new interruptor_argument(2, consumer_tid, n));

  for (int i = 0; i < n; i++) {
    pthread_create(&consumer_tid[i], nullptr, consumer_routine,
        new consumer_argument(3 + i, 1000 * limit + 1, &shared_value));
  }

  pthread_join(producer_tid, nullptr);
  pthread_join(interruptor_tid, nullptr);

  for (int i = 0; i < n; i++) {
    pthread_join(consumer_tid[i], (void **) &sum);
    result += *sum;
  }

  pthread_barrier_destroy(&barrier);
  pthread_key_delete(tid);

  return result;
}
