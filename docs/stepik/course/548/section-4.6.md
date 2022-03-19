---
layout: default
---

<span>[Часть 4.6](){: .label }</span>

Некоторая утилита генерирует довольно большой вывод, а вам требуется всего-лишь посчитать 
количество символов '0' в этом выводе. Утилита при запуске принимает 1 параметр. Вам 
требуется разработать программу, которая вызывает указанную утилиту, с заданным параметром 
и подсчитывает количество символов '0' в ее выводе. Ваша программа принимает на вход 2 
параметра -- имя утилиты, в текущем каталоге и ее параметр. Ваша программа должна после 
подсчета вывести найденное число '0' в отдельной строке, заканчивающейся символом конца 
строки.

__Пример вызова__

```shell
$ ./solution someprog param
234222
```

__Представление решения__

Решение предоставляется в виде двух файлов _solution.c_ и _Makefile_, в последнем 
предполагается цель по умолчанию, которая приводит к сборке Вашего приложения. 
Бинарный файл вашего решения должен иметь имя __solution__.

__Вывод__

Программа выводит в стандартный поток вывода число (в отдельной строке)

_solution.c_

```c
#include <stdio.h>

char cmd[1024];

int main(int argc, char *argv[]) {
  sprintf(cmd, "%s %s", argv[1], argv[2]);
  
  FILE *f = popen(cmd, "r");
  if (f != NULL) {
    int count = 0;
    char c;
    while ((c = fgetc(f)) != EOF) {
      if(c == '0') count++;
    }
    printf("%d\n", count);    
    fclose(f);
  }
  return 0;
}
```

_Makefile_

```makefile
.PHONY: all clean

all: solution
solution:
  gcc -o solution solution.c
clean:
  rm -rf solution
```

---

В текущем каталоге есть 2 канала _in1_ _in2_, в которые в случайном порядке поступают числа,
которые необходимо просуммировать и вывести окончательную сумму на экран. Сумма выводится 
в отдельной строке, завершающейся символом конца строки. Признаком окончания подачи символов 
в каналы является закрытие этих каналов посылающей стороной.

Подсказка: для неблокирующего чтения использовать select.
Замечание: протокол обмена по каналу текстовый, то есть числа представлены строками

__Пример вызова__

```shell
$ ./solution
795
```

__Представление решения__

Решение предоставляется в виде двух файлов _solution.c_ и _Makefile_, в последнем
предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.
Бинарный файл вашего решения должен иметь имя __solution__.

__Вывод__

Программа выводит в стандартный поток вывода число (в отдельной строке)

_solution.c_

```c
#include <fcntl.h>
#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main(void) {
  int rc, maxfd, fd[2], sum[2] = {0, 0};
  struct timeval tm = {5, 0};
  char buff[32];
  fd_set watchset; /* fd для чтения */
  fd_set inset; /* обновляется select() */
  /* открыть оба канала */
  if ((fd[0] = open("in1", O_RDONLY | O_NONBLOCK)) < 0 ||
    (fd[1] = open("in2", O_RDONLY | O_NONBLOCK)) < 0) {
    perror("open");
    return 1;
  }
  /* начать чтение из обоих файловых дескрипторов*/
  FD_ZERO(&watchset);
  FD_SET(fd[0], &watchset);
  FD_SET(fd[1], &watchset);
  /* найти максимальный файловый дескриптор */
  maxfd = fd[0] > fd[1] ? fd[0] : fd[1];
  /* пока наблюдаем за одним из fd[0] или fd[1] */
  while (FD_ISSET(fd[0], &watchset)
      || FD_ISSET(fd[1], &watchset)) {
    /* здесь копируем watchset, потому что select() обновляет его */
    inset = watchset;
    if (select(maxfd + 1, &inset, NULL, NULL, &tm) < 0) {
      perror("select");
      return 1;
    }
    /* проверить, какой их файловых дескрипторов
     * готов для чтения из него */
    for (int i = 0; i < 2; i++) {
      if (FD_ISSET(fd[i], &inset)) {
        /* fd[i] готов для чтения, двигаться дальше... */
        rc = read(fd[i], buff, sizeof(char));
        if (rc < 0) {
          perror("read");
          return 1;
        } else if (!rc) {
          /* этот канал закрыт, не пытаться
           * читать из него снова */
          close(fd[i]);
          FD_CLR(fd[i], &watchset);
        } else {
          buff[rc] = '\0';
          sscanf(buff, "%d", &rc);
          sum[i] += rc;
        }
      }
    }
  }
  printf("%d\n", sum[0] + sum[1]);
  return 0;
}
```

_Makefile_

```makefile
.PHONY: all clean

all: solution
solution:
  gcc -std=c99 -o $@ solution.c
clean:
  rm -rf solution
```

---

Разработать приложение, умеющее обрабатывать сигналы SIGUSR1 ,SIGUSR2, SIGTERM. После старта
Ваше приложение должно по приходу одного из сигналов SIGUSR1,  SIGUSR2 выполнять суммирование
числа срабатываний каждого из сигналов, а после прихода сигнала SIGTERM, требуется вывести в 
стандартный поток вывода 2 числа, разделенных пробелом, соответствующих количеству обработанных
сигналов SIGUSR1, SIGUSR2, и завершить программу. Вывод оканчивается символом конца строки.

