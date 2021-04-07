#include "stdio.h"
#include "stdlib.h"
#include "termios.h"
#include "signal.h"
#include <unistd.h>

void io() {
  int ch;
  struct termios new, old;
  tcgetattr(0, &old);
  tcgetattr(0, &new);
  new.c_lflag = new.c_lflag & ~(ICANON | ECHO); // 去掉回显
  new.c_cc[VMIN] = 1;
  new.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &new);
  while (1) {
    ch = getchar();
    if (ch == 'Q') { // 退出
      break;
    }
    printf("%x ", ch);
    fflush(NULL);
  }
  tcsetattr(0, TCSANOW, &old);
}

void AlarmHandler(int s) {
  alarm(1);
  printf("Get SIGALRM\n");
}

int main() {
  // draw_window();
//    signal(SIGALRM, alarm_handler);
//    alarm(1);
//    int ch;
//    while (1) {
//      ch = getchar();
//      printf("%x ", ch);
//    }
  io();
  return 0;
}