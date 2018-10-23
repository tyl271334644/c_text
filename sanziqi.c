#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//������ĳ��ȶ���Ϊ��,������ڶԳ��������չ
//ֱ���޸ĺ궨�弴��
#define  ROW   3
#define   COL    3
//1.�����ά�����ʾ����
char  g_chess_board[ROW][COL];
void Init(){
	//�����̽��г�ʼ��
	for (int  row= 0; row< ROW; ++row){
		for (int col = 0; col < COL; ++col){
			g_chess_board[row][col] = ' ';
		}
	}
}
void  Print(){
	//��ӡ����
	for (int row = 0; row < ROW; ++row){
		printf("| %c | %c | %c |\n",g_chess_board[row][0],
			g_chess_board[row][1],g_chess_board[row][2]);
		if (row != ROW - 1){
			//�������һ�л����һ���߽�
			printf("|---|---|---|\n");
		}
	}
}
void PlayerMove()
{
	while (1){
		//�������
		//1.��ʾ�������һ������
		printf("���������(��������): ");
		//2.��ȡ��ҵ�����
		int row = -1;
		int col = -1;
		scanf("%d %d", &row, &col);
		//3.����ҵ��������У��(��ԶҲ��Ҫ�����û�������)
		//��У�������Ƿ��Ǻ���Χ
		//���������������Ӧλ���Ƿ��Ѿ�����
		//4.����������Ƿ�,��ѭ����ʾ�û���������
		if (row < 0 || row >= ROW || col < 0 || col >= COL){
			printf("���������Ƿ�,����������!\n");
			continue;
		}
		if (g_chess_board[row][col] != ' '){
			//��ǰλ���Ѿ���ռ����
			printf("��ǰλ���Ѿ�������,����������!\n");
			continue;
		}

		g_chess_board[row][col] = 'x';
		break;
		//5.����������Ϸ�,�Ͱ������ϵĶ�Ӧλ������Ϊ'x'

	}
}
void ComputerMove(){
	//��������,������Ե,�����������һ����,�������һ����
	//�����ǰ�к����Ѿ���ռ��,���ڲ���һ��
	printf("���������!\n");
	int row = 0;
	int col = 0;
	while (1){
		row = rand() % ROW; 
		col = rand() % COL;
		if (g_chess_board[row][col] == ' '){
			g_chess_board[row][col] = '0';
			break;
		}

	}

}
//ʹ��X��ʾ���.,ʹ��O��ʾ����
//Լ��CheckWinner��������X��ʾ���ʤ��
//�������O��ʾ����ʤ��,����Q��ʾ����
//������ؿո��ʾʤ��δ��
int IsFull(){
	//���˷���,û������0
	for (int row = 0; row < ROW; ++row){
		for (int col = 0; col < COL; ++col){
			if (g_chess_board[row][col] == ' '){
				return 0;
			}
		}
	}
	return 1;
}
char  CheckWinner(){
	//�����Ϸ�Ƿ����
	//1.�ȼ�������п��ǲ�������������һ��
	for (int row = 0; row < ROW; ++row){
		if (g_chess_board[row][0] == g_chess_board[row][1]
			&& g_chess_board[row][0] == g_chess_board[row][2]
			&& g_chess_board[row][0] != ' '){
			return g_chess_board[row][0];
		}
	}
	//2.�ټ�����е����ǲ�������һ��
	for (int col = 0; col < COL; ++col){
		if (g_chess_board[0][col] == g_chess_board[1][col]
			&& g_chess_board[0][col] == g_chess_board[2][col]
			&& g_chess_board[0][col] != ' '){

			return g_chess_board[0][col];
		}
	}
	//3.���Խ���
	if (g_chess_board[0][0] == g_chess_board[1][1]
		&& g_chess_board[0][0 == g_chess_board[2][2]]
		&& g_chess_board[0][0] != ' '){
		return g_chess_board[0][0];
	}
	if (g_chess_board[2][0] == g_chess_board[1][1]
		&& g_chess_board[2][0] == g_chess_board[0][2]
		&& g_chess_board[2][0] != ' '){
		return g_chess_board[2][0];
	}
	//4.����Ƿ����
	if (IsFull()){
		return  'q';
	}
	return  ' ';
}
int main(){
	char winner = ' ';
	Init();
	while (1){
		Print();
		PlayerMove();
		winner = CheckWinner();
		if (winner != ' '){
			//��Ϸ����
			break;
		}
		ComputerMove();
		winner = CheckWinner();
		if (winner != ' '){
			//��Ϸ����
			break;
		}
	}
	if (winner == 'x'){
		printf("��һ�ʤ!\n");
	}else if (winner == 'o'){
		printf("���Ի�ʤ!\n");
	}else if (winner == 'q'){
		printf("����!\n");
	}
	system("pause");
	return 0;
}