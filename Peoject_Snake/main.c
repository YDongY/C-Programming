#include "snake.h"

/**
 * 初始化蛇坐标
 */
void InitSnake(void) {
  snake.size = 2;

  snake.body[0].x = (WIDE + 1) / 2;
  snake.body[0].y = HIGH / 2;

  snake.body[1].x = (WIDE + 1) / 2 - 1;
  snake.body[1].y = HIGH / 2;
}

/**
 * 初始化食物坐标（随机）
 */
void InitFood(void) {
  food.x = rand() % (WIDE - 2) + 2;
  food.y = rand() % (HIGH - 2) + 2;
}

/**
 * 显示分数面板
 */
void ShowScorePanel() {
  // 分数面板
  printf("\033[%d;%dH\033[36mScore:%d\n", HIGH / 2, WIDE + 10, score);
}

/**
 * 显示食物
 */
void ShowFood() {
  // 画食物
  printf("\033[%d;%dH\033[36m#\n", food.y, food.x);
}

/**
 * 显示蛇
 */
void ShowSnake() {
  // 画蛇
  for (int i = 0; i < snake.size; ++i) {
    if (i == 0) {
      // 画蛇头
      printf("\033[%d;%dH\033[35m@\n", snake.body[i].y, snake.body[i].x);
    } else {
      // 画蛇身
      printf("\033[%d;%dH\033[37m*\n", snake.body[i].y, snake.body[i].x);
    }
  }
}

/**
 * 显示边界框
 */
void ShowFrame() {
  char *color = "42";
  char *world = "  ";
  // 上
  for (int i = 0; i <= WIDE; i++) {
    printf("\033[%d;%dH\033[%sm%s\n", 0, i, color, world);
  }

  // 左
  for (int i = 0; i <= HIGH; ++i) {
    printf("\033[%d;%dH\033[%sm%s\n", i, 0, color, world);
  }

  // 右
  for (int i = 0; i <= HIGH; i++) {
    printf("\033[%d;%dH\033[%sm%s\n", i, WIDE, color, world);
  }

  // 下
  for (int i = 0; i <= WIDE; i++) {
    printf("\033[%d;%dH\033[%sm%s\n", HIGH, i, color, world);
  }
}

/**
 * 初始化界面
 */
void InitUi() {
  printf("\033[2J"); // 清屏
  ShowScorePanel();
  ShowFood();
  ShowSnake();
  ShowFrame();
  printf("\033[0m");
}

/**
 * 蛇移动
 */
void SnakeMove() {
  // 蛇头碰壁
  if (snake.body[0].x <= 2 || snake.body[0].x > WIDE - 1
      || snake.body[0].y <= 1 || snake.body[0].y > HIGH - 1) {
    printf("蛇头碰壁 Game Over\n");
    alarm(0); // 取消时钟
    exit(1);// 游戏结束
  }
  // 蛇头和蛇身碰撞
  for (int i = 1; i < snake.size; ++i) {
    if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
      printf("蛇头和蛇身碰撞 Game Over\n");
      alarm(0); // 取消时钟
      exit(1); // 游戏结束
    }
  }
  // 蛇头和食物碰撞
  if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
    InitFood();   // 食物消失
    // ShowFood();
    snake.size++; // 蛇身增长
    score += 10;
  }

  // 获取蛇尾
  // lastX = snake.body[snake.size - 1].x;
  // lastY = snake.body[snake.size - 1].y;

  // 蛇移动
  for (int i = snake.size - 1; i > 0; i--) {
    snake.body[i].x = snake.body[i - 1].x;
    snake.body[i].y = snake.body[i - 1].y;
  }
  snake.body[0].x = snake.body[0].x + kx;
  snake.body[0].y = snake.body[0].y + ky;

  InitUi(); // 因为是全屏刷新，此方法效率低
  //  ShowSnake(); // 仅刷新蛇的图形
  //  printf("\033[%d;%dH\033[35m \n", lastY, lastX); // 将蛇尾最后的图案设置为空
}

/**
 * 信号 1s 触发一次界面刷新
 * @param s
 */
void AlarmHandler(int s) {
  alarm(1);
  SnakeMove();
}

/**
 * 游戏开始
 */
void PlayGame() {
  signal(SIGALRM, AlarmHandler);
  alarm(1);

  int key;
  struct termios new, old;
  tcgetattr(0, &old);
  tcgetattr(0, &new);
  new.c_lflag = new.c_lflag & ~(ICANON | ECHO); // 去掉回显
  new.c_cc[VMIN] = 1;
  new.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &new);
  while (1) {
    key = getchar();
    // printf("%c", key);
    switch (key) {
      case 'w':kx = 0;
        ky = -1;
        break;
      case 's':kx = 0;
        ky = 1;
        break;
      case 'a':kx = -1;
        ky = 0;
        break;
      case 'd':kx = 1;
        ky = 0;
        break;
      case 'Q':tcsetattr(0, TCSANOW, &old);
        return;
      default:printf("无效");
    }
    fflush(NULL);
    // 蛇移动
    SnakeMove();
  }

}

int main() {
  srand(time(NULL));

  InitSnake(); // 初始化蛇
  InitFood();  // 初始化食物
  InitUi();    // 初始化界面

  PlayGame();  // 启动游戏

  printf("Game Over!\n");

  return EXIT_SUCCESS;
}