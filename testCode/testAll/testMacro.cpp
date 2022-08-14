//状态机
#include <stdio.h>
#include <windows.h>

#define REGS_FOREACH(_) _(X) _(Y) //将传入的宏定义里面的变量用X。Y代替
#define RUN_LOGIC   X1 = !X && Y;\
                    Y1 = !X && !Y;
#define DEFINE(X)   static int X, X##1;
#define UPDATE(X)   X = X##1;
#define PRINT(X)    printf(#X " = %d;", X);

int main()
{
    REGS_FOREACH(DEFINE)
    while (1)   // clock
    {
        RUN_LOGIC;
        REGS_FOREACH(PRINT)
        REGS_FOREACH(UPDATE)
        putchar('\n');
        Sleep(1);
    }

    return 0;
}