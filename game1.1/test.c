#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>//��Ϊtest.c��game.c��������game.h�����Կ��԰����ͷ�ļ��ŵ�game.h����

#include "game.h"
//�Լ�������ͷ�ļ�����˫����

//дһ����������Ϸ

void game()
{
	char ret = 0;//�����������iswin�ķ���ֵ
	//����һ����ά���飬��������߳���������Ϣ
	//char board[3][3] = { 0 };//����һ��3��3�е����顣����ֱ��д3���ã������Ż�������������Ǽ����Ǽ�����game.h�����к���
	char board[ROW][COL] = {0};//ȫ���ո�   //������game.h�����ݣ�Ҫ����ͷ�ļ�
	//��ʼ������
	InitBoard(board, ROW, COL);//�������Ϸ����ش���  //������һ������ô������һ����ʼ�������棬��ӡ�������ǿո����������һ������ʼ����ʲô��ӡ�����ľ���ʲô
	//��ӡ����
	//___|___|___      �������м䣬��ӡһ���ո����ӣ��ո񣻴�ӡһ���ո����ӣ��ո񣻴�ӡһ���ո����ӣ��ո�
	//___|___|___      һ�����С�1��3��5���������ӣ�2��4����Ϊ�ָ���
	//   |   |   
	DisplayBoard(board,ROW,COL);

	//����
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//ÿ��һ����ӡһ������
		//�ж���Ӯ
		ret=IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���ʤ��\n");
	}
	else if (ret == '#')
	{
		printf("����ʤ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}


void menu()//�˵���ʼ����   //����������ӿ�ʼ����
{
	printf("*********************************\n");
	printf("*****     1.play   0.exit   *****\n");
	printf("*********************************\n");
}


void test()//testֻ��Ҫִ�У�����Ҫ����ֵ��������void   //�ڶ�����дtest����
{
	int input = 0;
	srand((unsigned int)time(NULL));//Ҫ����ʹ��srandҪ��.h������ͷ�ļ�<stdlib.h><time.h>
	do
	{
		menu();//����Ϸ��һ����ʼ�˵�ҳ��
		printf("�������֣�1��ʼ��Ϸ��0�˳���Ϸ��������:>");
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
			printf("�����������������\n");
			break;
		}

	} while (input);

}


int main()//��һ������дһ��main����
{
	test();//�ú���ִ����Ϸ
	return 0;
}
