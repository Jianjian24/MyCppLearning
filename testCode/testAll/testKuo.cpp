// #include <stdio.h>
// // #include <unistd.h>
// #include <windows.h>

#define REGS_FOREACH(_) _(X) _(Y)
#define DECLEAR(X) int X; 

int main()
{
    REGS_FOREACH(DECLEAR)

    return 0;
}