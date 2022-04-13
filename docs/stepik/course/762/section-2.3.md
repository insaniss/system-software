---
layout: default
---

<span>[Часть 2.3](){: .label }</span>

Какая утилита предназначена для определения типа файлов?

- [ ] `rm`
- [ ] `touch`
- [x] `file`
- [ ] `ls`

---

С помощью какой утилиты можно создать пустой файл?

- [x] `touch`
- [ ] `cp`
- [ ] `mv`
- [ ] `file`

---

Утилита `rm` удаляет файлы

- [x] Навсегда
- [ ] В корзину
- [ ] Не удаляет файлы

---

Имена файлов в Linux являются

- [x] Регистрозависимыми
- [ ] Зависит от типа файла
- [ ] Регистронезависимыми

---

Для рекурсивного копирования файлов команде cp необходимо указать ключ

- [ ] `-p`
- [x] `-r`
- [ ] `-f`
- [ ] `-i`

---

Напишите строку для полного (со всеми файлами и поддиректориями) удаления
директории `/home/box`

```shell
$ rm -rf /home/box
```

---
**Работа с файлами**

1. Создайте пустые файлы **file1** и **file2** в домашней директории.
2. Создайте директорию `~/default`, и скопируйте в нее все файлы из `/etc/default`.
3. Создайте директорию `~/newdir`, и переместите в нее файлы **rsyslog** и
   **syslog-ng** из `~/default`.
4. Удалите директорию `/var/cache/apt` со всем поддиректориями и файлами
   (используйте команду **sudo** для удаления с правами суперпользователя).

```shell
$ touch file1 file2
$ mkdir -p ~/default && cp -r /etc/default/* ~/default
$ mkdir -p ~/newdir && mv -r /home/box/default/rsyslog /home/box/default/syslog-ng ~/newdir
$ sudo rm -rf /var/cache/apt
```

<span class="d-block text-right">
  [Часть 2.2]({{ site.baseurl }}{% link docs/stepik/course/762/section-2.2.md %}){: .float-left }
  [Часть 2.4]({{ site.baseurl }}{% link docs/stepik/course/762/section-2.4.md %})
</span>