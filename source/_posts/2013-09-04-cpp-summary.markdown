---
layout: post
title: "C和C++总结"
date: 2013-09-04 11:03
comments: true
categories: C&C++
---

<!--more-->

##打印当前文件名、行数、函数名

```c
printf("File:%s,Line:%d,Func:%s", __FILE__, __LINE__, __func__);
```

