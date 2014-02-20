---
layout: post
title: "Lustre原理及优化"
date: 2013-07-16 16:30
comments: true
categories: Lustre FileSystem
---
介绍Lustre的内部细节及一些优化措施。

<!--more-->

##Lustre Stripe
Lustre采用对象存储技术，将大文件分片存储在多个OST上。分片的参数包括`stripe_count`和`stripe_size`，即所要使用的OST的数量以及分片的大小，默认分别为`1`和`1MB`。可以通过`lfs setstripe`命令进行设定，子目录继承父目录的分片模式。Lustre在创建文件时就按照分片模式和OST选择算法，预先创建好文件所需的OST对象。数据写入后，文件的分片不能修改，现在还未实现OST存储空间的自动均衡。

OST选择算法：

1. Round-Robin：任意两个OST剩余存储容量之差小于`20%`时采用该算法；以顺序轮转方式选择OST，算法非常高效。
2. 随机加权算法：存在两个OST剩余空间之差大于`20%`时采用该算法；Lustre维护着一张剩余空间的优先列表，采用随机算法在此列表中选择OST，会产生开销并影响性能；当任意两个OST剩余容量之差小于`20%`时，继续选用`Round-Robin`算法。

##Lustre性能优化

1. 禁用所有客户端的`LNET debug`功能：`sysctl -w lnet.debug=0`。
2. 增加客户端Dirty Cache大小：`lctl set_param osc./*.max_dirty_mb=256`，缺省为32MB，增大缓存将提升I/O性能，但数据丢失的风险也随之增大。
3. 增加RPC并行数量：echo 32 > /proc/fs/lustre/osc/*-OST000*/max_rpcs_in_flight，缺省为8，提升至32将提高数据和元数据性能。不利之处是如果服务器压力很大，可能反而会影响性能。

##参考资料
- [Lustre I/O性能特点与最佳实践](http://blog.csdn.net/liuben/article/details/6455736)
