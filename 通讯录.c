#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//ͨѶ¼,��Ҫ�ڴ����б�ʾ������
typedef struct PersonInfo{
	char name[1024];
	char phone[1024];
}PersonInfo;

#define SIZE 1000   //�궨��ͨѶ¼����Ϊ1000,���ڿɸ��ݸ�����Ҫ�����޸�

typedef struct AddrBook{
	//SIZE��ʾ��ͨѶ¼�е���Ϣ����
	PersonInfo person_info[SIZE];
	//��Ҫ��ע����Щ��Ϣ���������,��Щ��Ϣ��û�������
	//ͨѶ¼�����ǳ���������,�����1000���������������
	//[0,size)�����������
	int size;
}AddrBook;

AddrBook g_addr_book;

enum{
	EXIT=0,
	ADD,
	DEL,
	MODIFY,
	FIND,     //��������
	PRINT,    //��ӡ����
	CLEAR,    //�������
};
void Init(){
	g_addr_book.size = 0;
	//for (int i = 0; i < SIZE; ++i){
	//	strcpy(g_addr_book.person_info[i].name, " ");
	//	strcpy(g_addr_book.person_info[i].name, " ");
	//}
	//����һ
	memset(g_addr_book.person_info, 0x0,
		sizeof(g_addr_book.person_info));
	//��ʼ��
}

int  Menu(){
	//��ӡ���û��ṩ�Ĳ���,
	//������ʾ�û�����,
	//���û�����Ľ�����س���
	printf("========\n");
	printf(" 1.���\n");
	printf(" 2.ɾ��\n");
	printf(" 3.�޸�\n");
	printf(" 4.����\n");
	printf(" 5.��ʾ\n");
	printf(" 6.���\n");
	printf(" 0.�˳�\n");
	printf("========\n");
	printf("���������ѡ��:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void AddPersonInfo(){
	//���һ���û���Ϣ��ͨѶ¼��
	//��ʾ�û���ص��û���Ϣ,Ȼ��Ѷ�Ӧ�����ݸ��µ�������
	printf("���һ�����û�!\n");
	printf("������һ���û���:");
	//�±�Ϊsize��λ�þ���������Ҫ���õ���Ԫ�ص�λ��
	scanf("%s", g_addr_book.person_info[g_addr_book.size].name);
	printf("������绰����:");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].phone);
	++g_addr_book.size;
	printf("����ɹ�!\n");
}
void DelPersonInfo(){
	//�����û���Ϣ�ı�Ž���ɾ��
	printf("ɾ��ָ����¼!\n");
	printf("������Ҫɾ������Ŀ�ı��: ");
	int  num = 0;
	scanf("%d", &num);
	if (num < 0 || num >= g_addr_book.size){
		printf("����ı�Ų��Ϸ�,ɾ��ʧ��!\n");
		return;
	}
	//���Ҫɾ�����û������һ��,��ô��ֱ��--size
	if (num != g_addr_book.size - 1){
		strcpy(g_addr_book.person_info[num].name,
			g_addr_book.person_info[g_addr_book.size - 1].name);
		strcpy(g_addr_book.person_info[num].phone,
			g_addr_book.person_info[g_addr_book.size-1].phone);
	}
	--g_addr_book.size;
	printf("ɾ���ɹ�!\n");
	return;
}
void ModifyPersonInfo(){
	//�޸�ĳ���û���Ϣ,�û�����һ�������޸ĵı��,���ݱ�Ž����޸�
	printf("�޸�ĳ����¼\n");
	printf("������Ҫ�޸ĵ���Ϣ���:");
	int  num = 0;
	scanf("%d", &num);
	if (num < 0 || num >= g_addr_book.size){
		printf("����ı�Ų��Ϸ�,�޸�ʧ��!\n");
		return;
	}
	printf("�������µ��û���:");
	scanf("%s", g_addr_book.person_info[num].name);
	printf("�������µĵ绰����:");
	scanf("%s", g_addr_book.person_info[num].phone);
	printf("�޸ĳɹ�!\n");
}
void FindPersonInfo(){
	//�����û�������
	printf("���ҵ绰����!\n");
	printf("������Ҫ���ҵ�����: ");
	char name[1024] = { 0 };
	scanf("%s", name);
	int count = 0;
	for (int i = 0; i < g_addr_book.size; ++i){
		if (strcmp(name, g_addr_book.person_info[i].name) == 0){
			printf("�ҵ�һ�����,�绰����Ϊ:%s\n",
				g_addr_book.person_info[i].phone);
			++count;
		}
		if (count == 0){
			printf("δ�ҵ�ָ��������,�����²���\n");
		}
		else{
			printf("���ҳɹ�!�ҵ�%d�����!\n",g_addr_book.size);
		}
	}
}
void PrintPersonInfo(){
	//��ӡ���е��û���Ϣ
	printf("��ӡ���е��û���Ϣ!\n");
	for (int i = 0; i < g_addr_book.size; ++i){
		printf("[%d] %s %s\n",i, g_addr_book.person_info[i].name,
			g_addr_book.person_info[i].phone);
	}
	printf("��ӡ���! ����ӡ��%d����¼\n",g_addr_book.size);
	return;
}
void ClearPersonInfo(){
	printf("��������û���Ϣ!\n");
	printf("ȷ��ɾ��������Ϣ(y/n)\n");
	char input[1024] = { 0 };
	scanf("%s", input);
	if (strcmp(input, "y") != 0){
		printf("�Ѿ�ȡ��ɾ������!\n");
		return;
	}
	g_addr_book.size = 0;
	printf("����ɹ�!\n");
}
int main(){
	//1.�Ƚ���һ��ͨѶ¼�ı���,���Ҷ�����������г�ʼ��
	Init();
	while (1){
		//2.����ѭ��,��ӡһ���û��˵�,������ʾ�û����в���
		//��ɾ���
		int choice = Menu();
		//3.�û���������Ӧ�ı�ź�,�͵��ö�Ӧ�Ĳ�������,��ɻ�������
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