#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define   ROW  32 //��ָ��,�������鳤��,�ɸ�����������޸�
int   main(){
	 int data= 0;
	 int i = 0;
	 printf("����������!\n");
	 scanf("%d", &data);
	int arr[ROW] = { 0 };
	for (i = 0; i < ROW; i++)
	{
		arr[i] = data % 2;
		data = data / 2;
	}
	printf("ż��\n");
	for (i = ROW-1; i >= 0; i = i - 2){
		printf("%d", arr[i]);
	}
	printf("\n");
	printf("����:\n");
	for (i = ROW-2; i >= 0; i = i - 2){
		printf("%d", arr[i]);
	}
	system("pause");
	return 0;
}
