---
layout: post
title: "Lustre-2.3的安装与配置"
date: 2013-06-24 12:37
comments: true
categories: FileSystem
---
Lustre是一个分布式文件系统，由MDS（元数据服务器）、OSS（对象存储服务器）和Client（客户端）三部分组成。其中MDS和OSS都可以有多个节点，通过MGS进行管理，MGS只能有一个。

##主要内容
* 安装环境  
* Lustre的安装
* Lustre的配置
* 用于Lustre管理的实用工具
* 遇到的问题与解决方案
* 有创意的Idea

##安装环境
- 操作系统：CentOS 6.3 (x86\_64)
- 内核版本：2.6.32-279
- Lustre版本：2.3
- Lustre节点：一个MGS和MDT，使用同一个服务器；多个OSS。

##Lustre的安装
安装之前，对系统环境有如下要求：   

1. 必须已安装*net-snmp*，否则在安装*lustre-version.rpm*时会报错；
2. selinux必须被设置为disabled，如果未关闭则在*mkfs.lustre*操作时会报错；可通过sestatus查看selinux当前状态，如果为enforcing则表示未关闭；可通过命令`setenforce [permissive|0]`临时性关闭;永久关闭则需要修改配置文件*/etc/selinux/config*，做如下修改重启后生效：

```
SELINUX=disabled
```

