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
	printf("��ʼ��ַ  ����  ״̬\n");
	for (i = 0; i < N; i++)
		printf("%3d  %8d  %4d\n", P[i].startaddress, P[i].size, P[i].state);
}
void First()
{
	int i, l = 0, m;
	printf("\n���������������Ĵ�С��");
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
		printf("��ַ�ɹ�����\n\n");
		printf("��ַ����ɹ����״̬��\n");
		print();
	}
	else
		printf("û�п��Է���ĵ�ַ�ռ�\n");
}
void CirFirst()
{
	int l = 0, m, t = 0;
	printf("\n���������������Ĵ�С��");
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
		printf("��ַ�ɹ�����\n\n");
		printf("��ַ����ɹ����״̬��\n");
		print();
	}
	else
		printf("û�п��Է���ĵ�ַ�ռ�\n");
}
void Worst()
{
	int i, t = 0, l = 0, m;
	int a[L];
	printf("\n���������������Ĵ�С��");
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
		printf("��ַ�ɹ�����\n\n");
		printf("��ַ����ɹ����״̬��\n");
		print();
	}
	else
		printf("û�п��Է���ĵ�ַ�ռ�\n");
}
void Best()
{
	int i, t = 0, l = 0, m;
	int a[L];
	printf("\n���������������Ĵ�С��");
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
		printf("��ַ�ɹ�����\n\n");
		printf("��ַ����ɹ����״̬��\n");
		print();
	}
	else
		printf("û�п��Է���ĵ�ַ�ռ�\n");
}
void main()
{
	int k = 0;
	printf("��̬���������㷨��");
	while (k != 5)
	{
		printf("\n~~~~~~~~���˵�~~~~~~~~~");
		printf("\n1���״���Ӧ�㷨\n2��ѭ���״���Ӧ�㷨");
		printf("\n3�����Ӧ�㷨\n4�������Ӧ�㷨");
		printf("\n5���˳�\n");
		printf("��ѡ���㷨��");
		scanf("%d", &k);
		switch (k)
		{
		case 1:
			printf("\n��ʼ״̬Ϊ��\n");
			print();
			First();
			continue;
		case 2:
			printf("\n��ʼ״̬Ϊ��\n");
			print();
			CirFirst();
			continue;
		case 3:
			printf("\n��ʼ״̬Ϊ��\n");
			print();
			Worst();
			continue;
		case 4: printf("\n��ʼ״̬Ϊ��\n");
			print();
			Best();
			continue;
		case 5:
			break;
		default:printf("ѡ�����������ѡ��\n");
		}
	}
}
