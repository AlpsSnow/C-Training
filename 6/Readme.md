# 练习6

##题目
```
6、输入一个字符串，将字符串中大写转成小写，过滤掉不是字母的字符
实例：
 输入：  ABCabc124#
 输出：  abcabc
void translate(char *p)
{

}
void main()
{

}
 
```
##解题思路
1. 大写A的ASCII编码值值是65，小写a的ASCII编码值值是97。大写字母转小写，其实就是ASCII编码值增加32。
2. 关于各种编码的理解：参考[你真的了解 Unicode 和 UTF-8 吗？](https://www.linuxidc.com/Linux/2018-11/155553.htm), [字符编码ANSI和ASCII区别、Unicode和UTF-8区别](https://blog.csdn.net/xiangxianghehe/article/details/77574965)