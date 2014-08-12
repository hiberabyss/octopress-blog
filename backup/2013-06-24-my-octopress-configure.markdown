---
layout: post
title: "个性化Octopress资源整理"
date: 2013-06-24 17:07
comments: true
categories: Octopress
---
所做个性化修改的资料整理总结。

<!--more-->

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

##添加多说
主要参考[这篇文章](http://ihavanna.org/Internet/2013-02/add-duoshuo-commemt-system-into-octopress.html)。需要先在多看官网上[创建站点](http://duoshuo.com/create-site/)（官网的上写的是我要安装，最开始被我给直接忽略了），在后台控制面板的工具选项的代码中可以获取`short_name`，可能是和输入的域名是一致的，不太确定。

##国内的社会化工具
- [bshare](http://www.bshare.cn/)：分享按钮，本站使用的工具。  
- [多说](http://duoshuo.com/)：评论系统，本站使用的评论工具。
- [加网](http://www.jiathis.com/)：包括分享（加网）、评论（[友言](http://www.uyan.cc/)）和推荐（[友荐](http://www.ujian.cc/)）三个部分。有时间可以尝试下友荐，看着很不错。


##使用kramdown包
安装kramdown包：

```ruby
gem install kramdown
```

修改配置文件`_config.yml`，把`rdiscount`改为`kramdown`：

```yaml
markdown: kramdown
```

kramdown的详细语法资料[kramdown Syntax](http://kramdown.rubyforge.org/syntax.html#tables)。

##使用Latex
修改支持Latex的方法参见[这篇文章](http://yanping.me/cn/blog/2012/03/10/octopress-with-latex/)。

##关于中文分类标签
把`category_generator.rb`文件中的如下两行代码

{% codeblock category_generator.rb %}
self.write_category_index(File.join(dir, category.to_url), category)
  ...
"<a class='category' href='/#{dir}/#{category.to_url}/'>#{category}</a>"
{% endcodeblock %}

换为如下的代码（把`to_url`换为`downcase`，也即分类不区分大小写；`to_url`会把中文换为汉语拼音）

{% codeblock category_generator.rb %}
self.write_category_index(File.join(dir, category.downcase), category)
  ...
"<a class='category' href='/#{dir}/#{category.downcase}/'>#{category}</a>"
{% endcodeblock %}



##总结
有不少内容参考了[这篇文章](http://www.yanjiuyanjiu.com/blog/20130402/)。把无法连接的Twitter、FaceBook之类的插件注释掉，否则会影响页面的加载速度。 

##相关博客
- [雁起平沙的网络日志](http://yanping.me/cn/)  
- [知行录（github上有源码）](http://whbzju.github.io/)
- [MrZhang.me（做的比较玄的一个博客，有源代码）](http://mrzhang.me/)
- [Jeklly模板](http://webfrogs.me/)

##参考资料
* [为Octopress博客追加新浪微博侧栏](http://programus.github.io/blog/2012/03/03/add-weibo-sidebar-into-octopress/)  
* [幫你的Octopress增加文章分類](http://blog.eddie.com.tw/2011/12/05/add-catetories-to-sidebar-in-octopress/)
* [为 Octopress 添加多说评论系统](http://ihavanna.org/Internet/2013-02/add-duoshuo-commemt-system-into-octopress.html)
