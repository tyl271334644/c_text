#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int count_one_bits(unsigned int value)
{
	int count = 0;
	while (value)//valueΪ0ʱ����ѭ��
	{
		if (value % 2)
			count++;
		value = value / 2;
	}
	return count;
}
int main()
{
	int i = 0;
	int result = 0;
	printf("������һ��������");
	scanf("%d", &i);
	result = count_one_bits(i);
	printf("result=%d\n", result);
	system("pause");
	return 0;
}
