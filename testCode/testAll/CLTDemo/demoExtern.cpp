#include<stdio.h>
// #include "demoEx.cpp"
void func();
int main()
{
    func(); //1
    extern int num;
    printf("%d",num); //2
    return 0;
}

// int num = 3;
// void func()
// {
//     printf("%d\n",num);
// }