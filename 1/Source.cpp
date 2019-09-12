#include<stdio.h>
#include<Windows.h>
#include <locale.h>

void GetCount(int Num, float pOutput[])
{
	float sum = 0;
	float factorial = 1;
	int i = 0;

	//入参检查
	if (NULL == pOutput)
	{
		printf("pOutput is NULL!");
		return;
	}

	if (Num < 1 || Num > 20)
	{
		printf("输入的不是1~20之间的整数！");
		pOutput[0] = 0;
		return;
	}

	for (i = 1; i <= Num; i++)
	{
		factorial *= i;
		sum += factorial;
	}

	pOutput[0] = sum;

}
void main()
{
	setlocale(LC_CTYPE, "");   //设置字符编码未当前系统编码格式
	float pNumber[2] = { 0 };
	int Number = 0;
	printf("请输入一个1~20之间的整数：");
	scanf_s("%d", &Number);
	GetCount(Number, pNumber);
	printf("%d以内数据的阶乘之和:%f", Number, pNumber[0]);
	return;
}