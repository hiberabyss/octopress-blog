---
layout: post
title: "Octopress中Markdown文件语法总结"
date: 2013-06-25 15:20
comments: true
categories: Markdown Octopress
---
本文主要对`Octopress`中`Markdown`文件的语法做一些总结。
<!--more-->

<h2 id="first">Markdown语法</h2>
Markdown的完整语法可以参考图灵社区的[中文文档](http://www.ituring.com.cn/article/504)；查看该文档[源代码](https://github.com/othree/markdown-syntax-zhtw/edit/master/syntax.md)。

##首页只显示部分博客内容
`<!--more-->`会使得在博客首页只显示这个标记之前的内容。提示继续阅读的文字信息则可以在`_config.yml`文件中`excerpt_link: `字段进行修改。

##可以用如下方式添加同一文档内的链接
链接到[Markdown语法](#first)部分

##关于分类
文件中的多个分类直接用空格进行间隔即可，我用的插件会自动把分类名称的首字母大写。

##插入代码
可以利用下面的代码插入相对应于`source`目录的代码文件。

{% raw %}
```
{% codeblock bash.sh lang:bash %} 
	 {% render_partial sample-language/shell/bash.sh %}
{% endcodeblock %}
```
{% endraw %}

[参考](http://stackoverflow.com/questions/15786144/how-to-escape-in-markdown-on-octopress)

