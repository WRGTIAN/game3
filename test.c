#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
void menu()
{
	printf("**************************************************\n");
	printf("*******     1.PLAY         2.EXIT    *************\n");
	printf("**************************************************\n");
}
int main()
{
	int input = 0;
	char arr[ROWS+2][COLS+2] = {'_'};        //雷的位置
	char mine[ROWS+2][COLS+2] = {'_'};       //展示
	do 
	{
		menu();
		printf("请选择：>");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			init_board(arr);               
			init_board(mine);              
			set_mines(arr);
			print_board(arr);
			print_board(mine);
			mine_sweepe(arr,mine);
			break;
		case 0:
			break;
		}

	} while (input);
	return 0;
}
