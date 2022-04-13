---
layout: default
---

<span>[Часть 7.2](){: .label }</span>

Где расположена локальная база данных учетных записей пользователей в Linux?

- [ ] `/etc/default`
- [x] `/etc/passwd`
- [ ] `/home`
- [ ] `/etc/skel`

---

Какой пользователь является наиболее привилегированным в ОС Linux?

- [ ] `admin`
- [ ] `su`
- [ ] `sudo`
- [x] `root`

---

Сопоставьте утилиты с их функциями

|           |                                            |
|:----------|:-------------------------------------------|
| `userdel` | удаляет учетные записи пользователей       |
| `usermod` | изменяет параметры учетных записей         |
| `useradd` | добавляет учетны записи пользователей в БД |

----

Какая директория выступает в роли шаблона домашней директории и стандартного
профиля пользователя?

- [ ] `/etc/default`
- [x] `/etc/skel`
- [ ] `/home/skel`
- [ ] `/home/default`

---

1. Создайте пользователя **user01**, с домашней директорией `/home/u01d` и
   командной оболочкой по умолчанию Korn shell.
2. Удалите учетные записи пользователей, которые используют командную оболочку C shell.
3. Удалите учетную запись и домашнюю директорию пользователя **test02**.

```shell
$ sudo useradd -m user01 -d /home/u01d -s /bin/ksh
$ sudo deluser `grep "/bin/csh" /etc/passwd | cut -d: -f1`
$ sudo userdel -r test02
```

<span class="d-block text-right">
  [Часть 7.1]({{ site.baseurl }}{% link docs/stepik/course/762/section-7.1.md %}){: .float-left }
  [Часть 7.3]({{ site.baseurl }}{% link docs/stepik/course/762/section-7.3.md %})
</span>
