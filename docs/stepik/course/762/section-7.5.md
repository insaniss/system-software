---
layout: default
---

<span>[Часть 7.5](){: .label }</span>

С помощью утилиты `groupadd` можно

- [ ] добавить одну группу в другую
- [ ] добавить пользователя в группу
- [x] создать новую группу

---

Членство пользователей в группах описывается в файле

- [ ] `/etc/passwd`
- [ ] `/etc/users`
- [ ] `/etc/shadow`
- [x] `/etc/group`

---

С помощью команды `groups` можно

- [x] посмотреть в каких группах состоит пользователь
- [ ] добавить одну группу в другую
- [ ] создать новую группу
- [ ] добавить пользователя в группу

---

Членство пользователя в группах может быть изменено с помощью утилиты

- [ ] `groupadd`
- [ ] `groupmod`
- [x] `usermod`
- [ ] `groups`

---

Какой параметр утилиты `usermod` позволяет сохранить список групп пользователя,
в которых он состоял, если имена данных групп не были переданы в составе команды?

- [ ] `-G`
- [ ] `-g`
- [ ] список прежних групп пользователя сохраняется при обновлении
- [ ] `-s`
- [x] `-a`

---

С помощью какой утилиты вы можете изменить имя группы?

- [x] `groupmod`
- [ ] `groups`
- [ ] `newgr`

---

1. Создайте группы **tennis**, **football** и **sport**.
2. Найдите пользователей, которые состоят в группе **beer**. Удалите их из этой
   группы и поместите их в группу **sport**.
3. Делегируйте пользователю **baz** права на управление группами **football** и 
   **tennis**.

```shell
$ sudo groupadd tennis                                      
$ sudo groupadd football                                    
$ sudo groupadd sport                                       
$ cat /etc/group | grep beer                                
beer:x:8378:foo,bar                                                             
$ sudo gpasswd -d foo beer                                  
Removing user foo from group beer                                               
$ sudo gpasswd -d bar beer                                  
Removing user bar from group beer                                               
$ sudo usermod -a -G sport foo                              
$ sudo usermod -a -G sport bar                              
$ sudo gpasswd -A baz football                              
$ sudo gpasswd -A baz tennis
```

<span class="d-block text-right">
  [Часть 7.4]({{ site.baseurl }}{% link docs/stepik/course/762/section-7.4.md %}){: .float-left }
  [Часть 8.1]({{ site.baseurl }}{% link docs/stepik/course/762/section-8.1.md %})
</span>
