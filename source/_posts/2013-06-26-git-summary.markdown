---
layout: post
title: "git总结"
date: 2013-06-26 23:00
comments: true
categories: git
---
##git初始化设置
设置全局用户名和邮箱，存储在`~/.gitconfig`文件中。

```bash
git config --global user.name "My Name"
git config --global user.email "my@email.com"
```

或者对单独的`Repo`进行设置，存储在`.git/config`文件中

```bash
cd dir
git config user.name "My Name"
git config user.email "my@email.com"
```

配置终端颜色显示

```bash
git config −−global color.diff auto
git config −−global color.status auto
git config −−global color.branch auto
```

##创建本地git仓库并push到github

```bash
mkdir project
cd project
git init
git add .
#会自动创建master分支，进行完commit操作后才能新建别的分支
git commit −am 'comment message '  #-a会自动添加被修改的文件
#git@github使用的是ssh连接，还可以使用https://github.com/username/project.git
git remote add origin git@github.com:username/yourrepo.git
#把本地分支push到远程服务器，--tags选项会把本地的tags标签也上传
git push origin remote_branch --tags
#更一般的情况，把local_branch本地分支上传到remote_branch分支
git push origin [local_branch]:remote_branch
```
当使用`SSH`的连接方式时，参考[这篇文章](https://help.github.com/articles/generating-ssh-keys)在`github`网站上添加`SSH key`，这样在进行数据传输时就不需要再输入用户名和密码了。

##从远程分支获取内容

```bash
git clone -b branch remote_url
```

##关于分支的一些操作
```bash
#查看当前已有分支及默认的分支
git branch
#创建一个本地分支
git branch local_branch
#切换默认分支
git checkout branch
#删除一个远程的分支，相当于把本地一个不存在的分支push到远程分支中
git push origin :remote_branch
```

##标签
可以对一些版本加标签

```bash
#commit is the checksum value to add tag to previous version
git tag −a tagname −m 'message ' <commit >
```

##文件过滤
在相应的目录中新建`.gitignore`文件，`~/.gitignore`文件作用于全局

```bash
#this is comments. To see detail, execute 'git help ignore '
hello.c
*.o
!foo.o
#to include foo.o which is excluded by *.o.
\!important!.o
#to exclude file whose name begin with !.
```

##其他常用命令

```bash
#查看详细的帮助文档
git help command
#删除文件
git rm
git status
git log
#将服务器端更改同步到本地
git pull
```

##参考资料
- [git学习笔记](http://wlog.cn/soft/git-quick-start.html)
