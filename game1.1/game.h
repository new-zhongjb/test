#define ROW 3
#define COL 3

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

void InitBoard(char board[ROW][COL], int row, int col);//������������game.c��ʵ��

void DisplayBoard(char board[ROW][COL], int row, int col);//��.c�ļ���ʵ��

void PlayerMove(char board[ROW][COL], int row, int col);//��.c�ļ���ʵ��,ͳһ��������ͷ�ļ���������.c�ļ�ʵ��

void ComputerMove(char board[ROW][COL], int row, int col);

//����������Ϸ������״̬�����Ӯ������Ӯ��ƽ�֡�������Ϸ��
//���Ӯ    '*'
//����Ӯ    '#'
//ƽ��      'Q'
//������Ϸ  'C'

char IsWin(char board[ROW][COL],int row,int col);