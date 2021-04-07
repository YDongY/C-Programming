#ifndef CDEV_PEOJECT_SNAKE_SNAKE_H_
#define CDEV_PEOJECT_SNAKE_SNAKE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <signal.h>
#include <unistd.h>

#define WIDE 60
#define HIGH 20

struct Food {
  int x;
  int y;
} food;

struct Body {
  int x;
  int y;
};

struct Snake {
  struct Body body[WIDE * HIGH];
  int size;
} snake;

int score = 0;

// 默认向右移动
int kx = 1;
int ky = 0;

int lastX = 0;
int lastY = 0;

// 声明函数
void InitSnake(void);
void InitFood(void);
void InitUi(void);

void ShowFood();
void ShowSnake();
void ShowFrame();

void AlarmHandler(int s);
void SnakeMove();

#endif