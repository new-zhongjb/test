#define _CRT_SECURE_NO_WARNINGS



#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';

		}
	}
}

//void DisplayBoard(char board[ROW][COL], int row, int col)//这样写比较挫，因为行可以变化，而列却是固定的三列
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//打印一行数据
//		printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
//		if(i<row-1)
//		//打印一行分割线
//		printf("___|___|___\n");//执行后发现多了一条分割线，所以加上一个条件，上面的if
//	}
//}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//打印一行的数据
			printf(" %c ", board[i][j]);
			if (j < row - 1)
				printf("|");
		}
		printf("\n");
		//打印分割行
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("___");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}

	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;//用x,y表示棋子坐标
	int y = 0;
	printf("玩家走:>\n");
	while (1)
	{
		printf("请输入要下的坐标:>");
		scanf("%d%d", &x, &y);//注意两个坐标之间要空格，不然会当成一个两位数，判断坐标非法
		//判断坐标的合法性，因为玩家输入的值可能超过棋盘范围
		if (x >= 1 && x <= row && y >= 1 && y <= col)//虽然数组的坐标是从0开始，但是为了方便正常人使用，输入xy的值设置为1--3；
		{
			if (board[x - 1][y - 1] == ' ')//意思是判断该坐标是否被占用，x-1;y-1是数组原本的位置，因为数组是从0开始
			{
				board[x - 1][y - 1] = '*';
				break;//如果没有break，就会一直循环
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入!\n");
		}
	}


}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;//生成电脑要走的坐标
	printf("电脑走:\n");
	while(1)
	{
		x = rand() % row;//rand()生成随机数,模上行就是随机数取row之内的数
		y = rand() % col;//用rand之前要先调用srand
			//xy的坐标在合法范围，所以不用在判断是否合法，但是要判断是否已被占用
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}//写到这里就可以玩家走一步电脑走一步了，但是还没有判断输赢

//返回1表示棋盘满了
//返回0表示棋盘没满
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//没满
			}
		}
	}
	return 1;//满了
}



char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//横3行
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}

	}
	for (i = 0; i < col; i++)//竖3列
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];//返回其中任何一个数字
		}
	}
	//两个对角线判断
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	//判断是否平局
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}