---
layout: default
---

<span>[Часть 1.3](){: .label }</span>

Вам требуется скомпилировать программу, состоящую из единственного файла _main.c_ в исполняемый
файл _loader_. Вы знаете, что данная программа использует `libdl` для загрузки динамических 
библиотек в _run-time_. Какая команда, на ваш взгляд, для этого больше всего подходит?
  
  - [ ] `gcc main.c -fPIC -ldl -L.`
  - [x] `gcc main.c -fPIC -ldl -o loader`
  - [ ] `gcc -o main.c -libdl -fPIC loader`
  - [ ] `gcc main.c -fPIC --shared -o loader`

---

Проверьте свои знания, отметьте верные утверждения.

  - [ ] `dlsym` должна вызываться перед каждым вызовом функции из библиотеки
  - [ ] загружаемые в run-time библиотеки должны находиться в текущем каталоге программы
  - [x] `LD_LIBRARY_PATH` позволяет указать, где dlopen будет искать библиотеки
  - [x] `extern "C"` в с++ файле отключает мэнглинг экпортируемых имен
  - [ ] `extern "C"` обеспечивает автоматическое приведение типов при вызове функций из 
  -     библиотеки

---

Разработать программу _solution_, обеспечивающую загрузку динамической библиотеки в режиме
исполнения. При запуске, программе передается имя динамической библиотеки, имя функции 
которая должна быть вызвана, и ее аргумент. Функция в библиотеке принимает на вход `int` и
возвращает `int`. Результат, возвращаемый функцией должен быть выведен отдельной строкой
(оканчиваться символом новой строки `\n`)  в `stdout`.

**Пример вызова**
```shell
./solution libShared.so someSecretFunctionPrototype 8
16
```
В примере, должна быть загружена библиотека `libShared.so`, в которой вызвана функция 
`someSecretFunctionPrototype` с аргументом `8`. Результат `(16)` выведен в `stdout`.

**Представление решения**

Решение предоставляется в виде двух файлов _solution.c_ и _Makefile_, в последнем 
предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.

**Вывод**

Программа выводит в стандартный поток вывода число, полученное после вызова функции, и
символ новой строки `\n`.

_solution.c_
```c
#include <dlfcn.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int (*some_function)(const int);

bool init_lib(const char *dlib, const char *lib) {
  void *handle = dlopen(dlib, RTLD_LAZY);
  if (handle == NULL) {
    return false;
  }
  some_function = dlsym(handle, lib);
  if (some_function == NULL) {
    return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  if (init_lib(argv[1], argv[2]))
    printf("%d\n", some_function(atoi(argv[3])));
  else
    printf("Library could not load!\n");
  return 0;
}
```

_Makefile_
```makefile
.PHONY: solution clean

solution: solution.c
	gcc $^ -fPIC -ldl -Wl,-rpath,. -o $@
clean:
	rm -rf *.o *.so
```

<span class="d-block text-right">
  [Часть 1.2]({{ site.baseurl }}{% link docs/stepik/course/548/section-1.2.md %}){: .float-left }
  [Часть 2.1]({{ site.baseurl }}{% link docs/stepik/course/548/section-2.1.md %})
</span>
