#include "stdlib.h"
#include "stdio.h"

void draw_window() {
  int left = 10;
  int top = 5;
  int width = 30;
  int height = 20;
  char *color = "[45";
  char *world = "  ";

  printf("\033[2J"); // 清屏

  // 上
  for (int i = 0; i <= width; i++) {
    printf("\033[%d;%dH\033%sm%s\n", top, i + left, color, world);
  }

  // 左
  for (int i = 0; i <= height; ++i) {
    printf("\033[%d;%dH\033%sm%s\n", i + top, left, color, world);
  }

  // 右
  for (int i = 0; i <= height; i++) {
    printf("\033[%d;%dH\033%sm%s\n", i + top, left + width, color, world);
  }

  // 下
  for (int i = 0; i <= width; i++) {
    printf("\033[%d;%dH\033%sm%s\n", top + height, i + left, color, world);
  }

  printf("\033[0m");
}

void draw_square() {
  int width = 30;
  int height = 20;
  char *color = "[45";
  char *world = "  ";

  char square[4][4];


}

int main() {
  draw_window();
  return 0;
}