//Ͱ����bucket_sort����һ�����С�����߱仯��Χ��С���������򷽷�
//������һ������ΪN������Array�������е����ַ�Χ��1��M��������n��m��
//��������ص���Ϣ������Ԥ��һ��������Count��Count�Ĵ�СΪM����m-n+1�����ڲ���ֵ����Ϊ0
//������Array�е����ֽ��ж�ȡ�������ȥ����ֵ1(����n),Count�Ķ�Ӧλ������ֵ��1
//������Count���������ݲ�Ϊ��ʱ������±�ӻ���ֵ������Ϊ�����������


#include<stdio.h>
#include<stdlib.h>
//������������ֵ
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

//�����������Сֵ
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

//�����������Count����Ԫ�ص�ַ
int* Bucket_sort(int* a,int b,int c,int len)
{
	int* Count = 0;
	int i = 0;
	Count = (int*)malloc(sizeof(*a) * (b - c + 1));
	//�Ƚ��г�ʼ��Ϊ��Ĳ���
	for (i = 0; i < (b - c + 1); i++)
	{
		*(Count + i) = 0;
	}
	//�����������
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
	int b = Max(a,len);//���������е����ֵ
	int c = Min(a,len);//���������е���Сֵ��Ҳ�ǻ���ֵ
	int* d = Bucket_sort(a,b,c,len);
	//�������������ӡ
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