#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

//����������Ԫ�صĵ�ַ
int main()
{
	int arr[] = { 1,2,3,4,5 };
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);
	printf("%d\n", *arr);
	return 0;
}
//����������Ԫ�صĵ�ַ��������������
//��sizeof(������) --��������ʾ�������飬sizeof(������)���������������Ĵ�С����λ���ֽ�
//��&��������ȡ��ַ���������������������������飬ȡ��������������ĵ�ַ



//�������������ð������
bubble_sort(int arr[],int sz)
{
	//ȷ��ð�����������
	int i = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]);
	for (i=0;i<sz-1;i++)
	{
		int j = 0;
		int flag = 1;//������һ�������Ѿ�����
		for (j=0;j<sz-1-i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//������������ݲ���ȫ����
			}
		}
		if (flag == 1)
		{
			break;//������鲻��Ҫ����ֱ������
		}
	}

}

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//��arr���������γ�����
	//arr�����飬���Ƕ�����arr���д��Σ�ʵ���ϴ�����������Ԫ�صĵ�ַ����������������
	//bubble_sort(arr);//ð������,Ӧ����main�������Ԫ�ظ���������ð������
	bubble_sort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);

	}

	return 0;
}
