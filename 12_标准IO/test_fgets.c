#include "stdio.h"
#include "stdlib.h"
int main() {
  // 按行读
  FILE *fp = fopen("test.txt", "r");
  if (fp == NULL) {
    printf("文件打开失败");
    return EXIT_FAILURE;
  }
  char buf[1024] = {0};
#if 0
  while (!feof(fp)){ // 文件没有结束
    char *ret = fgets(buf,sizeof(buf)-1,fp);
    if(ret==NULL){
        break;
    }
    // 把 \n 换成 \0;
    buf[strlen(buf)-1]= '\0';
    printf("%s \n",buf);
  }
#else
  // 优化
  while (fgets(buf, sizeof(buf) - 1, fp)) {
    buf[sizeof(buf) - 1] = '\0';
    printf("%s \n", buf);
  }
#endif

  fclose(fp);
  return EXIT_SUCCESS;
}