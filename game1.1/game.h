#define ROW 3
#define COL 3

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

void InitBoard(char board[ROW][COL], int row, int col);//函数声明，在game.c中实现

void DisplayBoard(char board[ROW][COL], int row, int col);//在.c文件中实现

void PlayerMove(char board[ROW][COL], int row, int col);//在.c文件中实现,统一步骤先在头文件声明再在.c文件实现

void ComputerMove(char board[ROW][COL], int row, int col);

//告诉我们游戏的四种状态（玩家赢、电脑赢、平局、继续游戏）
//玩家赢    '*'
//电脑赢    '#'
//平局      'Q'
//继续游戏  'C'

char IsWin(char board[ROW][COL],int row,int col);