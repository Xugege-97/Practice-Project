#define _CRT_SECURE_NO_WARNINGS 1 
#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//空格
		}
	}
}

//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	//三行三列的  其实无非是：
//	// _%s_|_%s_|_%s_
//	// _%s_|_%s_|_%s_
//	//  %s | %s | %s 
//		int i = 0;
//		for (i = 0; i < row; i++)
//		{
//			//打印数据
//			printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//			//打印分割行
//			if (i<row-1)  //最后一行不打印
//			   printf("---|---|---\n");
//		}
//}              /*若是改变行列数，这个方法就很死板了*/
//              /*优化一下程序，使它具有更好的可扩展性*/
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	//打印数据
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)//一行打印几个数据，取决于有几列
		{
			printf(" %c ", board[i][j]);
			if (j < col-1)
				printf("|");
		}
		printf("\n");
		//打印分割行
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}	
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋:>\n");

	while (1)
	{
		printf("请输入一个坐标:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断坐标范围
		{
			if (board[x-1][y-1] != ' ') //实际数学坐标 和 数组下标 不一样
			{
				printf("坐标被占用，请重新输入！\n");
			}
			else
			{
				board[x-1][y-1] = '*'; //实际数学坐标 和 数组下标 不一样
				break;
			}
		}
		else
		{
			printf("坐标非法，请重新输入！\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋:>\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
} 

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char CheckWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	//三列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//平局
	if (IsFull(board,row,col) == 1)//不用ROW,COL，因为这里已经有了row,col的参数
	{
		return 'Q';
	}
	//继续游戏  //前面没有赢，没有平局
	return 'C';
}