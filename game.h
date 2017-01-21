#define  __GAME_H__
#ifdef   __GAME_H__
#define _CRT_SECURE_NO_WARNINGS 1
#define  ROWS     10
#define  COLS     10
#define  MINE     30
#include <time.h>
void init_board(char arr[ROWS][COLS]);   //初始化棋盘
void print_board(char arr[ROWS][COLS]);  //打印雷棋盘 
void set_mines(char arr[ROWS][COLS]);    //设置雷

void print_board2(char arr[ROWS+2][COLS+2]);//打印显示棋盘
void mine_sweepe(char arr[ROWS][COLS],char mine[ROWS][COLS]);//扫雷

#endif __GAME_H__
