#include<stdio.h>
#include<tchar.h>
#include<Windows.h>
#include <locale.h>

void TrimStr(TCHAR *strInput, TCHAR *strOutput)
{
	int i = 0;
	int len = 0;
	TCHAR *p = NULL;
	if (NULL == strInput || NULL == strOutput)
	{
		_tprintf(_T("parament error."));
		return;
	}
	p = strInput;
	len = lstrlen(p);
	for (i = 0; i < len; i++)
	{
		if (_T(' ') == *p)
		{	
			p += 1;
			continue;
		}
		else 
		{
			break;
		}
	}

	len = lstrlen(p);
	for (i = len - 1; i >= 0;i--) 
	{
		if (_T(' ') == *(p + i))
		{
			*(p + i) = _T('\0');
			continue;
		}
		else
		{
			break;
		}
	}
	memset(strOutput, 0, MAX_PATH);
	lstrcat(strOutput, p);
	return;
}

void main()
{
	setlocale(LC_CTYPE, "");   //设置字符编码未当前系统编码格式
	TCHAR strInput[MAX_PATH] = { 0 };
	TCHAR strOutput[MAX_PATH] = { 0 };
	_tprintf(_T("input a string:"));
	_getts_s(strInput, MAX_PATH - 1);    //scanf接收不到带空格的字符串。
	TrimStr(strInput, strOutput);
	_tprintf(_T("output:%s"), strOutput);
	return;
}