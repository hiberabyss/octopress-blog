---
layout: post
title: "我定制的Octopress文件"
date: 2013-06-25 19:57
comments: true
categories: Octopress
---
这里放置我自己修改的`Rakefile`配置文件和`sass/custom/_styles.scss`，显示的代码会和源文件中代码保持一致，主要利用[Render Partial](http://octopress.org/docs/plugins/render-partial/)插件实现，该插件以`source`目录作为工作目录。利用[Codeblock](http://octopress.org/docs/plugins/codeblock/)插件可以显示标题，在标题中包括文件扩展名可以自动添加语法高亮。

##样式文件
`/sass/custom/`下的文件会最后加载，因此会覆盖之前所做的设置。

{% codeblock ../sass/custom/_styles.scss %}
	{% render_partial ../sass/custom/_styles.scss %}
{% endcodeblock %}

##Ruby程序文件
主要做了如下修改：

1. 增加`editor = vim`，在每次`new_post`和`new_page`操作时，自动打开相应的文件；
2. 新增`task :lgdeploy`，仅布局到本地，暂不上传到`github`。

Rakefile的语法可以参见[这篇文章](http://lukaszwrobel.pl/blog/rake-tutorial)

{% codeblock ../Rakefile lang:ruby %}
	{% render_partial ../Rakefile raw%}
{% endcodeblock %}
