---
layout: default
---

<span>[Часть 3.5](){: .label }</span>

Разработать программу _solution_, которая осуществляет поиск родительского PID текущего
процесса в файловой системе proc и выводит найденное значение на консоль.  Результат,
возвращаемый функций должен быть выведен отдельной строкой(должен оканчиваться символом
перевода строки `\n`) в `stdio`.

__Пример вызова__

```shell
./solution
13221
```

_solution.c_

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 1024

char path[SIZE];
char line[SIZE];

int main()
{
  sprintf(path, "/proc/%d/status", getpid());

  FILE *file = fopen(path, "rb");
  
  int iteration = 0;
  while (iteration != 7) { 
    iteration++;
    fgets(line, SIZE, file);
  }

  int pid;
  sscanf(line, "PPid:	%d\n", &pid);
  printf("%d\n", pid);

  return 0;
}
```

---

Разработать программу _solution_, которая осуществляет поиск и подсчет числа процессов
с именем __genenv__ в системе Linux на которой выполняется программа.

__Пример вызова__

```shell
./solution
13
```

_solution.c_

```c
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  struct dirent **namelist;
  int n;
  
  n = scandir("/proc", &namelist, NULL, alphasort);
  if (n == -1) {
    perror("scansur");
    exit(EXIT_FAILURE);
  }

  FILE *f;
  char *name, path[1024];
  int count = 0;

  while (n--) {
    if (atoi(namelist[n]->d_name) != 0) {
      sprintf(path, "/proc/%s/comm", namelist[n]->d_name);
      f = fopen(path, "rb");

      fscanf(f, "%s", name);
      if (strcmp("genenv", name) == 0) {
        count++;
      }
      fclose(f);
    }
    free(namelist[n]);
  }
  free(namelist);
  printf("%d\n", count);

  exit(EXIT_SUCCESS);
}
```

---

Разработать программу _solution_, которая по заданному pid, осуществляет поиск пути
в дереве процессов до процесса с идентификатором 1 (init). Для каждого найденного процесса
печатается в отдельной строке его идентификатор.

__Пример вызова__

```shell
./solution 1766
1766
1299
465
1
```

_solution.c_

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 1024

char path[SIZE], line[SIZE];

int get_ppid(int pid) {
  sprintf(path, "/proc/%d/status", pid);
  FILE *file = fopen(path, "rb");
  int n = 0;
  while (n != 7) {
    n++;
    fgets(line, SIZE, file);
  }
  fclose(file);
  sscanf(line, "PPid: %d", &pid);
  return pid;
}

int main(int argc, char *argv[]) {
  int pid = atoi(argv[1]);
  while (pid) {
    printf("%d\n", pid);
    pid = get_ppid(pid);
  }
  return 0;
}
```

---

Разработать программу _solution_, которая по заданному pid, осуществляет поиск всех
потомков процесса с этим идентификатором и выводит их количество (включая процесс с
заданным pid).

__Пример вызова__

```shell
./solution 1233
76
```

_solution.c_

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PATH_PATTERN \
    "/proc/%d/task/%d/children"
#define SIZE 1024

char path[SIZE];

int dfs(int pid) {
  int res = 1;
  sprintf(path, PATH_PATTERN, pid, pid);
  FILE *f = fopen(path, "rb");
  int id;
  while (fscanf(f, "%d", &id) >= 0) {
    res += dfs(id);
  }
  fclose(f);
  return res;  
}

int main(int argc, char *argv[]) {
  int pid = atoi(argv[1]);
  printf("%d\n", dfs(pid));  
  return 0;
}
```

---

Разработать программу _solution_, которая при запуске себя "демонизирует" и остается
в памяти. Перед закрытием стандартного потока вывода ___stdout___ унаследованного от
родителя, программа должна вывести в него Pid процесса-демона.

__Пример вызова__

```shell
./solution
13221
```

_solution.c_
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fs.h>

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
  
  sleep(100);
  return 0;
}
```

<span class="d-block text-right">
  [Часть 3.2]({{ site.baseurl }}{% link docs/stepik/course/548/section-3.2.md %}){: .float-left }
  [Часть 4.1]({{ site.baseurl }}{% link docs/stepik/course/548/section-4.1.md %})
</span>
