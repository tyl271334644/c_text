#include<stdint.h>
#include<stdlib.h>
#include<string.h>
int  Menu(){
	
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("请输入您的选择!: 0-1\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
#define MINE_COUNT 10
#define  ROW  9   //设置为宏后期可直接修改此处来改变地图大下
#define  COL   9
//使用二维数组来表示扫雷的地图,此处需要使用两个二维数组
//第一个二维数组表示地雷的雷阵
//第二个二维数组表示用户看到的地图
//扫雷的地图大小是9x9,但是我们准备把这个二维数组定义成11x11
//此时,我们的地图有效范围[1,ROW]和[1,COL]
//对于mine_map.使用'0'表示不是地雷,使用'1'表示地雷
char mine_map[ROW + 2][COL + 2];
//对于show_map使用'*'表示未打开的方块,对于打开的方块就用具体的数字表示
char show_map[ROW + 2][COL + 2];
void Init(char mine_map[ROW + 2][COL + 2], char show_map[ROW + 2][COL + 2]){
	//1.那数组进行初始化
	//对于mine_map,先把里面所有的元素都设置为'0'
	memset(mine_map,'0',(ROW+2)*(COL+2));
	//对于show_map,先把所有的元素都设置成'*'
	memset(show_map, '*', (ROW + 2)*(COL + 2));
	//2.随机布置雷阵
	srand(time(0)); //取随机种子
	int mine_count = MINE_COUNT;
	while (mine_count > 0){
		//在这个循环中随机设置地雷,没次设置完成一个地雷,mine_count--
		int row = rand()%9+1; //模9得到数字0-8
		int col = rand() % 9 + 1;
		if (mine_map[row][col] == '0'){
			mine_map[row][col] = '1'; 
			--mine_count;
		}
	}
}
void DisplayMap(char map[ROW+2][COL+2]){
	printf("    ");
	//打印第一行的内容 .列的坐标
	for (int col = 1; col <= COL; ++col){
		printf("%d ", col);
	}
	printf("\n");
	//打印具体的地图
	//打印第二行,地图的上边框
	for (int col = 1; col <= COL; ++col){
		printf("---");
	}
	printf("\n");
	//按行打印地图中的具体内容
	for (int row = 1; row <= ROW; ++row){
		//先打印行号
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
	show_map[row][col] = '0' + mine_count;   //为了使结果为字符型+'0'
	//需要统计row,col位置的元素周围有几个雷,并且把结果更新到show_map中
}
void Game(){
	//1.初始化地图(mine_map,show_map),布置雷阵
	int not_mine_count = 0;  //不是地雷的个数
	Init(mine_map, show_map);
	//2.先打印show_map
	DisplayMap(show_map);
	while (1){
		//3.提示用户进行输入坐标[1,ROW][1,COL]
		int row = 0;
		int col = 0;
		printf("请输入要翻开的方块坐标(row,col):");
		scanf("%d %d", &row, &col);
		//4.对用户输入的合法性进行判定,如果不合理提示用户重新输入
		if (row <= 0 || row > ROW || col <= 0 || col > COL){
			printf("输入不合法!请重新输入\n");
			continue;
		}
		//5.判定玩家当前是否踩雷,如果踩雷,游戏结束,并且打印
		if (mine_map[row][col] == '1'){
			printf("游戏结束!\n");
			DisplayMap(mine_map);
			break;
		}
		//6/如果没踩雷,判断玩家是否胜利(条件,已经翻开的方块数达到了  地图方块总数-地雷的个数)
		++not_mine_count;
		if (not_mine_count == ROW*COL - MINE_COUNT){
			printf("扫雷成功!\n");
			DisplayMap(mine_map);
			break;
		}
		//7.如果游戏没有胜利,就需要统计当前位置有几个雷,打印show_map,回到第三步
		UpdateShowMap(show_map,mine_map,row,col);
		DisplayMap(show_map);
	}
}
void Start(){
	while (1){
		int choice = Menu();
		if (choice == 0){
			printf("退出游戏!\n");
		}
		Game();
	}
}
int  main(){
	Start();
	system("pause");
	return  0;
}