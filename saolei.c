#include<stdint.h>
#include<stdlib.h>
#include<string.h>
int  Menu(){
	
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("����������ѡ��!: 0-1\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
#define MINE_COUNT 10
#define  ROW  9   //����Ϊ����ڿ�ֱ���޸Ĵ˴����ı��ͼ����
#define  COL   9
//ʹ�ö�ά��������ʾɨ�׵ĵ�ͼ,�˴���Ҫʹ��������ά����
//��һ����ά�����ʾ���׵�����
//�ڶ�����ά�����ʾ�û������ĵ�ͼ
//ɨ�׵ĵ�ͼ��С��9x9,��������׼���������ά���鶨���11x11
//��ʱ,���ǵĵ�ͼ��Ч��Χ[1,ROW]��[1,COL]
//����mine_map.ʹ��'0'��ʾ���ǵ���,ʹ��'1'��ʾ����
char mine_map[ROW + 2][COL + 2];
//����show_mapʹ��'*'��ʾδ�򿪵ķ���,���ڴ򿪵ķ�����þ�������ֱ�ʾ
char show_map[ROW + 2][COL + 2];
void Init(char mine_map[ROW + 2][COL + 2], char show_map[ROW + 2][COL + 2]){
	//1.��������г�ʼ��
	//����mine_map,�Ȱ��������е�Ԫ�ض�����Ϊ'0'
	memset(mine_map,'0',(ROW+2)*(COL+2));
	//����show_map,�Ȱ����е�Ԫ�ض����ó�'*'
	memset(show_map, '*', (ROW + 2)*(COL + 2));
	//2.�����������
	srand(time(0)); //ȡ�������
	int mine_count = MINE_COUNT;
	while (mine_count > 0){
		//�����ѭ����������õ���,û���������һ������,mine_count--
		int row = rand()%9+1; //ģ9�õ�����0-8
		int col = rand() % 9 + 1;
		if (mine_map[row][col] == '0'){
			mine_map[row][col] = '1'; 
			--mine_count;
		}
	}
}
void DisplayMap(char map[ROW+2][COL+2]){
	printf("    ");
	//��ӡ��һ�е����� .�е�����
	for (int col = 1; col <= COL; ++col){
		printf("%d ", col);
	}
	printf("\n");
	//��ӡ����ĵ�ͼ
	//��ӡ�ڶ���,��ͼ���ϱ߿�
	for (int col = 1; col <= COL; ++col){
		printf("---");
	}
	printf("\n");
	//���д�ӡ��ͼ�еľ�������
	for (int row = 1; row <= ROW; ++row){
		//�ȴ�ӡ�к�
		printf("%02d| ",row);
		for (int col = 1; col <= COL; ++col){
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}
void  UpdateShowMap(char show_map[ROW + 2][COL + 2],char mine_map[ROW+2][COL+2]
,int row,int col	){
	int mine_count = 0;
	mine_count = (mine_map[row - 1][col - 1] - '0') +
		(mine_map[row - 1][col] - '0') +
		(mine_map[row - 1][col + 1] - '0') +
		(mine_map[row][col - 1] - '0') +
		(mine_map[row][col + 1] - '0') +
		(mine_map[row + 1][col - 1] - '0') +
		(mine_map[row + 1][col] - '0') +
		(mine_map[row + 1][col + 1] - '0');
	show_map[row][col] = '0' + mine_count;   //Ϊ��ʹ���Ϊ�ַ���+'0'
	//��Ҫͳ��row,colλ�õ�Ԫ����Χ�м�����,���Ұѽ�����µ�show_map��
}
void Game(){
	//1.��ʼ����ͼ(mine_map,show_map),��������
	int not_mine_count = 0;  //���ǵ��׵ĸ���
	Init(mine_map, show_map);
	//2.�ȴ�ӡshow_map
	DisplayMap(show_map);
	while (1){
		//3.��ʾ�û�������������[1,ROW][1,COL]
		int row = 0;
		int col = 0;
		printf("������Ҫ�����ķ�������(row,col):");
		scanf("%d %d", &row, &col);
		//4.���û�����ĺϷ��Խ����ж�,�����������ʾ�û���������
		if (row <= 0 || row > ROW || col <= 0 || col > COL){
			printf("���벻�Ϸ�!����������\n");
			continue;
		}
		//5.�ж���ҵ�ǰ�Ƿ����,�������,��Ϸ����,���Ҵ�ӡ
		if (mine_map[row][col] == '1'){
			printf("��Ϸ����!\n");
			DisplayMap(mine_map);
			break;
		}
		//6/���û����,�ж�����Ƿ�ʤ��(����,�Ѿ������ķ������ﵽ��  ��ͼ��������-���׵ĸ���)
		++not_mine_count;
		if (not_mine_count == ROW*COL - MINE_COUNT){
			printf("ɨ�׳ɹ�!\n");
			DisplayMap(mine_map);
			break;
		}
		//7.�����Ϸû��ʤ��,����Ҫͳ�Ƶ�ǰλ���м�����,��ӡshow_map,�ص�������
		UpdateShowMap(show_map,mine_map,row,col);
		DisplayMap(show_map);
	}
}
void Start(){
	while (1){
		int choice = Menu();
		if (choice == 0){
			printf("�˳���Ϸ!\n");
		}
		Game();
	}
}
int  main(){
	Start();
	system("pause");
	return  0;
}