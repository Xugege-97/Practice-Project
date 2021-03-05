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
			board[i][j] = ' ';//�ո�
		}
	}
}

//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	//�������е�  ��ʵ�޷��ǣ�
//	// _%s_|_%s_|_%s_
//	// _%s_|_%s_|_%s_
//	//  %s | %s | %s 
//		int i = 0;
//		for (i = 0; i < row; i++)
//		{
//			//��ӡ����
//			printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//			//��ӡ�ָ���
//			if (i<row-1)  //���һ�в���ӡ
//			   printf("---|---|---\n");
//		}
//}              /*���Ǹı�����������������ͺ�������*/
//              /*�Ż�һ�³���ʹ�����и��õĿ���չ��*/
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	//��ӡ����
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)//һ�д�ӡ�������ݣ�ȡ�����м���
		{
			printf(" %c ", board[i][j]);
			if (j < col-1)
				printf("|");
		}
		printf("\n");
		//��ӡ�ָ���
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
	printf("�������:>\n");

	while (1)
	{
		printf("������һ������:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж����귶Χ
		{
			if (board[x-1][y-1] != ' ') //ʵ����ѧ���� �� �����±� ��һ��
			{
				printf("���걻ռ�ã����������룡\n");
			}
			else
			{
				board[x-1][y-1] = '*'; //ʵ����ѧ���� �� �����±� ��һ��
				break;
			}
		}
		else
		{
			printf("����Ƿ������������룡\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("��������:>\n");
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
	//����
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	//����
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//ƽ��
	if (IsFull(board,row,col) == 1)//����ROW,COL����Ϊ�����Ѿ�����row,col�Ĳ���
	{
		return 'Q';
	}
	//������Ϸ  //ǰ��û��Ӯ��û��ƽ��
	return 'C';
}