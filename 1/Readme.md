# 练习1

##题目
```
1、程序实现目标：输入1~20的数字n，求n以内数据的阶乘之和。
1! + 2! + 3! +......+n! = ?

void GetCount(int Num ,float pOutput[])
{

}
void main()
{
    float pNumber[2] = {0};
    Number = 20;
    GetCount(Number ,pNumber);
}
```
##解题思路
1. 阶乘是什么？
   - n!=1×2×3×...×n
2. 20以内的数的阶乘之和，可以用什么类型的变量存储？
   - [Data Type Ranges](https://docs.microsoft.com/en-us/cpp/cpp/data-type-ranges?view=vs-2019),由此看来，int肯定是放不下了，可以用float存放。