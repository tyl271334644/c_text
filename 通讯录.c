#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//通讯录,需要在代码中表示若干人
typedef struct PersonInfo{
	char name[1024];
	char phone[1024];
}PersonInfo;

#define SIZE 1000   //宏定义通讯录长度为1000,后期可根据个人需要进行修改

typedef struct AddrBook{
	//SIZE表示的通讯录中的信息上限
	PersonInfo person_info[SIZE];
	//需要标注出哪些信息是有意义的,哪些信息是没有意义的
	//通讯录并不是程序已启动,里面的1000条数据是有意义的
	//[0,size)有意义的区间
	int size;
}AddrBook;

AddrBook g_addr_book;

enum{
	EXIT=0,
	ADD,
	DEL,
	MODIFY,
	FIND,     //查找内容
	PRINT,    //打印内容
	CLEAR,    //清空内容
};
void Init(){
	g_addr_book.size = 0;
	//for (int i = 0; i < SIZE; ++i){
	//	strcpy(g_addr_book.person_info[i].name, " ");
	//	strcpy(g_addr_book.person_info[i].name, " ");
	//}
	//方法一
	memset(g_addr_book.person_info, 0x0,
		sizeof(g_addr_book.person_info));
	//初始化
}

int  Menu(){
	//打印出用户提供的操作,
	//并且提示用户输入,
	//把用户输入的结果返回出来
	printf("========\n");
	printf(" 1.添加\n");
	printf(" 2.删除\n");
	printf(" 3.修改\n");
	printf(" 4.查找\n");
	printf(" 5.显示\n");
	printf(" 6.清除\n");
	printf(" 0.退出\n");
	printf("========\n");
	printf("请输入你的选择:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void AddPersonInfo(){
	//添加一个用户信息到通讯录中
	//提示用户相关的用户信息,然后把对应的数据更新到数组中
	printf("添加一个新用户!\n");
	printf("请输入一个用户名:");
	//下标为size的位置就是我们需要放置的新元素的位置
	scanf("%s", g_addr_book.person_info[g_addr_book.size].name);
	printf("请输入电话号码:");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].phone);
	++g_addr_book.size;
	printf("插入成功!\n");
}
void DelPersonInfo(){
	//按照用户信息的编号进行删除
	printf("删除指定记录!\n");
	printf("请输入要删除的条目的编号: ");
	int  num = 0;
	scanf("%d", &num);
	if (num < 0 || num >= g_addr_book.size){
		printf("输入的编号不合法,删除失败!\n");
		return;
	}
	//如果要删除的用户是最后一个,那么就直接--size
	if (num != g_addr_book.size - 1){
		strcpy(g_addr_book.person_info[num].name,
			g_addr_book.person_info[g_addr_book.size - 1].name);
		strcpy(g_addr_book.person_info[num].phone,
			g_addr_book.person_info[g_addr_book.size-1].phone);
	}
	--g_addr_book.size;
	printf("删除成功!\n");
	return;
}
void ModifyPersonInfo(){
	//修改某个用户信息,用户输入一个进行修改的编号,根据编号进行修改
	printf("修改某条记录\n");
	printf("请输入要修改的信息编号:");
	int  num = 0;
	scanf("%d", &num);
	if (num < 0 || num >= g_addr_book.size){
		printf("输入的编号不合法,修改失败!\n");
		return;
	}
	printf("请输入新的用户名:");
	scanf("%s", g_addr_book.person_info[num].name);
	printf("请输入新的电话号码:");
	scanf("%s", g_addr_book.person_info[num].phone);
	printf("修改成功!\n");
}
void FindPersonInfo(){
	//根据用户名查找
	printf("查找电话号码!\n");
	printf("请输入要查找的姓名: ");
	char name[1024] = { 0 };
	scanf("%s", name);
	int count = 0;
	for (int i = 0; i < g_addr_book.size; ++i){
		if (strcmp(name, g_addr_book.person_info[i].name) == 0){
			printf("找到一条结果,电话号码为:%s\n",
				g_addr_book.person_info[i].phone);
			++count;
		}
		if (count == 0){
			printf("未找到指定的姓名,请重新查找\n");
		}
		else{
			printf("查找成功!找到%d条结果!\n",g_addr_book.size);
		}
	}
}
void PrintPersonInfo(){
	//打印所有的用户信息
	printf("打印所有的用户信息!\n");
	for (int i = 0; i < g_addr_book.size; ++i){
		printf("[%d] %s %s\n",i, g_addr_book.person_info[i].name,
			g_addr_book.person_info[i].phone);
	}
	printf("打印完成! 共打印了%d条记录\n",g_addr_book.size);
	return;
}
void ClearPersonInfo(){
	printf("清楚所有用户信息!\n");
	printf("确定删除所有信息(y/n)\n");
	char input[1024] = { 0 };
	scanf("%s", input);
	if (strcmp(input, "y") != 0){
		printf("已经取消删除操作!\n");
		return;
	}
	g_addr_book.size = 0;
	printf("清除成功!\n");
}
int main(){
	//1.先建立一个通讯录的变量,并且对这个变量进行初始化
	Init();
	while (1){
		//2.进入循环,打印一个用户菜单,并且提示用户进行操作
		//增删查改
		int choice = Menu();
		//3.用户输入了相应的编号后,就调用对应的操作函数,完成基本操作
		switch (choice){
		case ADD:
			AddPersonInfo();
			break;
		case DEL:
			DelPersonInfo();
			break;
		case MODIFY:
			ModifyPersonInfo();
			break;
		case FIND:
			FindPersonInfo();
			break;
		case PRINT:
			PrintPersonInfo();
			break;
		case CLEAR:
			ClearPersonInfo();
			break;
		case EXIT:
			printf("Goodbye!\n");
			system("pause");
			return 0;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}