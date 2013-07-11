---
layout: post
title: "VirtualBox配置总结"
date: 2013-07-11 20:12
comments: true
categories: VirtualBox
---
本文记录使用VirtualBox时的一些配置和使用技巧。

<!--more-->

##利用`nat`方式连接外网
一般把虚拟机的网卡设置为`nat`连接方式时，会自动分配相应的ip地址和网关地址；如果没有正确地分配到ip地址，则设置成如下的网络配置即可：

```
...
IPADDR=10.0.3.15
NETMASK=255.255.255.0
GATEWAY=10.0.3.2
...

#dns服务器
nameserver=10.0.3.2
```

##连接外网的同时和主机进行通信
给虚拟机新添加一个网卡，一个使用`nat`方式，一个使用`Bridged Adapter`方式，把后一个网卡的ip地址配置和主机在同一个网段，然后配置和主机相同的网关地址即可。
