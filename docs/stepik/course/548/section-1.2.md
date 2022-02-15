---
layout: default
---

<span>[Часть 1.2](){: .label }</span>

Проверьте свои знания. Отметьте верные высказывания.

  - [x] Для сборки динамической библиотеки gcc требуется указать опцию `--shared`
  - [ ] GNU make может использоваться только для сборки программ на С/С++
  - [x] Для вывода символических имен объектного(бинарного) файла используется `nm`
  - [x] `с++filt` используется для восстановления исходного имени функций (Demangle)
  -     на языках на C++ и Java
  - [ ] Для вывода символических имен объектного(бинарного) файла используется `stat`
  - [x] В основе работы make лежит информация о зависимостях частей проекта 

---

Найдите соответствие между прототипами функций С++ и их закодированными именами

  | Закодированные имена         | Функция                             |
  |:-----------------------------|:------------------------------------|
  | `_Z8getValuei`{: .fs-2 }     | `getValue(int)`{: .fs-2 }           |
  | `_Z8getValuePFviE`{: .fs-2 } | `getValue(void (*)(int))`{: .fs-2 } |
  | `_Z8getValuePvi`{: .fs-2 }   | `getValue(void*, int)`{: .fs-2 }    |
  | `_Z8getValuev`{: .fs-2 }     | `getValue()`{: .fs-2 }              |

---

В этом задании Вам необходимо создать разделяемую динамическую библиотеку `libsolution.so` 
в которой реализовать функцию со следующим прототипом:
```c
int stringStat(const char *string, size_t multiplier, int *count);
```
Функция возвращает значение длины строки `string`, умноженное на `multiplier`, и увеличивает
на 1 значение, на которое указывает `count`.

**Представление решения**

Решение предоставляется в виде двух файлов `solution.c` и `Makefile`, в последнем 
предполагается цель по умолчанию, которая приводит к сборке Вашей библиотеки.

**Вывод**

Программа (функция в библиотеке) ничего не выводит на консоль

*solution.c*
```c
#include <string.h>

int stringStat(const char *string, size_t multiplier, int *count) {
  *count = *count + 1;
  return (int) (strlen(string) * multiplier);
}
```
*Makefile*
```makefile
all: solution.c
	gcc --shared -fPIC -o libsolution.so solution.c
```

<span class="d-block text-right">
  [Часть 1.1]({{ site.baseurl }}{% link docs/stepik/course/548/section-1.1.md %}){: .float-left }
  [Часть 1.3]({{ site.baseurl }}{% link docs/stepik/course/548/section-1.3.md %})
</span>
