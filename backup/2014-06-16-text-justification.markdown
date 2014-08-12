--
layout: post
title: "Text Justification"
date: 2014-06-16 10:57
comments: true
categories: Leetcode
---

[Text Justification](https://oj.leetcode.com/problems/text-justification/)

{:toc}

<!--more-->

##思路
- 扫描到一行最多能存放的单词的数目：单词长度之和(len) + 单词内间隔数目(n) <= L
- 从后往前依次计算每个间隔内应填充的空格数目：
    - 首先计算出应该填充的总空格数：spaceSize = L - len
    - 第n个间隔内应填充空格数：curSpace += spaceSize / n;
    - 更新剩余空格数：spaceSize %= n;
- 对最后一行和仅有一个单词的情况做特殊处理：把空格填充在尾部。    

##代码

{% codeblock TextJustification lang:cpp %}
{% render_partial lc2/TextJustification.cpp %}
{% endcodeblock %}
