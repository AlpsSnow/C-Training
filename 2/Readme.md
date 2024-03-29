﻿# 练习2

## 题目
```
2、程序实现目标：把一段字符串中的第一个空格和最后一个空格去掉。

实例：源字串：" asd bsdf   df "，目的字串："asd bsdf   df"
```
## 解题思路
1. 如何从标准入力接收带有空格的字符串？ 
  - scanf:遇到空格就会结束，默认使用空格作为入力的分隔符。以空格或回车符号分割入力，只返回空格或回车符号之前的类容，其余类容被保留再stdin缓冲区，下次读取stdin时可直接读到。
  - gets:接收字符串直到遇到回车，并且接收回车字符，然后将回车字符转成字符串结束符`'\0'`保存。
2. 去字符串前后空格，可以使用指针，从前往后，如果是空格指针向后移动一个字符，直到找到第一个非空格字符。从后往前查找空格，如果是空格，就将该空格置换为字符串结束符`'\0'`。
3. 考虑到unicode和multibyte字符串编码的存在，为了在不改变代码的情况下，只需要通过变更工程设置，就能够简单编译出unicode和multibyte字符两个版本的程序，引入了windows.h和tchar.h头文件。另外所有的字符处理函数都使用了（xxxA和xxxW）的通用函数。
4. 考虑到各种系统字符集的不相同，为了使字符串正确在各个不同字符集的机器上正确输出不乱码，引入了locale.h,使用`setlocale(LC_CTYPE, "");`获取当前系统编码。

### 思考
1. scanf和gets不同点：  
scanf不能接受空格、制表符Tab、回车等；而gets能够接受空格、制表符Tab和回车等；  
scanf ：当遇到回车，空格和tab键会自动在字符串后面添加’\0’，但是回车，空格和tab键仍会留在输入的缓冲区中。  
gets：可接受回车键之前输入的所有字符，并用’\0’替代 ‘\n’.回车键不会留在输入缓冲区中。  
2. printf和puts的不同点：  
puts在输出字符串时会将puts在输出字符串时会将’\0’自动转换成’\n’进行输出，也就是说，puts方法输出完字符串后会自动换行。  
puts's Remarks：The puts function writes string to the standard output stream stdout, replacing the string's terminating null character ('\0') with a newline character ('\n') in the output stream.
