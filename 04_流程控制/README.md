# 流程控制

## if-else

```C
int main(int argc, char const *argv[]) {
    if (){
        // ...
    }else if (){
        // ...
    }else{
        // ...
    }

    // 省略 {}
    if ()
        // ...
    else
        // ...

    return 0;
}
```

## switch

- 可以没有 default
- 表达式、表达式1、表达式2必须是整型表达式
- 表达式1、表达式2必须是常量表达式，不能带有变量

```C
#include <stdio.h>

int main(int argc, char const *argv[])
{
    switch ("表达式"){
        case "表达式1":
            // ...
            break;
        case "表达式2":
            // ...
            break;
        default:
            break;
    }

    int a = 10;
    switch(a){
        case 1:{
            int b = 25; // case 中声明变量，必须添加 {}
            printf("%d",b);
            break;
        }
        case 2:
            printf("2");
            break;
    }
    return 0;
}
```

## while

```C
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    while (i <= 10){
        printf("%d \n", i);
        i += 1;
    }

    return 0;
}
```

## for

```C
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    for (int i = 0; i <= 10; i++)
    {
        printf("%d", i);
    }
    return 0;
}
```

## do-while

```C
#include <stdio.h>

int main(int argc, char const *argv[])
{
    do
    {
        printf("直接执行,在判断");
    } while (0);

    return 0;
}
```

## goto

```C
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    code:
        printf("%d", n);
        n++;
        if (n <= 5)
            goto code; // 直接跳转到 code
    return 0;
}
```