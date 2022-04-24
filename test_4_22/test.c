#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include "add.h"
//
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = Add(a, b);
//	printf("sum=%d\n", sum);
//	return 0;
//}

//int main()
//{
//	printf("hehe\n");
//	main();//简单递归，不断向栈申请空间，直到空间不足，栈溢出
//	return 0;
//}

//接受一个整形值（无符号），按照顺序打印它的每一位。例如输入1234，输出1，2，3，4
//void print(int n)
//{
//	if (n > 9)//如果n大于9，那就至少是两位数
//	{
//		print(n / 10);//n除以10，得到123，递归回到print得12，再递归得1。最后一次递归得到结果，返回上一次递归，n是12，模10得2，打印2.再返回打印3，然后4
//	}
//	printf("%d ", n%10);//1模10得1，打印1.
//}
//
//int main()
//{
//	unsigned int num = 0;//unsigned int(无符号整形)
//	scanf("%d", &num);//输入1234
//	print(num);
//
//	return 0;
//}
#include <string.h>
//编写函数不允许创建临时变量，求字符串长度
//int my_strlen(char* str)
//{
//	int count = 0;//这是创建了临时变量的方法
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

int my_strlen(char* str)//str指向的是第一个字符的地址
{
	if (*str != '\0')
	{
		return 1 + my_strlen(str + 1);
	}
	else
		return 0;
}


int main()
{
	char arr[] = "bit";
	//int len = strlen(arr);//求字符串长度
	//printf("%d", len);
	int len = my_strlen(arr);//arr是数组，数组传参，传过去的不是整个数组，而是第一个元素的地址
	printf("len=%d\n", len);
	return 0;
}