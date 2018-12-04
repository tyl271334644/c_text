#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define L 10
typedef struct LNode
{
	int startaddress;
	int size;
	int state;
}LNode;
LNode P[L] = { {0,128,0},{200,256,0},{500,512,0},{1500,1600,0},{5000,150,0} };
int N = 5; int f = 0;
void print()
{
	int i;
	printf("起始地址  分区  状态\n");
	for (i = 0; i < N; i++)
		printf("%3d  %8d  %4d\n", P[i].startaddress, P[i].size, P[i].state);
}
void First()
{
	int i, l = 0, m;
	printf("\n输入请求分配分区的大小：");
	scanf("%d", &m);
	for (i = 0; i < N; i++)
	{
		if (P[i].size < m)
			continue;
		else if (P[i].size == m)
		{
			P[i].state = 1;
			l = 1;
			break;
		}
		else
		{
			P[N].startaddress = P[i].startaddress + m;
			P[N].size = P[i].size - m;
			P[i].size = m; P[i].state = 1;
			l = 1;    N++;
			break;
		}
	}
	if (l == 1 || i < N)
	{
		printf("地址成功分配\n\n");
		printf("地址分配成功后的状态：\n");
		print();
	}
	else
		printf("没有可以分配的地址空间\n");
}
void CirFirst()
{
	int l = 0, m, t = 0;
	printf("\n输入请求分配分区的大小：");
	scanf("%d", &m);
	while (f < N)
	{
		if (P[f].size < m)
		{
			f = f + 1;
			if (f%N == 0)
			{
				f = 0; t = 1;
			}
			continue;
		}
		if (P[f].size == m && P[f].state != 1)
		{
			P[f].state = 1;
			l = 1;		f++;
			break;
		}
		if (P[f].size > m && P[f].state != 1)
		{
			P[N].startaddress = P[f].startaddress + m;
			P[N].size = P[f].size - m;
			P[f].size = m;
			P[f].state = 1;
			l = 1;	   N++;
			f++;	   break;
		}
	}
	if (l == 1)
	{
		printf("地址成功分配\n\n");
		printf("地址分配成功后的状态：\n");
		print();
	}
	else
		printf("没有可以分配的地址空间\n");
}
void Worst()
{
	int i, t = 0, l = 0, m;
	int a[L];
	printf("\n输入请求分配分区的大小：");
	scanf("%d", &m);
	for (i = 0; i < N; i++)
	{
		a[i] = 0;
		if (P[i].size < m)
			continue;
		else if (P[i].size == m)
		{
			P[i].state = 1;
			l = 1;    break;
		}
		else
			a[i] = P[i].size - m;
	}
	if (l == 0)
	{
		for (i = 0; i < N; i++)
		{
			if (a[i] != 0)
				t = i;
		}
		for (i = 0; i < N; i++)
		{
			if (a[i] != 0 && a[i] > a[t])
				t = i;
		}
		P[N].startaddress = P[t].startaddress + m;
		P[N].size = P[t].size - m;
		P[t].size = m; P[t].state = 1;
		l = 1;	 N++;
	}
	if (l == 1 || i < N)
	{
		printf("地址成功分配\n\n");
		printf("地址分配成功后的状态：\n");
		print();
	}
	else
		printf("没有可以分配的地址空间\n");
}
void Best()
{
	int i, t = 0, l = 0, m;
	int a[L];
	printf("\n输入请求分配分区的大小：");
	scanf("%d", &m);
	for (i = 0; i < N; i++)
	{
		a[i] = 0;
		if (P[i].size < m)
			continue;
		else if (P[i].size == m)
		{
			P[i].state = 1;
			l = 1;
			break;
		}
		else
			a[i] = P[i].size - m;
	}
	if (l == 0)
	{
		for (i = 0; i < N; i++)
		{
			if (a[i] != 0)
				t = i;
		}
		for (i = 0; i < N; i++)
		{
			if (a[i] != 0 && a[i] < a[t])
				t = i;
		}
		P[N].startaddress = P[t].startaddress + m;
		P[N].size = P[t].size - m;
		P[t].size = m; P[t].state = 1;
		l = 1;	 N++;
	}
	if (l == 1 || i < N)
	{
		printf("地址成功分配\n\n");
		printf("地址分配成功后的状态：\n");
		print();
	}
	else
		printf("没有可以分配的地址空间\n");
}
void main()
{
	int k = 0;
	printf("动态分区分配算法：");
	while (k != 5)
	{
		printf("\n~~~~~~~~主菜单~~~~~~~~~");
		printf("\n1、首次适应算法\n2、循环首次适应算法");
		printf("\n3、最坏适应算法\n4、最佳适应算法");
		printf("\n5、退出\n");
		printf("请选择算法：");
		scanf("%d", &k);
		switch (k)
		{
		case 1:
			printf("\n初始状态为：\n");
			print();
			First();
			continue;
		case 2:
			printf("\n初始状态为：\n");
			print();
			CirFirst();
			continue;
		case 3:
			printf("\n初始状态为：\n");
			print();
			Worst();
			continue;
		case 4: printf("\n初始状态为：\n");
			print();
			Best();
			continue;
		case 5:
			break;
		default:printf("选择错误，请重新选择。\n");
		}
	}
}
