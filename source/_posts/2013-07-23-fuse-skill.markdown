---
layout: post
title: "利用FUSE挂载文件系统"
date: 2013-07-23 09:18
comments: true
categories: FileSystem
---
从《Linux内核精髓》这本书得到的关于`fuse`的一些使用技巧。

<!--more-->

##sshfs
利用`sshfs`可以把 SSH 远程登录的机器的目录挂载到本地机器上。

```bash
sshfs username@remote:foo ~/remote-foo
#卸载
fusermount -u -z ~/remote-foo
```
##普通用户挂在iso文件

```bash
fuseiso foo.iso ~/iso
fusermount -u -z ~/remote-foo
```

