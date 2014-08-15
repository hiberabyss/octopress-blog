---
layout: post
title: "未分类面试题"
date: 2014-08-15 13:03
comments: true
categories: Job
---

收录语言、数学等一些杂题。

<!--more-->

###为什么`strcpy`返回值是`char *`类型？
`strcpy`的原型为`char *strcpy(char *dest, const char *src);`；返回值为`dest`。返回`char *`可以支持链式表达式：`strcpy(a, strcpy(b,c))`，方便编程。比较类似于`a=b=c;`。

###证明素数是无限多个的。
使用反证法进行证明：假设素数是有限的，分别为{$ P_1,\dots,P_n $}。构造一个新的整数：

$$ x = P_1 * P_2 * \dots * P_n + 1 $$

$x$不能被任一个素数{ $ P_1 , \dots , P_n  $ }整除，则它也是一个素数，与假设相矛盾。
