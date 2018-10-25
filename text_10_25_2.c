#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int count_one_bits(unsigned int value)
{
	int count = 0;
	while (value)//value为0时跳出循环
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
	printf("请输入一个正数：");
	scanf("%d", &i);
	result = count_one_bits(i);
	printf("result=%d\n", result);
	system("pause");
	return 0;
}
