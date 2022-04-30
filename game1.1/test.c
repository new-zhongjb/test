#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>

#include "game.h"

void menu()
{
	printf("***************************************\n");
	printf("**********  1.play   0.exit ***********\n");
	printf("***************************************\n");
}

//整个游戏的算法实现
void game()
{
	int ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
		//下棋
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家下棋
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board,ROW,COL);
		if (ret!='C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//每走一步打印一次棋盘
		ret=IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家胜利\n");
		printf("\n");
	}
	else if (ret == '#')
	{
		printf("电脑胜利\n");
		printf("\n");
	}
}


void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入数字：1则开始游戏，0则退出游戏:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入:>\n");
			break;
		}
	} while (input);

}


int main()
{
	test();
	return 0;
}