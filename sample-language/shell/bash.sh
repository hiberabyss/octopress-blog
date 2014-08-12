#!/bin/bash

#默认会执行“~/.profile”、“~/.bashrc”脚本文件

#man bash可以查看到详细的帮助文档
#一些命令参数：
#-n: 测试语法是否正确，不执行
#-x: 显示所执行的每一条命令
#-c "string": 从string中读取命令
#-l: 以登录shell运行，区别是读取的配置文件不同，具体可参见man bash

#取消相应参数
set +x
#设置相应选项
set -x

#特殊的参数，man bash中“Special Parameters”中有详细介绍：
# $#:表示输入参数的个数，在Linux中常用#表示数字
# $*:所有参数的字符串，分隔符和“IFS”有关，和$@的区别还没有搞清楚
# $@:和上面功能类似
# $?:上一条命令的返回状态

usage() {
  printf "%b" "
    
Usage
  example [options] [action]
Options

Examples

Actions
"
}

#参数处理
#关于for语句等流程控制语句的详细用法参考man bash的“Compound Commands”部分

while (( $# > 0 )); do
  token="$1"
  shift
  case "$token" in
    --help|-h)
      echo "haha,help"
      ;;
    --nodebug|-n)
      set +x
      ;;
    *)
      usage
      exit 1
      ;;
  esac
done

sum=0
#((expression))用于算术运算和比较，等同于let "expression"
#如果expression非0，则返回0,否则返回1
#关于运算符详细信息参见：ARITHMETIC EVALUATION
for (( i=1;i<=10;i++ )); do
  sum=$((sum + i))
done

echo $sum

#[[ ]]和[ ]功能类似，但功能更强大，支持字符串的比较 
SPECIAL_DAY="2012-07-07"
ADD2YEARS=`date -d "$SPECIAL_DAY 2 years" +%F`
TODAY=`date +%F`
if [[ $TODAY < $SPECIAL_DAY ]]; then
  echo "today is before special day"
#'string'会显示所有的字符串，不区分特殊字符，除了'
elif [[ $TODAY < $ADD2YEARS ]]; then
  echo '$ADD2YEARS is ' $ADD2YEARS
else
  echo "the last one"
fi

# 2> /dev/zero 对stderr进行重定向
# > /dev/zero 对输出进行重定向
#详情参见：REDIRECTION
if ls /mytest 2> /dev/zero ; then
  echo 'excute correct'
elif ls /home > /dev/zero ; then
  echo '/home exists'
fi

#详细条件判断参考：CONDITIONAL EXPRESSIONS
if [[ -d "/home/" ]]; then
  echo "home dirctory exits"
  if [[ ! -f "/home/haha" ]]; then
    echo "haha: file not exits"
  fi
fi

#关于数组，从0开始；普通的变量相当于是只有一个元素的数组，
#数组元素的引用方式为 ${array[2]}；大括号是必须的；$array则相当于是${array[0]}
#详情参见 Arrays
name=
for ((i=1;i<5;i++)); do
  name[i]="a$i"
done

#输出数组中的所有元素
echo ${name[*]}
echo ${name[@]}
#输出某一项的长度
echo ${#name[2]}
#输出数组元素的个数，相当于第一个元素为空
echo ${#name[*]}

#关于字符串处理，替换，拓展等
#详细信息参见 EXPANSION Parameter Expansion

echo abc{x,y,z}d	#abcxd,abcyd,abczd

#最后一个数字为step，默认为1或-1，加前导0会保证数字的宽度
#参见 Brace Expansion
echo {01..10..1}	#01 02 03 ...

#Parameter Expansion
mytest=aabbbbccccddaa
myabc=lalala

#如果未定义则用后面的代替
echo ${mynull:-test}	#test
#代替的同时也赋值给前面的变量
echo ${mynull:=test}	#test 同时 $mynull也为test
#如果定义则用后面的单词代替
echo ${myabc:+hahaha}	#hahaha

#输出子字符串
echo ${mytest:0:5}	#从第0个字符开始输出5个字符，如果最后的长度省略，则输出到字符串末尾
#用负数计数时 - 号必须和：有间隔
echo ${mytest: -1}
#字符串长度
echo ${#mytest}
#下面的字符串删除中 # 表示从行首开始删除匹配项，%表示行尾，## %% 表示最大匹配
echo ${mytest#a}
echo ${mytest##aa}
#表示字符串替换 ${para/pattern/string} 把符合模式的字符串替换为string
#其中 pattern 以 / 开头表示完全匹配，#开头表示匹配行首，%表示匹配行尾
#string为空，则把相应的匹配项删除

#${para^pattern}
#大小写转换 ^ 表示大写， ',' 表示小写， ^^ ,, 表示最大匹配
#如果pattern为空，则默认为 ?
