---
layout: default
---

<span>[Часть 2.4](){: .label }</span>

Какая утилита позволяет вывести несколько строк с начала файла?

- [x] `head`
- [ ] `less`
- [ ] `more`
- [ ] `tail`

---

Какая утилита позволяет вывести несколько строк с конца файла?

- [ ] `more`
- [x] `tail`
- [ ] `head`
- [ ] `less`

---

Какие утилиты позволяют просматривать длинные файлы, разделив их на страницы?

- [x] `less`
- [x] `more`
- [ ] `tail`
- [ ] `head`

---

Напишите команду для вывода двух последних строк из файла `/etc/fstab`

```shell
$ tail -n 2 /etc/fstab
```

---

С помощью утилиты cat создайте файл `~/resolv.conf` из файлов **head** **base**
**google1** **google2**, расположенных в каталоге `/etc/resolvconf/resolv.conf.d`.

Внимание! Сохраняйте последовательность файлов в команде cat, как указано в этом задании.

```shell
$ cat /etc/resolvconf/resolv.conf.d/{head,base,google{1,2}} >resolv.conf
```

<span class="d-block text-right">
  [Часть 2.3]({{ site.baseurl }}{% link docs/stepik/course/762/section-2.3.md %}){: .float-left }
  [Часть 2.5]({{ site.baseurl }}{% link docs/stepik/course/762/section-2.5.md %})
</span>