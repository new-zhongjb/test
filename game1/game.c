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