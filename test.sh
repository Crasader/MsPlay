#!/bin/bash
# echo "fuck the world"
# echo "定义一个变量"
# shit="fuckfjdkfjsf"

# echo $shit
# echo ${shit}
# for var in A B C ; do 
# 	echo "var is a ${var}" 
# done 

# your_name="jingdo"
# greeting="hello $your_name"
# greeting_1="hello, ${your_name} !"
# echo $greeting $greeting_1

# # 获取字符串长度
# echo ${#your_name}


# # 提取子字符串
# # 以下实例从字符串第 2 个字符开始截取 4 个字符：
# string="runoob is a great site"
# echo ${string:1:4} # 输出 unoo

# #数组
# array=(1 2 3 4)
# echo ${array[@]}

# vale1=${array[0]}
# echo $vale1
# for (( i = 0; i < 5; i++ )); do
# 	echo ${array[i]}
# done

# # 取数数组长度
# length=${#array[@]}
# echo $length

# # 测试传递参数
# echo "shell 测试传递参数"
# echo "执行的文件名：$0";
# echo "第一个参数为：$1";
# echo "第二个参数为：$2";
# echo "第三个参数为：$3";

# echo "Shell 传递参数实例！";
# echo "第一个参数为：$1";
# echo "参数个数为：$#";
# echo "传递的参数作为一个字符串显示：$*";

#基本运算
# echo `expr 2 + 2`

# val=`expr 2 + 2`
# echo "2 + 2 = $val"

# a=10
# b=20

# val=`expr $a + $b`
# echo "a + b : $val"

# val=`expr $a - $b`
# echo "a - b : $val"

# val=`expr $a \* $b`
# echo "a * b : $val"

# val=`expr $b / $a`
# echo "b / a : $val"

# val=`expr $b % $a`
# echo "b % a : $val"

# if [[ $a == $b ]]; then
# 	echo "a equal b"
# fi

# if [[ $a != $b ]]; then
# 	echo "a not equal b!"
# fi

# b=$a
# echo $b $a

##显示表量
# read name 
# echo $name is a testt

# # 显示命令执行结果
# echo `date`

# printf "%-10s %-8s %-4s\n" 姓名 性别 体重kg  
# printf "%-10s %-8s %-4.2f\n" 郭靖 男 66.1234 
# printf "%-10s %-8s %-4.2f\n" 杨过 男 48.6543 
# printf "%-10s %-8s %-4.2f\n" 郭芙 女 47.9876 

# #shell test
# num1=100
# num2=200
# if test $[num1] -eq $[num2] 
# then
# 	echo "equal"
# else
# 	echo "not equal"
# fi

# num1="fuck"
# num2="fuck"
# if test $num1 = $num2
# then
# 	echo "str equal"
# else
# 	echo "str not equal"
# fi

# if test -e ./test.sh 
# then
# 	echo "file exist"
# else
# 	echo "file not exits"
# fi

# #if elseif else
# a=10
# b=20
# if [[ $a == $b ]]; then
# 	echo "a==b"
# elif [[ $a -gt $b ]]; then
# 		echo "a>b"
# elif [[ $a -lt $b ]]; then
# 		echo "a<b"
# else
# 	echo "no suit condition"
# fi

# for str in 'this ia fukc'; do
# 	echo $str
# done

# for i in 'this isa fuck'; do
# 	echo $i
# done

# read -p "fffffffffffffffff" name
# echo "------${name}"

# a=100;
# echo "Value of a is $a \n"
# echo -e "Value of a is $a \n"

# DATE=`date`
# USER=`who | wc -l`
# echo "Date is $DATE"
# echo "Logged in user are $USER"
# UP=`date ; uptime`
# echo "uptime is $UP"

# echo ${var:-"Variable is not set"}
# echo "1 - Value of var is ${var}"

# echo ${var:="Variable is not set"}
# echo "2 - Value of var is ${var}"

# file="/Volumes/jingjing/Workspace/MsPlay/test.sh"
# if [ -r $file ]; then
#    echo "File has read access"
# else
#    echo "File does not have read access"
# fi

# if [ -w $file ]; then
#    echo "File has write permission"
# else
#    echo "File does not have write permission"
# fi

# if [ -x $file ]; then
#    echo "File has execute permission"
# else
#    echo "File does not have execute permission"
# fi
# if [ -f $file ];then
#    echo "File is an ordinary file"
# else
#    echo "This is sepcial file"
# fi

# if [ -d $file ];then
#    echo "File is a directory"
# else
#    echo "This is not a directory"
# fi

# if [ -s $file ];then
#    echo "File size is zero"
# else
#    echo "File size is not zero"
u fi

# if [ -e $file ];then
#    echo "File exists"
# else
#    echo "File does not exist"
# fi


# string="alibaba is a great company"
# echo `expr index $string is`
for FILE in $HOME/.bash*
do
   echo $FILE
done

funWithReturn(){
    echo "The function is to get the sum of two numbers..."
    echo -n "Input first number: "
    read aNum
    echo -n "Input another number: "
    read anotherNum
    echo "The two numbers are $aNum and $anotherNum !"
    return $(($aNum+$anotherNum))
}
funWithReturn
val=$?
echo $val

#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
            abckefg########                          XXXXX test ------------------123jj
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
#html http://c.biancheng.net/cpp/view/2740.html
