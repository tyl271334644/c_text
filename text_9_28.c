#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int i;
	double sum = 0, sub = 0;
	for (i = 1; i < 101; i++)
	{
		sub = pow(-1, i + 1);
		sum = sum + sub * 1 / i;
	}
	printf("sum =%f\n", sum);
	system("pause");
	return 0;
}
