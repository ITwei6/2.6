//宏是替换不是传参
//定义宏时不要吝啬括号‘
//用于对数值表达式求值的宏定义都应该用这种方式加上括号，避免
//使用宏时由于参数中的操作符或邻近操作符之间不可预料的相互作用
//# X不会将X替换而是会变成X对应的那个字符串
//4个二进制转化一个16进制位/

//%02x   16进制输出，保留2位
///数据放到内存就牵扯到大小端问题
//char *p= "123456";这样写不严谨，右边是不可以改变的常量字符串
//但右边又可以通过指针来改变指针所指向的内容，所以应该在前面加上caonst
//const char* p = "123456";
// x，y，将地址传给函数，充当参数和返回值
//返回型参数，我们希望它能从函数中带回来一些值/
#include <ctype.h>
#include <stdio.h>
#define INT_MAX       2147483647
#define INT_MIN     (-2147483647 - 1)
enum State
{
	INVALE,//默认是非法的
	VALE//默认是合法的
}state;
     state = INVALE;//因为大多数情况是非法的，所以一开始让state默认为非法的
	/* 设置成全局变量，整体都可以访问*/
int digit_change(char* s)
{
	
	int flag = 1;//正数默认是1
	if (s == NULL)//1.空指针
	{
		return 0;//非法情况下的返回0
	}
	if (*s =='\0')//2.空白字符串
	{
		return 0;//非法情况下的返回0
	}
	while (isspace(*s))//如果是空格则返回非0，如果不是则返回0
	{
		s++;
	}
	if (*s == '+')//3.非法符号+  -
	{
		flag = 1;
		s++;
	}
	else if (*s == '-')
	{
		flag = -1;
		s++;
	}

	long long n = 0;
	while (isdigit(*s))//处理数字字符转换
	{
		n = n * 10 + flag*(*s - '0');
		if (n > INT_MAX || n < INT_MIN)
		{
			return 0;
		}
		s++;
	}
	/*跳出来有两种情况，一种是找到\0，另一种是发现不是数字字符，但都是合法的*/
	state = VALE;//把state改为合法的
	return (int)n;
	//if (*s == '\0')
	//{
	//	state = VALE;
	//	return (int)n;
	//}
	//else
	//{
	//	/*也可以把前面的数值返回去不过是非法情况下的*/
	//	state = INVALE;
	//	return (int)n;
	//}

	
}
int main()
{

	char* s = "   -112a";
	int ret=digit_change(s);
	if (state == VALE)
	{
		printf("合法的%d", ret);
	}
	else
	{
		printf("非法的%d", ret);
	}
	return 0;
}
//#include <stdlib.h>
//int main()
//{
//	const char* p = "   666";//常量字符串是不可以修改的
//	//所以用const修饰*p，使指针p指向的内容不能修改
//	int ret = atoi(p);
//	printf("%d", ret);
//	return 0;
//}
