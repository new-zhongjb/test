#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//接收一个整形值（无符号），按照顺序打印它的每一位
//分析：如果它只有一位数，则直接打印；
//两位数，先除以10打印商，再模10打印余数； 

void mat(int n)
{
	if (n>9)
	{
		mat(n / 10);
	}
	printf("%d ", n % 10);
}

int main()
{
	unsigned int n = 0;
	
	scanf("%d", &n);
	mat(n);
	return 0;
}



//用递归计算n的阶乘

int fac(int n)
{
	if (n<=1)
	{
		return 1;
	}
	else
	{
		return n * fac(n - 1);
	}
}

int main()
{
	int n = 0;
	printf("求谁的阶乘:>");
	scanf("%d", &n);
	int ret = fac(n);
	printf("所求阶乘结果为:>");
	printf("%d\n", ret);
	return 0;
}


//求斐波那契数,斐波那契数列1，1，2，3，5，8，13，21，34，55。。。。。前两个数相加等于第三个数
int fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;//定义三个变量，当n小于2，斐波那契数为1；当n大于2，斐波那契数为前两个数之和
	while (n>2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	int s = 0;
	printf("输入所求斐波那契数序号:>");
	scanf("%d", &n);
	s = fib(n);
	printf("所求斐波那契数为:>");
	printf("%d\n", s);
	return 0;
}