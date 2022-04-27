#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>

//数组名是首元素的地址
int main()
{
	int arr[] = { 1,2,3,4,5 };
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);
	printf("%d\n", *arr);
	return 0;
}
//数组名是首元素的地址，但有两个例外
//①sizeof(数组名) --数组名表示整个数组，sizeof(数组名)计算的是整个数组的大小，单位是字节
//②&数组名（取地址数组名），数组名代表整个数组，取出的是整个数组的地址



//对整形数组进行冒泡排序
bubble_sort(int arr[],int sz)
{
	//确定冒泡排序的躺数
	int i = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]);
	for (i=0;i<sz-1;i++)
	{
		int j = 0;
		int flag = 1;//假设这一趟排序已经有序
		for (j=0;j<sz-1-i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;//本躺排序的数据不完全有序
			}
		}
		if (flag == 1)
		{
			break;//如果数组不需要排序，直接跳出
		}
	}

}

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//对arr进行排序，形成升序
	//arr是数组，我们对数组arr进行传参，实际上传的是数组首元素的地址，而不是整个数组
	//bubble_sort(arr);//冒泡排序,应该在main函数算好元素个数，传给冒泡排序
	bubble_sort(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);

	}

	return 0;
}
