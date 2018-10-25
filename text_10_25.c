#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define   ROW  32 //宏指令,定义数组长度,可根据情况进行修改
int   main(){
	 int data= 0;
	 int i = 0;
	 printf("请输入数字!\n");
	 scanf("%d", &data);
	int arr[ROW] = { 0 };
	for (i = 0; i < ROW; i++)
	{
		arr[i] = data % 2;
		data = data / 2;
	}
	printf("偶数\n");
	for (i = ROW-1; i >= 0; i = i - 2){
		printf("%d", arr[i]);
	}
	printf("\n");
	printf("奇数:\n");
	for (i = ROW-2; i >= 0; i = i - 2){
		printf("%d", arr[i]);
	}
	system("pause");
	return 0;
}
