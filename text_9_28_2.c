#include<stdio.h>
#include<stdlib.h>
int main(){
	int i;
	int sum = 0;
	for (i = 1; i < 101; i++){
		if (i % 10 == 9){  //对数字i求模,模如果为9,sum+1
			sum += 1;
		}
		if (i / 10 == 9){  //对数字i求商,商为9,sum+1
			sum += 1;
		}
	}
	printf("%d\n", sum);

	system("pause");
	return 0;
}

