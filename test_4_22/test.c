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
//	main();//�򵥵ݹ飬������ջ����ռ䣬ֱ���ռ䲻�㣬ջ���
//	return 0;
//}

//����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ����������1234�����1��2��3��4
//void print(int n)
//{
//	if (n > 9)//���n����9���Ǿ���������λ��
//	{
//		print(n / 10);//n����10���õ�123���ݹ�ص�print��12���ٵݹ��1�����һ�εݹ�õ������������һ�εݹ飬n��12��ģ10��2����ӡ2.�ٷ��ش�ӡ3��Ȼ��4
//	}
//	printf("%d ", n%10);//1ģ10��1����ӡ1.
//}
//
//int main()
//{
//	unsigned int num = 0;//unsigned int(�޷�������)
//	scanf("%d", &num);//����1234
//	print(num);
//
//	return 0;
//}
#include <string.h>
//��д��������������ʱ���������ַ�������
//int my_strlen(char* str)
//{
//	int count = 0;//���Ǵ�������ʱ�����ķ���
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

int my_strlen(char* str)//strָ����ǵ�һ���ַ��ĵ�ַ
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
	//int len = strlen(arr);//���ַ�������
	//printf("%d", len);
	int len = my_strlen(arr);//arr�����飬���鴫�Σ�����ȥ�Ĳ����������飬���ǵ�һ��Ԫ�صĵ�ַ
	printf("len=%d\n", len);
	return 0;
}