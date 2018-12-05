////#include<stdio.h>
////#include<stdlib.h>
//////////CmpInt是qsort的比较函数.CmpInt调用时机不是由程序员自己决定
//////////而是由qsort内部来决定的.像这种风格的函数,就叫做回调函数
////////int  CmpInt(void* p1,void* p2) {
////////	int* a = (int*) p1;
////////	int* b = (int* )p2;
////////	//如果*a<*b相当于让函数返回真
////////	//如果期望p2指向的元素在p1的前面返回真
////////	//如果期望p1指向的元素在p2的前面返回假
////////	return  *a < *b;
////////}
////int main() {
//////	//int a[] = { 1,2,3,4 };
//////	//printf("%d\n", sizeof(a));     
//////	////16  sizeof求的是整个a数组的大小,一个元素为int-4,4个则为16
//////	//printf("%d\n", sizeof(a + 0));
//////	////4   数组名不能进行数学运算,此时a隐式转换成了指针
//////	//printf("%d\n", sizeof(*a));
//////	////4   数组名隐式转换成了指针,指向第一个int类型
//////	//printf("%d\n", sizeof(a + 1));
//////	////4    类似于第二个
//////	//printf("%d\n", sizeof(a[1]));
//////	////4    取出具体元素 2
//////	//printf("%d\n", sizeof(&a));
//////	////4    此时a为数组指针也属于指针
//////	//printf("%d\n", sizeof(*&a));
//////	////16   &a数组指针,对这个指针解引用得到的仍然是原来的数组
//////	//printf("%d\n", sizeof(&a + 1));
//////	////4    指针+1还是指针
//////	//printf("%d\n", sizeof(&a[0]));
//////	////4   先运算方括号里面
//////	//printf("%d\n", sizeof(&a[0] + 1));
//////	////4  
//////
//////
//////
//////
//////
//////	////c  string C风格字符串,才是以\0作为结束标志
//////   
//////	//printf("%d\n", sizeof(arr));
//////	////6
//////	//printf("%d\n", sizeof(arr+0));
//////	////4    转换为指针 
//////	//printf("%d\n", sizeof(*arr));
//////	////1    指针取出首元素
//////	//printf("%d\n", sizeof(arr[1]));
//////	////1    取出数组具体元素
//////	//printf("%d\n", sizeof(&arr));
//////	////4    数组指针
//////	//printf("%d\n", sizeof(&arr + 1));
//////	////4    同上
//////	//printf("%d\n", sizeof(&arr[0] + 1));
//////	////4    同上
//////
//////
//////
//////
////// //	printf("%d\n", strlen(arr));
//////	////结果为19表示第19个位置处存在\0,不同机器可能表示不同
//////	//printf("%d\n", strlen(arr + 0));
//////	////同上
//////	//printf("%d\n", strlen(*arr));
//////	////解引用为字符a,单个字符无法进行strlen
//////	////vs编译通过但是运行崩溃,检查不严格
//////	//printf("%d\n", strlen(arr[1]));
//////	////同上
//////	//printf("%d\n", strlen(&arr));
//////	////19 类似于第一个strlen
//////	//printf("%d\n", strlen(&arr + 1));
//////	////13 类似于第一个strlen
//////	//printf("%d\n", strlen(&arr[0] + 1));//////	////18  类似于第一个strlen
//////
//////
//////
//////   ////此时arr中包含了\0
//////   //char arr[] = "abcdef";
//////   //printf("%d\n", sizeof(arr));
//////   ////7 \0一起被带入数组
//////   //printf("%d\n", sizeof(arr + 0));
//////   ////4   数组名不能进行数学运算,此时数组隐式转换成了指针
//////   //printf("%d\n", sizeof(*arr));
//////   ////1  取到首元素的内容
//////   //printf("%d\n", sizeof(arr[1]));
//////   ////1  取到某个元素的内容
//////   //printf("%d\n", sizeof(&arr));
//////   ////4    数组指针
//////   //printf("%d\n", sizeof(&arr + 1));
//////   ////4    指针
//////   //printf("%d\n", sizeof(&arr[0] + 1));
//////   ////4    指针
//////   //printf("%d\n", strlen(arr));
//////   ////6   strlen求字符串长度时不会计算末尾的\0
//////   //printf("%d\n", strlen(arr + 0));
//////   ////6   同上
//////   //printf("%d\n", strlen(*arr));
//////   ////无法对一个字符进行strlen
//////   //printf("%d\n", strlen(arr[1]));
//////   ////同上
//////   //printf("%d\n", strlen(&arr));
//////   ////6  寻找\0结尾但不计入   
//////   //printf("%d\n", strlen(&arr + 1));
//////   ////随机值   跳过当前数组寻找\0,随机值不同系统值不同
//////   //printf("%d\n", strlen(&arr[0] + 1));
//////   ////5 跳过一个元素
//////
//////
//////
//////
//////
//////   // //" " 包含的字符串就是C风格字符串包含\0
//////   //char *p = "abcdef";
//////   //printf("%d\n", sizeof(p));
//////   ////4   指针
//////   //printf("%d\n", sizeof(p + 1));
//////
//////   ////4  同上
//////   //printf("%d\n", sizeof(*p));
//////   ////1  指向第一个首元素地址,解引用为第一个元素
//////   //printf("%d\n", sizeof(p[0]));
//////   ////1  
//////   //printf("%d\n", sizeof(&p));
//////   ////4  二级指针还是指针,指向元素为一级指针
//////   //printf("%d\n", sizeof(&p + 1));
//////   ////4    指针
//////   //printf("%d\n", sizeof(&p[0] + 1));
//////   ////4   同上
//////   //printf("%d\n", strlen(p));
//////   ////6
//////   //printf("%d\n", strlen(p + 1));
//////   ////5   当前只跳过一个元素
//////   //printf("%d\n", strlen(*p));
//////   ////可通过编译无法进行strlen
//////   //printf("%d\n", strlen(p[0]));
//////   ////同上
//////   //printf("%d\n", strlen(&p));
//////   ////随机值    寻找\0不同系统值不同
//////   //printf("%d\n", strlen(&p + 1));
//////   ////随机值
//////   //printf("%d\n", strlen(&p[0] + 1));
//////   ////5  跳过一个元素
////// // 
//////
//////
////// //   int a[3][4] = { 0 };
//////	//printf("%d\n", sizeof(a));
//////	////48     3x4x4
//////	//printf("%d\n", sizeof(a[0][0]));
//////	////4     具体某个元素
//////	//printf("%d\n", sizeof(a[0]));
//////	////16     取到结果为4个整形元素的数组
//////	//printf("%d\n", sizeof(a[0] + 1));
//////	////4     只要进行数学运算 数组变为指针
//////	//printf("%d\n", sizeof(*(a[0] + 1)));
//////	////4    等价于==>a[0][1]取出的是具体变量
//////	//printf("%d\n", sizeof(a + 1));
//////	////4    指针
//////	//printf("%d\n", sizeof(*(a + 1)));
//////	////16   ==>a[1]  长度为4的一维数组
//////	//printf("%d\n", sizeof(&a[0] + 1));
//////	////4    指针
//////	//printf("%d\n", sizeof(*(&a[0] + 1)));
//////	////16  指向数组的指针 
//////	//printf("%d\n", sizeof(*a));
//////	////16  ==>a[0]
//////	//printf("%d\n", sizeof(a[3]));
//////	////16
//////
//////
//////
//////
//////
//////
//////	//int a[5] = { 1, 2, 3, 4, 5 };
//////	//int *ptr = (int *)(&a + 1);
//////	////ptr指向比较关键 &a+1得到的结果是一个指向数组最后一个的
//////	////下一个位置的地址
//////	//printf("%d,%d", *(a + 1), *(ptr - 1));
////int m = 123;
////  int result = 0;
////  int i = 0;
////  while (1)
////  {
////	  i = m % 10;
////	  result = result * 10 + i;
////	  m = m/10;
////	  
////  }
////  printf("%d", i);
////
//////	
//////
////
////	//int a[4] = { 1, 2, 3, 4 };
////	//int *ptr1 = (int *)(&a + 1);
////	//int *ptr2 = (int *)((int)a + 1);
////	//printf("%x,%x", ptr1[-1], *ptr2);
////
////
////	system("pause");
////	return 0;
////}
////
//////
//////
//////	
////////char *p = "abcdef";
////////printf("%d\n", sizeof(p));
////////printf("%d\n", sizeof(p + 1));
////////printf("%d\n", sizeof(*p));
////////printf("%d\n", sizeof(p[0]));
////////printf("%d\n", sizeof(&p));
////////printf("%d\n", sizeof(&p + 1));
////////printf("%d\n", sizeof(&p[0] + 1));
////////printf("%d\n", strlen(p));
////////printf("%d\n", strlen(p + 1));
////////printf("%d\n", strlen(*p));
////////printf("%d\n", strlen(p[0]));
////////printf("%d\n", strlen(&p));
////////printf("%d\n", strlen(&p + 1));
////////printf("%d\n", strlen(&p[0] + 1));
////////////一维数组
////////int a[] = { 1,2,3,4 };
////////printf("%d\n", sizeof(a));
////////printf("%d\n", sizeof(a + 0));
////////printf("%d\n", sizeof(*a));
////////printf("%d\n", sizeof(a + 1));
////////printf("%d\n", sizeof(a[1]));
////////printf("%d\n", sizeof(&a));
////////printf("%d\n", sizeof(*&a));
////////printf("%d\n", sizeof(&a + 1));
////////printf("%d\n", sizeof(&a[0]));
////////printf("%d\n", sizeof(&a[0] + 1));
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int n;
//	scanf_s("%d", &n);//输入要翻转的数字 
//	int result = 0;//保存翻转后的结果
//	while (1)//while(true)也可以 
//	{
//		if ((n > pow(2, 31) - 1) || (n < (-1)*pow(2, 31))) {
//			return 0;
//		}
//		int i = n % 10;//每次都是得到最低位上的数字
//		result = result * 10 + i;
//		n = n / 10;//递归降位
//		if (n == 0)
//		{
//			break;
//		}
//		
//	}
//	
//	printf("翻转后的数字是%d\n", result);
//}
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool isPowerOfTwo(int n) {
	if (n == 0 || n < 0) {
		return false;
	}
	return ((n & (n - 1)) == 0);
}


int main() {
	int x = 0;
	scanf("%d", &x);
	printf("%d", isPowerOfTwo(x));
}
