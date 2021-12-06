//桶排序（bucket_sort）是一种针对小数或者变化范围较小数快速排序方法
//假设有一组数量为N的数组Array，数组中的数字范围由1到M（或者由n到m）
//利用这个特点信息，可以预设一个空数组Count，Count的大小为M（或m-n+1），内部数值设置为0
//对数组Array中的数字进行读取，将其减去基础值1(或者n),Count的对应位置上数值加1
//最后遍历Count，当其内容不为零时，输出下标加基础值，内容为几则输出几次


#include<stdio.h>
#include<stdlib.h>
//返回数组的最大值
int Max(int* a,int len)
{
	int p = 0;
	int i = 0;
	p = *a;
	for (i = 1; i < len; i++)
	{
		if (*(a + i) > p)
		{
			p = *(a + i);
		}
	}
	return p;
}

//返回数组的最小值
int Min(int* a, int len)
{
	int p = 0;
	int i = 0;
	p = *a;
	for (i = 1; i < len ; i++)
	{
		if (*(a + i) < p)
		{
			p = *(a + i);
		}
	}
	return p;
}

//返回排序结束Count的首元素地址
int* Bucket_sort(int* a,int b,int c,int len)
{
	int* Count = 0;
	int i = 0;
	Count = (int*)malloc(sizeof(*a) * (b - c + 1));
	//先进行初始化为零的操作
	for (i = 0; i < (b - c + 1); i++)
	{
		*(Count + i) = 0;
	}
	//进行排序操作
	for (i = 0; i < len; i++)
	{
		*(Count + (*(a + i) - c)) += 1;
	}
	return Count;
}

int main()
{
	int i = 0;
	int a[] = { 1,4,4,5,6,6,3,7,2,9,11 };
	int len = sizeof(a) / sizeof(a[0]);
	int b = Max(a,len);//计算数组中的最大值
	int c = Min(a,len);//计算数组中的最小值，也是基础值
	int* d = Bucket_sort(a,b,c,len);
	//将排序后的数组打印
	for (i = 0; i < (b - c + 1); i++)
	{
		while (*(d + i)!=0)
		{
			printf("%d ", i + c);
			*(d + i) -= 1;
		}
	}
	return 0;
}