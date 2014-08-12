---
layout: post
title: "安装grub2到U盘以及相关配置"
date: 2014-02-26 17:16
comments: true
categories: 
---
通过安装grub2到U盘，可以利用U盘来安装、启动操作系统，进行系统的维护。

##主要内容
* 对U盘进行分区
* 安装grub2到U盘
* 在Virtualbox中从U盘启动
* 轻量型Linux系统Slitaz 
* 示例grub.cfg文件

<!--more-->

##对U盘分区
用gparted把U盘分成两个区(fat32, ext4)，fat32存放数据，ext4存放grub和启动信息。ext4分区要在fat32分区之后，否则windows无法识别。把分区卸载之后可以用gparted更改分区label。

##安装grub2到U盘
执行如下命令(ubuntu 13.10)，需要先指定grub文件的存放位置，即U盘ext4分区的挂载位置，最后指定U盘对应的设备文件（如`/dev/sdb`）：

```
sudo grub-install --boot-directory /upan/partition/mountpoint /dev/sdX
```

执行后如果提示没有足够空间存放`core.img`文件，则用`gparted`在mbr后预留出1～2MB的空间。或者在上述命令后加上`--force`选项。

```
sudo grub-install --boot-directory /upan/partition/mountpoint /dev/sdX --force
```

##在Virtualbox中从U盘启动
通过设置在Virtualbox中从U盘启动，可以很方便的进行测试。   

先用如下命令生成一个和U盘相对应的vmdk文件（要确保U盘已经挂载，否则会报错）：

```
sudo VBoxManage internalcommands createrawvmdk -rawdisk /dev/sdX -filename filename.vmdk
```

用root权限启动Virtualbox，创建虚拟机，把上面生成的vmdk文件作为硬盘设备即可。注意要保证生成文件时和虚拟机启动时U盘所对应的设备文件是一致的，例如都是`/dev/sdb`

##Slitaz
Slitaz是一个轻量型的Linux系统，官网下载的`slitaz-4.0.iso`只有35MB大小，但没有中文支持。在[无忧论坛](http://bbs.wuyou.com/forum.php?mod=viewthread&tid=190810)上下载了一个中文定制版，基本能够满足需求。   

利用grub2启动的配置：

```
menuentry 'SliTaz' {
    set ISOFILE="/iso/slitaz.iso"
    search --set=root -f $ISOFILE --hint (hd0,2)
    loopback loop $ISOFILE
    #linux (loop)/boot/bzImage lang=en kmap=us rw root=/dev/null autologin
    linux (loop)/boot/bzImage rw root=/dev/null autologin
    initrd (loop)/boot/rootfs.gz
}
```

##使用的grub2配置文件

{% codeblock grub.cfg %} 
    {% render_partial sample-language/grub.cfg raw %}
{% endcodeblock %}

