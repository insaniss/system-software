---
layout: default
---

<span>[Часть 3.1](){: .label }</span>

Сколько аргументов передается с помощью данной строки команды (не считая самой
команды)
```shell
$ touch '/etc/cron/cron.allow' 'file 42.txt' "file 33.txt" file11.txt
```

Ответ: `4`

---

В каких случа**ях** количество пробелов между словами **foo** и **bar** будет
сохранено в результате выполнения команды `echo`?

- [x] `echo "foo bar"`
- [ ] `echo foo bar`
- [ ] `echo [foo bar]`
- [ ] `echo (foo bar)`
- [x] `echo 'foo bar'`

---

Какая команда предназначена для определения, будет ли переданная командной
оболочке команда исполнена как внешняя команда или как встроенная команда?

- [x] `type`
- [ ] `which`
- [ ] `touch`

---

Какая команда осуществляет поиск бинарных файлов в директории, заданной с
помощью переменной окружения $PATH?

- [ ] `find`
- [ ] `search`
- [ ] `type`
- [x] `which`

---

Напишите команду для создания псевдонима для команды "ls -lh", и назовите
псевдоним "lh".

```shell
$ alias lh="ls -lh"
```

---

Проверьте с помощью `type` и `which`, какие команды являются встроенными в
командную оболочку, а какие внешними:

- `alias`
- `echo`
- `rm`
- `route`
- `tac`
- `which`

Проверьте с помощью `which` в каких директориях находятся бинарные файлы
внешних команд. Запишите или запомните результат.

```shell
$ type alias echo rm route tac which
$ which alias echo rm route tac which
```

---

Отметьте команды, встроенные в командную оболочку

- [ ] `rm`
- [x] `echo`
- [ ] `which`
- [ ] `tac`
- [x] `alias`
- [ ] `route`

---

Отметьте внешние команды

- [x] `rm`
- [ ] `alias`
- [x] `tac`
- [x] `route`
- [x] `which`
- [x] `echo`

---

Сопоставьте бинарные файлы с их директориями

|         |            |
|:--------|:-----------|
| `alias` |            | 
| `route` | `/sbin`    |
| `rm`    | `/bin`     |
| `tac`   | `/usr/bin` |

<span class="d-block text-right">
  [Часть 2.5]({{ site.baseurl }}{% link docs/stepik/course/762/section-2.5.md %}){: .float-left }
  [Часть 3.2]({{ site.baseurl }}{% link docs/stepik/course/762/section-3.2.md %})
</span>
