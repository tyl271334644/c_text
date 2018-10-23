#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//对数组的长度定义为宏,方便后期对程序进行扩展
//直接修改宏定义即可
#define  ROW   3
#define   COL    3
//1.定义二维数组表示棋盘
char  g_chess_board[ROW][COL];
void Init(){
	//对棋盘进行初始化
	for (int  row= 0; row< ROW; ++row){
		for (int col = 0; col < COL; ++col){
			g_chess_board[row][col] = ' ';
		}
	}
}
void  Print(){
	//打印棋盘
	for (int row = 0; row < ROW; ++row){
		printf("| %c | %c | %c |\n",g_chess_board[row][0],
			g_chess_board[row][1],g_chess_board[row][2]);
		if (row != ROW - 1){
			//避免最后一行还输出一个边界
			printf("|---|---|---|\n");
		}
	}
}
void PlayerMove()
{
	while (1){
		//玩家落子
		//1.提示玩家输入一个坐标
		printf("请玩家落子(输入坐标): ");
		//2.读取玩家的输入
		int row = -1;
		int col = -1;
		scanf("%d %d", &row, &col);
		//3.对玩家的输入进行校验(永远也不要相信用户的输入)
		//①校验坐标是否是合理范围
		//②玩家输入的坐标对应位置是否已经有子
		//4.如果玩家输入非法,就循环提示用户重新输入
		if (row < 0 || row >= ROW || col < 0 || col >= COL){
			printf("输入的坐标非法,请重新输入!\n");
			continue;
		}
		if (g_chess_board[row][col] != ' '){
			//当前位置已经被占用了
			printf("当前位置已经有子了,请重新输入!\n");
			continue;
		}

		g_chess_board[row][col] = 'x';
		break;
		//5.如果玩家输入合法,就把棋盘上的对应位置设置为'x'

	}
}
void ComputerMove(){
	//电脑落子,落子随缘,靠随机数产生一个行,随机产生一个列
	//如果当前行和列已经被占用,就在产生一次
	printf("请电脑落子!\n");
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
//使用X表示玩家.,使用O表示电脑
//约定CheckWinner函数返回X表示玩家胜利
//如果返回O表示电脑胜利,返回Q表示和棋
//如果返回空格表示胜负未分
int IsFull(){
	//满了返回,没满返回0
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
	//检测游戏是否结束
	//1.先检查所有行看是不是三个子连在一起
	for (int row = 0; row < ROW; ++row){
		if (g_chess_board[row][0] == g_chess_board[row][1]
			&& g_chess_board[row][0] == g_chess_board[row][2]
			&& g_chess_board[row][0] != ' '){
			return g_chess_board[row][0];
		}
	}
	//2.再检查所有的列是不是连在一起
	for (int col = 0; col < COL; ++col){
		if (g_chess_board[0][col] == g_chess_board[1][col]
			&& g_chess_board[0][col] == g_chess_board[2][col]
			&& g_chess_board[0][col] != ' '){

			return g_chess_board[0][col];
		}
	}
	//3.检查对角线
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
	//4.检查是否和棋
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
			//游戏结束
			break;
		}
		ComputerMove();
		winner = CheckWinner();
		if (winner != ' '){
			//游戏结束
			break;
		}
	}
	if (winner == 'x'){
		printf("玩家获胜!\n");
	}else if (winner == 'o'){
		printf("电脑获胜!\n");
	}else if (winner == 'q'){
		printf("和棋!\n");
	}
	system("pause");
	return 0;
}