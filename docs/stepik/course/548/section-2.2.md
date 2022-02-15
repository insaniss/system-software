---
layout: default
---

<span>[Часть 2.2](){: .label }</span>

Вы пишете программу для обхода всех каталогов вашей файловой системы и подсчета количества
файлов. Какое условие наиболее подходит для того чтобы прекратить обход?

- [x] readdir вернул `NULL` 
- [ ] для текущего итератора `dirent` выполняется условие `dirent.d_type & DT_DIR`
- [ ] для текущего итератора `dirent` выполняется условие `!(dirent.d_type & DT_DIR)`

<span class="d-block text-right">
  [Часть 2.1]({{ site.baseurl }}{% link docs/stepik/course/548/section-2.1.md %}){: .float-left }
  [Часть 2.3]({{ site.baseurl }}{% link docs/stepik/course/548/section-2.3.md %})
</span>
