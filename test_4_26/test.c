#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ
//�����������ֻ��һλ������ֱ�Ӵ�ӡ��
//��λ�����ȳ���10��ӡ�̣���ģ10��ӡ������ 

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



//�õݹ����n�Ľ׳�

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
	printf("��˭�Ľ׳�:>");
	scanf("%d", &n);
	int ret = fac(n);
	printf("����׳˽��Ϊ:>");
	printf("%d\n", ret);
	return 0;
}


//��쳲�������,쳲���������1��1��2��3��5��8��13��21��34��55����������ǰ��������ӵ��ڵ�������
int fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;//����������������nС��2��쳲�������Ϊ1����n����2��쳲�������Ϊǰ������֮��
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
	printf("��������쳲����������:>");
	scanf("%d", &n);
	s = fib(n);
	printf("����쳲�������Ϊ:>");
	printf("%d\n", s);
	return 0;
}