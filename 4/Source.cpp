#include<stdio.h>
#include<tchar.h>
#include<Windows.h>
#include <locale.h>

void main()
{
	TCHAR InputStr[MAX_PATH] = { 0 };
	setlocale(LC_CTYPE, "");   //设置字符编码未当前系统编码格式
	_tprintf_s(_T("Please enter a string of Numbers："));
	_getts_s(InputStr, MAX_PATH - 1);

	//输出非0的数字
	for (size_t i = 0; i < lstrlen(InputStr); i++)
	{
		if (*(InputStr + i) > _T('0') && *(InputStr + i) < _T('9')) {
			_tprintf_s(_T("%c"), *(InputStr + i));
		}
	}

	//输出0
	for (size_t i = 0; i < lstrlen(InputStr); i++)
	{
		if (_T('0') == *(InputStr + i)) {
			_tprintf_s(_T("%c"), *(InputStr + i));
		}
	}
	getchar();
}
