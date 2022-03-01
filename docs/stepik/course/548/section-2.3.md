---
layout: default
---

<span>[Часть 2.3](){: .label }</span>

Перед вами следующий консольный вывод. Отметьте верные высказывания относительно файлов.
```
kkv@thinkpag:/tmp/test$ ls -lai
total 76
2376174 drwxrwxr-x  2 kkv  kkv   4096 мая   17 22:19 .
2359297 drwxrwxrwt 18 root root 69632 мая   17 22:17 ..
2362904 -rw-rw-r--  1 kkv  kkv      0 марта 10  2012 file1
2362910 lrwxrwxrwx  1 kkv  kkv      5 мая   17 22:09 file2 -> file1
2362911 lrwxrwxrwx  1 kkv  kkv      5 мая   17 22:09 file3 -> file2
2362913 lrwxrwxrwx  1 kkv  kkv     20 мая   17 22:19 libMylib.so.2.3.1 -> libSolution.so.1.2.3
2362012 lrwxrwxrwx  1 kkv  kkv     17 мая   17 22:09 libSolution.so.2.2.3 -> libMylib.so.2.3.1
2363908 -rw-rw-r--  2 kkv  kvv      0 марта 10  2012 makefile
2363908 -rw-rw-r--  2 kkv  kvv      0 марта 10  2012 Makefile
```

- [x] команда 'touch libSolution.so.1.2.3' "починит" все ссылки в данном каталоге 
- [x] Makefile является жесткой ссылкой на makefile 
- [x] cat libMylib.so.2.3.1 вернет ошибку "No such file or directory"
- [ ] если удалить makefile, то автоматически удалится Makefile 
- [x] file2 является символической (мягкой) ссылкой на file1

<span class="d-block text-right">
  [Часть 2.2]({{ site.baseurl }}{% link docs/stepik/course/548/section-2.2.md %}){: .float-left }
  [Часть 2.4]({{ site.baseurl }}{% link docs/stepik/course/548/section-2.4.md %})
</span>
