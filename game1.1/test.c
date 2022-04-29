#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>//因为test.c和game.c都引用了game.h，所以可以把这个头文件放到game.h里面

#include "game.h"
//自己创建的头文件，用双引号

//写一个三子棋游戏

void game()
{
	char ret = 0;//创建数组接收iswin的返回值
	//创建一个二维数组，用来存放走出的棋盘信息
	//char board[3][3] = { 0 };//创建一个3行3列的数组。但是直接写3不好，可以优化，变成想让它是几就是几。在game.h定义行和列
	char board[ROW][COL] = {0};//全部空格   //引用了game.h的内容，要加上头文件
	//初始化棋盘
	InitBoard(board, ROW, COL);//这个是游戏的相关代码  //加上这一步，那么不管上一步初始化是上面，打印出来都是空格，如果屏蔽这一步，初始化是什么打印出来的就是什么
	//打印棋盘
	//___|___|___      落子在中间，打印一个空格，落子，空格；打印一个空格，落子，空格；打印一个空格，落子，空格；
	//___|___|___      一共五行。1，3，5行用来落子，2，4行作为分割线
	//   |   |   
	DisplayBoard(board,ROW,COL);

	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//每走一步打印一次棋盘
		//判断输赢
		ret=IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
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
		printf("玩家胜利\n");
	}
	else if (ret == '#')
	{
		printf("电脑胜利\n");
	}
	else
	{
		printf("平局\n");
	}
}


void menu()//菜单开始界面   //第三步，添加开始界面
{
	printf("*********************************\n");
	printf("*****     1.play   0.exit   *****\n");
	printf("*********************************\n");
}


void test()//test只需要执行，不需要返回值，所以用void   //第二步，写test函数
{
	int input = 0;
	srand((unsigned int)time(NULL));//要正常使用srand要在.h中引用头文件<stdlib.h><time.h>
	do
	{
		menu();//给游戏加一个开始菜单页面
		printf("输入数字：1则开始游戏，0退出游戏。请输入:>");
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
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (input);

}


int main()//第一步，先写一个main函数
{
	test();//用函数执行游戏
	return 0;
}
