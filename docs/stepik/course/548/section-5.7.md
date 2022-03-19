---
layout: default
---

<span>[Часть 5.7](){: .label }</span>

Разработайте утилиту командной строки, принимающую на вход имя хоста и печатающую в 
стандартный поток вывода список IP-адресов, ассоциированных с данным именем.

__Пример вызова__

```shell
$ ./solution yandex.ru
213.180.204.3
93.158.134.3
213.180.193.3
```

__Представление решения__

Решение предоставляется в виде двух файлов _solution.c_ и _Makefile_, в последнем
предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.
Бинарный файл вашего решения должен иметь имя __solution__.

__Вывод__

Программа выводит в стандартный поток вывода IP-адреса, причем каждый адрес должен
быть выведен на отдельной строчке, оканчивающейся символом конца строки.

_solution.c_

```c
#include <netdb.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    return 1;
  }
  struct hostent *h = gethostbyname(argv[1]);
  if (h == NULL) {
    printf("Oops...\n");
    return 1;
  }
  int i;
  while (h->h_addr_list[i] != NULL) {
    struct in_addr *a = (struct in_addr *) h->h_addr_list[i++];
    printf("%s\n", inet_ntoa(*a));
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

Разработайте UDP сервер для логирования (сбора и записи) сообщений. Сервер при запуске
принимает параметр -- номер порта, на котором будут приниматься запросы. Каждый запрос
приходящий к серверу -- строка, не превышающая размер `5K`.  Задача сервера -- выводить
приходящие строки в стандартный поток ввода-вывода, завершающиеся символом конца строки.

Сервер завершает работу, когда получает строку содержащую только текст `OFF`, и 
заканчивающуюся символом перевода строки `\n`.

Сервер использует локальный адрес `127.0.0.1`

__Пример вызова__

```shell
$ ./solution 22476
foo
bar 
foo bar baz
```

__Представление решения__

Решение предоставляется в виде двух файлов _solution.c_ и _Makefile_, в последнем
предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.
Бинарный файл вашего решения должен иметь имя __solution__.

__Вывод__

Программа выводит в стандартный поток строки, причем каждая строка должна оканчиваться 
символом конца строки.

_solution.c_

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

struct sockaddr_in local;

int main(int argc, char *argv[])
{
  int s = socket(AF_INET, SOCK_DGRAM, 0);

  inet_aton("127.0.0.1", &local.sin_addr);
  local.sin_port = htons(atoi(argv[1]));
  local.sin_family = AF_INET;

  int result = bind(s, (struct sockaddr *) &local, sizeof(local));

  char buff[BUFSIZ];
  const char *target = "OFF\n";
  while (1) {
    size_t len = read(s, buff, BUFSIZ);
    buff[len] = '\0';
    if (strcmp(buff, target) == 0) {
      break;
    }
    printf("%s\n", buff);
  }
  return 0;
}
```

_Makefile_

```makefile
.PHONY: all solution

all: solution
solution:
  gcc -o $@ solution.c
clean:
  rm -rf solution
```

---

Разработайте TCP сервер, предназначенный для сортировки символов в строке. Сервер 
получает на вход строки, оканчивающиеся символом `\0`, сортирует в них символы 
в порядке убывания ASCII-кодов и отсылает обратно на клиент, в виде строки 
заканчивающейся `\0`. Завершение работы сервера происходит после получения строки,
содержащей только `OFF`.

При старте сервер получает на вход номер порта в качестве параметра командной строки. 
`bind` производится на адресе `127.0.0.1`

__Пример вызова__

```shell
$ ./solution 13555
```

__Представление решения__

Решение предоставляется в виде двух файлов _solution.c_ и _Makefile_, в последнем
предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.
Бинарный файл вашего решения должен иметь имя __solution__.

_solution.c_

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

struct sockaddr_in local;

int comp(const void *elem1, const void *elem2) {
  char f = *((char *) elem1);
  char s = *((char *) elem2);
  if (f < s) return 1;
  if (f > s) return -1;
  return 0;
}

int main(int argc, char *argv[]) {
  int ss = socket(AF_INET, SOCK_STREAM, 0);
  int cs;

  inet_aton("127.0.0.1", &local.sin_addr);
  local.sin_port = htons(atoi(argv[1]));
  local.sin_family = AF_INET;

  bind(ss, (struct sockaddr *) &local, sizeof(local));
  listen(ss, 5);

  cs = accept(ss, NULL, NULL);

  char buff[BUFSIZ];
  const char *target = "OFF";
  while (1) {
    size_t len = read(cs, buff, BUFSIZ);
    if (strcmp(buff, target) == 0) {
      break;
    }
    qsort(buff, strlen(buff), 1, comp);
    write(cs, buff, len);
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

<span class="d-block text-right">
  [Часть 5.3]({{ site.baseurl }}{% link docs/stepik/course/548/section-5.3.md %}){: .float-left }
</span>
