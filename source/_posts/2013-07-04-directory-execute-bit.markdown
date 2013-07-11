---
layout: post
title: "Linux目录的可执行权限"
date: 2013-07-04 10:37
comments: true
categories: Linux
---
Linux目录必须要有可执行权限，此时`x`字段并不是真的代表可执行，而只是被重利用，用来表示在路径搜索中是否允许进行搜索，因此目录的`x`字段又被称为`search permision`字段。

<!--more-->

例如，当搜索目录`/path/to/file`时，如果目录`to`没有可执行权限，则在搜索`to`目录之前会首选判断`x`字段是否置位，如果没有，则提示没有权限。但如果有`to`目录的读取权限，还是可以显示`to`目录的内容的。

在用`cd dir`切换目录时，需要`dir`目录具有可执行权限，否则会提示权限错误。

[参考资料](http://www.cnblogs.com/frydsh/archive/2013/01/15/2862066.html)
