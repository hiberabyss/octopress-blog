---
layout: post
title: "bash编程的一些总结"
date: 2013-06-28 11:51
comments: true
categories: 
    - bash
    - Linux
---
对shell编程的一些总结，直接使用代码进行示例。

<!--more-->

##数字序列
- `echo {01..10}`
- `$(seq -w 02 08)` # `$()` like \`\` , will substitute '\n' to <space>

##自动补全
编辑如下的文件：

- [自定义Bash自动完成](http://marlonyao.iteye.com/blog/695225)

{% codeblock ~/etc/bash_completion lang:bash %}
    {% render_partial sample-language/shell/bash_completion raw %}
{% endcodeblock %}

并用`. bash_completion`导入即可，则在输入`octo-rake` 后按`Tab`键即可自动补全。

##相关文档
* 一篇会很有用的文章[Bash的陷阱](http://tech.idv2.com/2008/01/09/bash-pitfalls/)，抽时间好好看一下。bash的帮助文档很详细，所有的东西都可以从里面找到，要了解该帮助文档的组织结构。
* [简洁的Bash编程技巧续篇](http://kodango.com/simple-bash-programming-skills-2)
* [我从其他Shell脚本中学到了什么](http://www.csdn.net/article/2013-08-15/2816581-What-I-learned-from-other-s-shell-scripts)

{% codeblock bash.sh lang:bash %}
	{% render_partial sample-language/shell/bash.sh %}
{% endcodeblock %}
