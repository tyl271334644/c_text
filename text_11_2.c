//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#define   NUM 10    //�궨�����鳤��
//void  Exchange(int arr[], int size){
//	int  left = 0;
//	int right = arr- 1;
//	while (left < right){
//		//����߿�ʼ�ҵ�һ��ż��
//		while ((left<right)&&arr[left] % 2 != 0){
//			left++;
//		}
//		//���ұ��ҵ�һ������
//		while ((left < right) && arr[right] % 2 == 0){
//			right--;
//		}
//		if (left < right){
//			int temp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = temp;
//		}
//	}
//}
//int main(){
//	int arr[10];
//	int i = 0;
//	int m = 0;
//	int  j = 0;
//	printf("������10������:\n");
//	for (i = 0; i < NUM; ++i){  //NUM�궨��Ϊ10,���ڿ��޸�
//		scanf("%d", &m);
//		arr[i] = m;
//	}
//	int size = strlen(arr);
//	Exchange(arr, size);
//	for (j = 0; j < size; ++j){
//
//	}
//	system("pause");
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
//�����½ǿ�ʼ��
void  find(int a[3][3], int row, int col, int k, int* px,int* py){
	int  i = row -1;
	int  j = 0;
	while ((i > 0) && (j <= col)){   
		//����ҵ�K��ֵ,����K��ʾ��ֵ��λ��
		if (a[i][j] ==k){
			*px = i;
			*py = j;
			return;
		}
		
		else if (a[i][j] < k){
		     j++;
		}
	
		else{
			i--;
		}
	}

}
int main(){
	int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int  px = 0;
	int py = 0;
	find(a, 3, 3, 5, &px, &py);
	printf("%d %d\n",px,py );
	system("pause");
	return 0;

}