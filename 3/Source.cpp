#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<tchar.h>
#include <locale.h>

void SortStr(TCHAR *ptrStr[], int num)
{
	TCHAR *p = NULL;
	if (NULL == ptrStr)
	{
		_tprintf(_T("ptrStr NULL."));
		return;
	}
	if (num <2 || num > MAX_PATH)
	{
		_tprintf(_T("num error."));
		return;
	}
	
	for (int i = 0; i < num; i++)
	{		
		for (int j = i + 1; j < num; j++)
		{
			if (lstrcmp(ptrStr[i], ptrStr[j]) < 0)
			{
				p = ptrStr[i];
				ptrStr[i] = ptrStr[j];
				ptrStr[j] = p;
			}
		}
	}
	return;

}

void main()
{
	setlocale(LC_CTYPE, "");   //设置字符编码未当前系统编码格式
	int num = 0;
	TCHAR *ptrStr[MAX_PATH];   //TCHAR* 的指针数组，每一个指针都指向一个入力字符串。	
	_tprintf(_T("Please enter the number of strings:"));
	scanf_s("%d", &num);      //scanf:以空格或回车符号分割入力，只返回空格或回车符号之前的类容，其余类容被保留再stdin缓冲区，下次读取stdin时可直接读到。
	getchar();                //丢弃上次入力中的回车符号。

	for (int i = 0; i < num; i++)
	{		
		//申请用来保存入力字符串的空间
		ptrStr[i] =(TCHAR *)malloc(sizeof(TCHAR) * MAX_PATH);
		if (NULL == ptrStr[i])
		{			
			goto FreeMemory;
		}		
		_getts_s(ptrStr[i], MAX_PATH - 1);    //scanf接收不到带空格的字符串。
		
	}
	SortStr(ptrStr, num);

	_tprintf(_T("The sorted result：\n"));
	for (int i = 0; i < num; i++)
	{
		_tprintf(_T("%s\n"),ptrStr[i]);
	}

FreeMemory:
	for (int i = 0; i < num; i++)
	{
		if (NULL != ptrStr[i])
		{
			free(ptrStr[i]);
		}
	}
	return;

}