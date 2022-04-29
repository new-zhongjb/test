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

//void DisplayBoard(char board[ROW][COL], int row, int col)//����д�Ƚϴ죬��Ϊ�п��Ա仯������ȴ�ǹ̶�������
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//��ӡһ������
//		printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
//		if(i<row-1)
//		//��ӡһ�зָ���
//		printf("___|___|___\n");//ִ�к��ֶ���һ���ָ��ߣ����Լ���һ�������������if
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
			//��ӡһ�е�����
			printf(" %c ", board[i][j]);
			if (j < row - 1)
				printf("|");
		}
		printf("\n");
		//��ӡ�ָ���
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
	int x = 0;//��x,y��ʾ��������
	int y = 0;
	printf("�����:>\n");
	while (1)
	{
		printf("������Ҫ�µ�����:>");
		scanf("%d%d", &x, &y);//ע����������֮��Ҫ�ո񣬲�Ȼ�ᵱ��һ����λ�����ж�����Ƿ�
		//�ж�����ĺϷ��ԣ���Ϊ��������ֵ���ܳ������̷�Χ
		if (x >= 1 && x <= row && y >= 1 && y <= col)//��Ȼ����������Ǵ�0��ʼ������Ϊ�˷���������ʹ�ã�����xy��ֵ����Ϊ1--3��
		{
			if (board[x - 1][y - 1] == ' ')//��˼���жϸ������Ƿ�ռ�ã�x-1;y-1������ԭ����λ�ã���Ϊ�����Ǵ�0��ʼ
			{
				board[x - 1][y - 1] = '*';
				break;//���û��break���ͻ�һֱѭ��
			}
			else
			{
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������!\n");
		}
	}


}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;//���ɵ���Ҫ�ߵ�����
	printf("������:\n");
	while(1)
	{
		x = rand() % row;//rand()���������,ģ���о��������ȡrow֮�ڵ���
		y = rand() % col;//��rand֮ǰҪ�ȵ���srand
			//xy�������ںϷ���Χ�����Բ������ж��Ƿ�Ϸ�������Ҫ�ж��Ƿ��ѱ�ռ��
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}//д������Ϳ��������һ��������һ���ˣ����ǻ�û���ж���Ӯ

//����1��ʾ��������
//����0��ʾ����û��
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
				return 0;//û��
			}
		}
	}
	return 1;//����
}



char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//��3��
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}

	}
	for (i = 0; i < col; i++)//��3��
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];//���������κ�һ������
		}
	}
	//�����Խ����ж�
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	//�ж��Ƿ�ƽ��
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}