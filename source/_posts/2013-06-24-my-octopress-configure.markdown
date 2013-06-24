---
layout: post
title: "个性化Octopress资源整理"
date: 2013-06-24 17:07
comments: true
categories: Octopress
---
所做的一些个性化更改的资料整理。

##修改导航栏名称
修改`source/_includes/custom/navigation.html`文件即可：

##修改缩进方式
修改文件`sass/custom/_layout.scss`，设置`$indented-lists: true`。

##添加Disqus
首先需要在[Disqus](http://www.disqus.com/)上注册一个帐号，然后修改`_config.yml`文件：
```
#在Disgus官网控制面板中输入使用的网址后会生成一个shortname
disqus_short_name: hiberabyss	
disqus_show_comment_count: true
```

##总结
把无法连接的Twitter、FaceBook之类的插件注释掉，否则会影响页面的加载速度。

##相关博客
[雁起平沙的网络日志](http://yanping.me/cn/)  
[知行录（github上有源码）](http://whbzju.github.io/)

##参考资料
[为Octopress博客追加新浪微博侧栏](http://programus.github.io/blog/2012/03/03/add-weibo-sidebar-into-octopress/)  
[幫你的Octopress增加文章分類](http://blog.eddie.com.tw/2011/12/05/add-catetories-to-sidebar-in-octopress/)
