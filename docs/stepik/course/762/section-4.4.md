---
layout: default
---

<span>[Часть 4.4](){: .label }</span>

Существуют три различных версии синтаксиса регулярных выражений. Сопоставьте 
сокращения с расшифровками.

|      |                                                            | 
|:-----|:-----------------------------------------------------------|
| BRE  | базовый синтаксис регулярных выражений                     |
| ERE  | расширенный синтаксис регулярных выражений                 |
| PCRE | синтаксис регулярных выражений языка программирования Perl |

---

Содержимое файла *tennis.txt*:

```shell
box@de98796:~$ cat tennis.txt
Amelie Mauresmo, Fra
Kim Clijsters, BEL
Justine Henin, Bel
Serena Williams, usa
Venus Williams, USA
```

В результате выполнения каких команд будут выведены строки:

```text
Amelie Mauresmo, Fra
Serena Williams, usa
Venus Williams, USA
```

- [ ] `grep W|M tennis.txt`
- [x] `grep -G "M\|W" tennis.txt`
- [ ] `grep -iE "W|M" tennis.txt`
- [ ] `grep W M tennis.txt`
- [x] `grep -E "W|M" tennis.txt`

---

Содержимое файла *tennis.txt*:

```shell
box@de98796:~$ cat tennis.txt
Amelie Mauresmo, Fra
Kim Clijsters, BEL
Justine Henin, Bel
Serena Williams, usa
Venus Williams, USA
```

Нужно найти всех спортсменок из Бельгии.

Ответ: `grep -i Bel tennis.txt`

---

Содержимое *bar.txt*:

```shell
box@de98796:~$ cat bar.txt
br
bar
baar
baaar
```

Подставьте регулярные выражения, соответствующие результатам выполнения команд:

```shell
box@de98796:~$ grep -E "a*" bar.txt
br
bar
baar
baaar

box@de98796:~$ grep -E "a+" bar.txt
bar
baar
baaar

box@de98796:~$ grep -E 'aaa?' bar.txt
baar
baaar
```

---

Содержимое файла *tennis.txt*:

```shell
box@de98796:~$ cat tennis.txt
Amelie Mauresmo, Fra
Kim Clijsters, BEL
Justine Henin, Bel
Serena Williams, usa
Venus Williams, USA
```

В результате выполнения каких команд будут выведены строки:

```shell
Amelie Mauresmo, Fra
Serena Williams, usa
Venus Williams, USA
```

- [ ] `grep -E 'a^' tennis.txt`
- [ ] `grep -E 'a$' tennis.txt`
- [x] `grep -i a$ tennis.txt`
- [x] `grep -iE 'a$' tennis.txt`
- [ ] `grep -iE 'a^' tennis.txt`

---

Напишите результат выполнения команды:

```shell
box@de98796:~$ echo Заморский | sed 's/За/При/'
```

Ответ: *Приморский*

---

Вставьте пропущенные строки:

```shell
box@de98796:~$ echo Заморский | sed 's/ский/ить/'
Заморить
```

----

Напишите результат выполнения команды:

```shell
box@de98796:~$ echo послезавтра | sed 's/после/&&/'
```

Ответ: *послепослезавтра*

---

Напишите результат выполнения команды:

```shell
box@de98796:~$ echo 01.05.1889 | sed 's|\(..\).\(..\).\(....\)|\2/\1/\3|'
```

Ответ: `05/01/1889`

---

В директории `/home/box/testdir` дан набор тестовых файлов. 

1. С помощью команды rename измените расширение у тестовых файлов с **.text** на **.txt**.

```shell
$ cd ./testdir ; rename 's/text/txt/' *.text
```

<span class="d-block text-right">
  [Часть 4.3]({{ site.baseurl }}{% link docs/stepik/course/762/section-4.3.md %}){: .float-left }
  [Часть 5.1]({{ site.baseurl }}{% link docs/stepik/course/762/section-5.1.md %})
</span>
