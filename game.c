#include <stdio.h>
#include "game.h"
#include <time.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 1
void init_board(char arr[ROWS+2][COLS+2])
{
	int rows = 0;
	int cols = 0;
	for (rows=0;rows<ROWS+2;rows++)
	{
		for (cols=0; cols<COLS+2; cols++)
		{
			arr[rows][cols] = arr[0][0];
		}
	}
}

void print_board(char arr[ROWS+2][COLS+2])
{
	int rows = 0;
	int cols = 0;
	printf("   ");                       //对其
	for (rows=1; rows<ROWS+1; rows++)    //输出行的标号
	{
		printf("%2d ",rows);
	}
	printf("\n");
	for (rows=1; rows<=ROWS; rows++)
	{
		printf("%2d ",rows);
		for (cols=1; cols<=COLS; cols++)
		{
			printf(" %c ",arr[rows][cols]);
		}
		printf("\n");
	}
}
void set_mines(char arr[ROWS+2][COLS+2])
{
	int cols = 0;
	int rows = 0;
	int count = MINE;
	srand((int)time(NULL));
	while(count)
	{
		rows = rand()%10+2;
		cols = rand()%10+2;
		rows--;
		cols--;
		if (arr[rows][cols] == '_')
		{
			arr[rows][cols] = '1';
			count--;
		}
	}
}
void mine_sweepe(char arr[ROWS+2][COLS+2],char mine[ROWS+2][COLS+2])
{
	int rows = 0;
	int cols = 0;
	printf("请输入坐标：>");
	scanf("%d%d",&rows,&cols);
	if (arr[rows][cols] == '1')           //第一次是雷
	{
		int rows1 = 0;
		int cols1 = 0;
		srand((unsigned)time(NULL));
		while (1)
		{
			rows1 = rand()%10+1;
		    cols1 = rand()%10+1;
			if (arr[rows1][cols1] == '_')
			{
				char tmp = arr[rows1][cols1];
				arr[rows1][cols1] = arr[rows][cols];
				arr[rows][cols] = tmp;
				break;
			}
		}
	}
	if (arr[rows][cols] != '1')
	{
		int count = 0;           //统计周围雷的个数
		int i = 0;
		int j = 0;                          
		for (j=cols-1; j<=cols+1; j++)
		{
			if (arr[rows-1][j] == '1')
			{
				count++;
				mine[rows-1][j] = '*';

			}
			if (arr[rows+1][j] == '1')
			{
				count++;
				mine[rows+1][j] = '*';
			}
		}
		if (arr[rows][cols-1] == '1' )
		{
			count++;
			mine[rows][cols-1] = '*';

		}
		if (arr[rows][cols+1] == '1' )
		{
			count++;
			mine[rows][cols+1] = '*';
		}
		
		mine[rows][cols] = count+'0';
		print_board(mine);              //打印第一次不是雷 周围雷的个数
		while (1)
		{
			int rows = 0;
			int cols = 0;
			printf("请输入坐标：>");
			scanf("%d%d",&rows,&cols);
			if (arr[rows][cols] == '1')
			{
				mine[rows][cols] = '*';
				print_board(mine);
				printf("很遗憾，你被炸死了！！！\n");
				break;
			}
			if (arr[rows][cols] == '_')
			{
				int count = 0;
				int i = 0;
				int j = 0;
				for (j=cols-1; j<=cols+1; j++)
				{
					if (arr[rows-1][j] == '1')
					{
						count++;
						mine[rows-1][j] = '*';

					}
					if (arr[rows+1][j] == '1')
					{
						count++;
						mine[rows+1][j] = '*';
					}
				}
				if (arr[rows][cols-1] == '1' )
				{
					count++;
					mine[rows][cols-1] = '*';

				}
				if (arr[rows][cols+1] == '1' )
				{
					count++;
					mine[rows][cols+1] = '*';
				}
				mine[rows][cols] = count+'0';
				print_board(mine);
			}
		}
	}
}