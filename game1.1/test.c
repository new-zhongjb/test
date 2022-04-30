#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>

#include "game.h"

void menu()
{
	printf("***************************************\n");
	printf("**********  1.play   0.exit ***********\n");
	printf("***************************************\n");
}

//������Ϸ���㷨ʵ��
void game()
{
	int ret = 0;
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
		//����
	while (1)
	{
		PlayerMove(board, ROW, COL);//�������
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board,ROW,COL);
		if (ret!='C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//ÿ��һ����ӡһ������
		ret=IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���ʤ��\n");
		printf("\n");
	}
	else if (ret == '#')
	{
		printf("����ʤ��\n");
		printf("\n");
	}
}


void test()
{
	int input = 0;
	do
	{
		menu();
		printf("���������֣�1��ʼ��Ϸ��0���˳���Ϸ:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������:>\n");
			break;
		}
	} while (input);

}


int main()
{
	test();
	return 0;
}