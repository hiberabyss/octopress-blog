---
layout: post
title: "Debug的技巧"
date: 2013-07-18 21:41
comments: true
categories: Debug
---
介绍进行debug的一些技巧。

<!--more-->

##利用宏和printf进行调试

```c
#define __DEBUG__  
#ifdef __DEBUG__  
#define myprintf(format,...) printf("File:"__FILE__", Line:%d: "format"\n", __LINE__, ##__VA_ARGS__)  
#else  
#define myprintf(format,...)  
#endif
```

其中`##`用于宏的字符串连接，如果`__VA_ARGS__`为空，则`,`会被删除。

##利用assert进行调试
`assert(expression)`用于对表达式进行断言，使用前需要`#include <assert.h>`，如下的代码：

```c
int a=78;
assert(a == 77);
```

会产生这样的错误：

```
test: test.cpp:14: int main(): Assertion `a == 77' failed.
```

并自动退出；如果定义`#define NDEBUG`，则会禁用`assert`。

##参考资料

- [巧用可变参数宏、编译器内置宏和printf输出调试信息](http://blog.csdn.net/hinyunsin/article/details/6546670)
