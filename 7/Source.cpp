#include<stdio.h>
#include<Windows.h>
#include <locale.h>

#define MAX_OUTPUT_NUMBER 4096

bool AnalyzeStr(char *strInput, char *strOutput)
{
	size_t ilen = 0;
	char *p = NULL;
	int charCount = 0;
	char strWork[MAX_PATH] = { 0 };
	char strLeftover[MAX_PATH] = { 0 };

	if (strInput == NULL)
	{
		printf("Parameter error！(NULL = strInput)\n");
		return false;
	}

	ilen = strlen(strInput);
	if (ilen == 0 || ilen > MAX_PATH - 1)
	{
		printf("Parameter error！(0 = strlen(strInput) || MAX_PATH - 1 < strlen(strInput))\n");
		return false;
	}

	strcpy_s(strWork, _countof(strWork), strInput);
	memset(strOutput, 0, sizeof(strOutput));
	sprintf_s(strOutput, MAX_OUTPUT_NUMBER, "output：\n");

	while (ilen != 0)
	{
		p = strWork;
		if (*p < 'a' || *p > 'z') {
			printf("Parameter error！(The string contains unexpected lowercase characters：%c)\n", *p);
			return false;
		}
		charCount = 1;
		for (int i = 1; i < ilen; i++)
		{			
			if (*p == *(strWork + i))
			{
				charCount++;
			}
			else
			{
				sprintf_s(strLeftover+strlen(strLeftover), sizeof(strLeftover)-strlen(strLeftover), "%c", *(strWork + i));
			}
		}

		sprintf_s(strOutput + strlen(strOutput), MAX_OUTPUT_NUMBER - strlen(strOutput), "%c\t%d\n", *p, charCount);
		
		memset(strWork, 0, sizeof(strWork));
		strcat_s(strWork, sizeof(strWork), strLeftover);
		memset(strLeftover, 0, sizeof(strLeftover));
		ilen = strlen(strWork);
	}
	return true;
}

int main(int argc, char *argv[])
{
	setlocale(LC_CTYPE, "");   //设置字符编码未当前系统编码格式
	char strInput[MAX_PATH] = { 0 };
	char strOutput[MAX_OUTPUT_NUMBER] = { 0 };
	int OutputCount = 0;
	printf("lease enter a string that contains only lowercase letters：");
	scanf_s("%s", strInput, MAX_PATH-1);
	if (true == AnalyzeStr(strInput, strOutput))
	{
		printf(strOutput);
		return 0;
	}
	else
	{
		return 1;
	}
}