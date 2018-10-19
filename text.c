#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[4] = { 1, 2, 3, 4 };
	int b[4] = { 9, 8, 7, 6 };
	int i;
	for (i = 0; i<4; i++)
	{
		a[i] = a[i] ^ b[i];
		b[i] = a[i] ^ b[i];
		a[i] = a[i] ^ b[i];

	}
	for (i = 0; i < 4; i++){
		printf("%d", a[i]);
	}
	printf("\n");
	for (i = 0; i < 4; i++){
		printf("%d", b[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
