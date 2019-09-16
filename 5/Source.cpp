#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<locale.h>

int Getnum(int input, int output)
{
	bool isNegative = false;
	int count = 1;
	int unit = 1;
	
	if (input < 0) {
		isNegative = true;
		input = 0 - input;
	}

	while (input/10 != 0)
	{			
		if (count % 2 != 0)
		{
			output += input % 10 * unit; //奇数位的数*该值的单位，再加上之前数的和。
			unit *= 10; //下一个奇数位的单位：十，百，千
		}
		input = input / 10;
		count++;

	}

	//入力数最高位的处理。（包括入力数字只有一位的情况）
	if (input / 10 == 0)
	{
		if (count % 2 != 0)
		{
			output += input % 10 * unit;
		}
	}

	if (isNegative)
	{
		output = 0 - output;
	}
	return output;


}
void main()
{
	int input = 0;
	int output = 0;
	setlocale(LC_CTYPE, "");   //设置字符编码未当前系统编码格式
	_tprintf_s(_T("Please enter a number："));
	_tscanf_s(_T("%d"), &input);
	output = Getnum(input, output);
	_tprintf_s(_T("%d"), output);
}