__Пример вызова__

```shell
$ ./solution
79 38
```

__Представление решения__

Решение предоставляется в виде двух файлов _solution.c_ и _Makefile_, в последнем
предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.
Бинарный файл вашего решения должен иметь имя __solution__.

__Вывод__

Программа выводит в стандартный поток вывода 2 числа, разделенных пробелом (Строка завершается
символом конца строки)

_solution.c_

```c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int sig1 = 0;
int sig2 = 0;

void sigusr1_handler(int signo) { sig1++; }  
void sigusr2_handler(int signo) { sig2++; }

void sigterm_handler(int signo) {
  printf("%d %d\n", sig1, sig2);
  exit(0);
}

int main(void) 
{
  signal(SIGUSR1, sigusr1_handler);
  signal(SIGUSR2, sigusr2_handler);
  signal(SIGTERM, sigterm_handler);
  while (1) {
    usleep(5000);
  }
  return 0;
}
```

_Makefile_

```makefile
.PHONY: all clean

all: solution
solution:
  gcc -o $@ solution.c
clean:
  rm -rf solution
```

---

В задании требуется доработать демон, разработанный ранее в задании 6 модуля 3.5. 
Задача -- снабдить демон обработчиком сигнала SIGURG, по приходу которого демон 
должен завершать свою работу.

__Пример вызова__

```shell
$ ./solution
13336
```

__Представление решения__

Решение предоставляется в виде двух файлов _solution.c_ и _Makefile_, в последнем
предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.
Бинарный файл вашего решения должен иметь имя __solution__.

__Вывод__

Программа выводит в стандартный поток PID созданного демона. (Строка завершается символом конца строки)

_solution.c_

```c
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int flag = 1;

void sigurg_handler(int signo) {
  printf("%d\n", getpid());
  flag = 0;
}

int main(void)
{
  pid_t pid = fork();

  if (pid == -1)
    return -1;

  if (pid != 0)
    exit(EXIT_SUCCESS);

  if (setsid() == -1)
    return -1;

  if (chdir("/") == -1)
    return -1;

  printf("%d\n", pid);

  close(0);
  close(1);
  close(2);

  usleep(500);
  signal(SIGURG, sigurg_handler);

  while (flag) { }
  return 0;
}
```

_Makefile_

```makefile
.PHONY: all clean

all: solution
solution:
  gcc -o $@ solution.c
clean:
  rm -rf solution
```

---

В системе существуют 2 региона разделяемой памяти, заполненной некоторыми числами (типа `int`).
Каждый из регионов имеет размер 1000 байт. Вам требуется разработать приложение, которое попарно
суммирует первые 100 чисел в этих регионах и помещает суммы в новый (созданный вашим
приложением) регион памяти размером 1000 байт. Таким образом, после завершения работы Вашего
приложения в памяти должен существовать регион разделяемой памяти размером 1000 байт,
содержащий в начале 100 сумм. Перед завершением работы приложение выводит в стандартный поток 
ввода-вывода ключ созданного региона, завершающийся символом конца строки. На вход ваше
приложение принимает ключи существующих регионов памяти.

__Пример вызова__

```shell
$ ./solution 456764 456768
512997
```

__Представление решения__

Решение предоставляется в виде двух файлов _solution.c_ и _Makefile_, в последнем
предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.
Бинарный файл вашего решения должен иметь имя __solution__.

__Вывод__

Программа выводит в стандартный поток вывода ключ созданного региона памяти (Строка 
завершается символом конца строки)

_solution.c_

```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define SHMSZ 1000

int main(int argc, char *argv[]) {
  int shmid[3], *shm[3];
  key_t key = ftok(argv[0], argc);

  if ((shmid[0] = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0
      || (shmid[1] = shmget(atol(argv[1]), SHMSZ, IPC_CREAT | 0666)) < 0
      || (shmid[2] = shmget(atol(argv[2]), SHMSZ, IPC_CREAT | 0666)) < 0)
  {
    perror("shmget");
    exit(1);
  }

  if ((shm[0] = shmat(shmid[0], NULL, 0)) == NULL
      || (shm[1] = shmat(shmid[1], NULL, 0)) == NULL
      || (shm[2] = shmat(shmid[2], NULL, 0)) == NULL)
  {
    perror("shmat");
    exit(1);
  }

  for (int i = 0; i < 100; i++) {
    shm[0][i] = shm[1][i] + shm[2][i];
  }

  printf("%d\n", key);

  return 0;
}
```

_Makefile_

```makefile
.PHONY: all clean

all: solution
solution:
  gcc -std=c99 -o $@ solution.c
clean:
  rm -rf solution
```

<span class="d-block text-right">
  [Часть 4.1]({{ site.baseurl }}{% link docs/stepik/course/548/section-4.1.md %}){: .float-left }
  [Часть 5.2]({{ site.baseurl }}{% link docs/stepik/course/548/section-5.2.md %})
</span>
