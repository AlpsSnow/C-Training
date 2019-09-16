#include<stdio.h>
#include<Windows.h>

void translate(char *p)
{
	char stroutput[MAX_PATH] = { 0 };
	int j = 0;
	if(NULL == p)
	{
		printf("p err.\n");
		return;
	}
	for (size_t i = 0; i < lstrlen(p); i++)
	{
		if (*(p + i) >= 'a' && *(p + i) <= 'z')
		{
			stroutput[j] = *(p + i);
			j++;
		}
		else if(*(p + i) >= 'A' && *(p + i) <= 'Z')
		{
			stroutput[j] = *(p + i) + 32;
			j++;
		}
	}
	memset(p, 0, MAX_PATH);
	lstrcpy(p,stroutput);
	return;
}
void main()
{
	char strinput[MAX_PATH] = { 0 };
	printf("Please enter a string:");
	gets_s(strinput, MAX_PATH-1);
	translate(strinput);
	printf("%s",strinput);
}