---
layout: default
---

<span>[Часть 4.1](){: .label }</span>

Сопоставьте имена и номера потоков ввода-вывода

|          |    |
|:---------|:---|
| `stdin`  | 0  |
| `stdout` | 1  |
| `stderr` | 2  |

---

В каких случаях содержимое файла будет удалено перед записью новой информации?

- [ ] `echo Hello world! <hello`
- [x] `echo Hello world! >hello`
- [ ] `echo Hello world! >>hello`
- [x] `echo Hello world! >|hello`

---

В каких случаях сообщения об ошибках не будут выводиться на экран?

- [x] `find / > allfiles.txt 2>&1`
- [ ] `find / 2>&1`
- [ ] `find / > allfiles.txt 1>&2`
- [ ] `find / > allfiles.txt 1> /dev/null`
- [x] `find / > allfiles.txt 2> /dev/null`

---

С помощью каких команд можно активировать режим `noclobber`?

- [x] `set -o noclobber`
- [ ] `set -N`
- [ ] `set +o noclobber`
- [x] `set -C`

---

Параметр noclobber активирован?

```shell
box@de98796:~$ echo $-
himBCH
```

- [x] Да
- [ ] С помощью команды "echo $-" невозможно узнать состояние параметра noclobber.
- [ ] Нет

<span class="d-block text-right">
  [Часть 3.6]({{ site.baseurl }}{% link docs/stepik/course/762/section-3.6.md %}){: .float-left }
  [Часть 4.2]({{ site.baseurl }}{% link docs/stepik/course/762/section-4.2.md %})
</span>