下载[e2fsprogs](http://downloads.whamcloud.com/public/e2fsprogs/latest/el6/RPMS/x86_64/)并安装：
```
rpm -Uvh --nodeps \
e2fsprogs-devel-1.42.7.wc1-7.el6.x86_64.rpm \
e2fsprogs-libs-1.42.7.wc1-7.el6.x86_64.rpm \
e2fsprogs-1.42.7.wc1-7.el6.x86_64.rpm \
libcom_err-devel-1.42.7.wc1-7.el6.x86_64.rpm \
libcom_err-1.42.7.wc1-7.el6.x86_64.rpm \
libss-devel-1.42.7.wc1-7.el6.x86_64.rpm \
libss-1.42.7.wc1-7.el6.x86_64.rpm
```

下载[kernel](http://downloads.whamcloud.com/public/lustre/lustre-2.3.0/el6/server/RPMS/x86_64/)包并安装（如果要使用InfiniBind连接方式，则必须安装kernel-ib-version包，且需要卸载系统中已经安装的以mlnx开头的kenel包）：
```
rpm -ivh \
kernel-firmware-2.6.32-279.5.1.el6_lustre.gb16fe80.x86_64.rpm \
kernel-devel-2.6.32-279.5.1.el6_lustre.gb16fe80.x86_64.rpm \
kernel-2.6.32-279.5.1.el6_lustre.gb16fe80.x86_64.rpm \
kernel-ib-version
```

下载并安装[Lustre](http://downloads.whamcloud.com/public/lustre/lustre-2.3.0/el6/server/RPMS/x86_64/)：
```
rpm -ivh \
lustre-ldiskfs-3.3.0-2.6.32_279.5.1.el6_lustre.gb16fe80.x86_64.x86_64.rpm \
lustre-modules-2.3.0-2.6.32_279.5.1.el6_lustre.gb16fe80.x86_64.x86_64.rpm \
lustre-2.3.0-2.6.32_279.5.1.el6_lustre.gb16fe80.x86_64.x86_64.rpm
```

##Lustre的配置
配置Lustre所使用的借口名称以及相对应的别名；创建*/etc/modprobe.d/lnet.conf*文件，写入以下内容：
```
options lnet networks="o2ib0(ib0)"
```
载入相关模块：
```
modprobe lustre
modprobe ldiskfs
modprobe lnet
```

这时可以查看*/sys/modules/lnet/prarameters/networks*内容，以确定*lnet.conf*中的配置信息是否已经加载至内核。

在MDS上的创建Lustre文件系统，并挂载：
```
mkfs.lustre --fsname=mylustre --mdt --mgs --index=0 --reformat /dev/sdb1
mount.lustre /dev/sdb1 /mnt/mdt
```
其中*fsname*为安装的lustre文件系统的标志，在MGS、MDS和OSS中都必须保持一致，在客户端挂在Lustre文件系统时也会使用到这个名字，长度不能超过8个字符；本例中MGS和MDS使用同一个服务器；*reformat*会对磁盘进行重新格式化处理。

在OSS上创建Lustre文件系统，并挂载：
```
mkfs.lustre --fsname=mylustre --ost --reformat --index=num --mgsnode=host_mds@o2ib0 /dev/sdb2
mount.lustre /dev/sdb2 /mnt/ost
```
必须要在MDT的文件系统挂在之后才能挂载OST的文件系统；*host_mds*为mds的ip地址或者已经写入*hosts*文件的主机名，*o2ib0*和*lnet.conf*中写入的内容保持一致。
如果出现无法连接的情况，则可能是防火墙的原因，可以关闭*iptables*服务：`service iptables stop`

客户端的挂载：
```
mount.lustre host_mds@o2ib0:/mylustre /mnt/lustre
```

##实用工具
lctl：可以直接在终端运行进入交互的命令方式或者直接输入命令。
```
lctl network up
lctl list_nids	#可以查看当前实际的ip地址，以确定是否使用了正确的接口
lctl ping nids	#用来检查OSS和MGS连接是否正常
lctl dl		#查看当前的设备
```

可以通过*lfs*命令获取已挂载的*lustre*文件系统信息：
```
lfs df -h
```

或者对文件系统的文件写入方式等进行配置：
```
lfs setstripe -c -1 -S 128M /mnt/lustre/
```
其中`-c -1`表示写入到所有的OSS中，`-S 128M`表示文件分块的大小为128M；上面是对整个文件系统进行设置，也可以单独地对某个文件或者文件夹进行设置；设置完后可以通过如下命令查看配置信息是否正确：
```
lfs getstripe /mnt/lustre
```

##遇到的问题及解决方法（P-Problem，C-Cause，R-Resolve）
P：安装完重启之后，系统无法启动。  
C：因为启动分区太小，只有100M大小，而*Lustre*生成的*initramfs*太大，大概有65M，最后导致生成的文件不完整，所以无法启动；在*lustre-module-version*的安装过程中产生，会报文件写入错误。  
R：调整分区大小比较困难，也不方便进行批量处理；就不是用单独的启动分区，把*grub*重新安装到*/dev/sda*上，卸载启动分区，把内核等文件复制到根文件系统的*/boot*目录下，修改*grub.conf*文件，直接通过根文件系统下的*/boot*目录中的内核进行启动。  

P：安装完Lustre并成功启动后，在执行*mount.lustre*操作之后，就会断开了ssh连接。  
C：主机上提示*out of memory*提示，并killing一大堆进程，至今没搞明白为什么会出现内存不足的问题，当时机器的配置是2G内存，我在虚拟机中实验时，设置1G的内存，也没有出现这个错误。  
R：去除内核参数*mem=2048M*之后，内存变为了32G，一切就恢复正常了。  

##比较有创意的Idea
需要对*/dev/sdb*进行分区，就在一台机器上利用`fdisk`按要求分区后，拷贝出该硬盘前512字节启动分区内容：
```
dd if=/dev/sdb of=boot512.img bs=512 count=1
```
之后把这个文件写入其他机器的*/dev/sdb*硬盘，便可完成分区，这样便方便进行批量处理了：
```
dd if=boot512.img of=/dev/sdb bs=512 count=1
```
在用`fdisk`分完区后，在*/dev/sdb#*中并没有及时地反映出分区后的结果，此时运行`partprobe /dev/sdb`命令即可。

##参考文献：
[51CTO：Lustre-2.3的安装](http://xiaolangit.blog.51cto.com/3343422/1195060)
