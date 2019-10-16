#include<stdio.h>
#include<Windows.h>

//测试参数入栈顺序
void test1(int a, int b, int c, int d, int e, int f)
{
	//栈是从高地址向低地址增长的
	printf("%p\n%p\n%p\n%p\n%p\n%p\n\n", &a, &b, &c, &d, &e, &f);

	/*
	000000F9EA6FF970
	000000F9EA6FF978
	000000F9EA6FF980
	000000F9EA6FF988
	000000F9EA6FF990
	000000F9EA6FF998
	-> 从a到f地址值依次增加8,从地址值可以推测f是最先入栈，a是最后入栈的。也就是说，参数是从右往左入栈的（注:当然并非所有语言都是如此）。
	*/
	
}
//变长参数实现分析：根据第一个参数的地址取得第二，第三，第...的参数值
void test2(int a, int b, int c, int d, int e, int f)
{
	intptr_t p_a = __int64(&a);
	intptr_t p_b = p_a + 8;
	intptr_t p_c = p_a + 16;
	intptr_t p_d = p_a + 24;
	intptr_t p_e = p_a + 32;
	intptr_t p_f = p_a + 40;
	printf("%d\n%d\n%d\n%d\n%d\n%d\n\n", *((int *)p_a), *((int *)p_b), *((int *)p_c), *((int *)p_d), *((int *)p_e), *((int *)p_f));

	/*
	1
	2
	3
	4
	5
	6
	-> 我们可以通过第一个参数取得其他参数的值，所以原理上来看，我们可以实现变长参数。	
	*/
}

//使用C提供的变长参数取得宏
void testTraceLog(const char *pLogFormat, ...)
{	
	char szMsg[MAX_PATH] = "";
	va_list args;
	va_start(args, pLogFormat);
	vsprintf_s(szMsg, pLogFormat, args);
	va_end(args);

	SYSTEMTIME time;
	GetLocalTime(&time);
	char szBuffer[MAX_PATH + 20] = "";
	sprintf_s(szBuffer,
		"%04d/%02d/%02d %02d:%02d:%02d ",
		time.wYear,
		time.wMonth,
		time.wDay,
		time.wHour,
		time.wMinute,
		time.wSecond);
	strcat_s(szBuffer, szMsg);
	strcat_s(szBuffer, "\r\n");
	printf("%s", szBuffer);
	/*
		TODO: write log file.
	*/

}

int main(int argc, char *argv[]) 
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;

	//参数入栈的调查
	test1(a, b, c, d, e, f); 


	//变长参数实现分析
	/*
	通过上面的例子我们可以发现，参数是从右往左入栈的，并且第一个参数就在栈顶存放。
	那么，如果我们知道了第一各参数的地址，是不是就能根据第一个参数的地址+偏移，取得其他参数的值呢？
	*/
	test2(a, b, c, d, e, f);

	//变长参数实现
	/*
	C已经有现成可用的一些东西来帮我们实现变长参数。它主要通过一个类型（va_list）和三个宏（va_start、va_arg、va_end）来实现

	va_list ：存储参数的类型信息
	void va_start ( va_list ap, paramN );
	参数：
	ap: 可变参数列表地址
	paramN: 确定的参数
	功能：初始化可变参数列表，会把paraN之后的参数放入ap中

	type va_arg ( va_list ap, type );
	功能：返回下一个参数的值。

	void va_end ( va_list ap );
	功能：完成清理工作。
	*/
	testTraceLog("今天是%d年%d月%d日，%s",2019,10,16,"星期三");


}