#include <stdio.h>

int main()
{
    int num = 0;
    char ch1[4];
    char ch2[30];

    scanf("%d", &num);

    printf("num is %d\n", num);

    scanf("%s", ch1);

    printf("%s\n", ch1);

    printf("num is %d\n", num);
    printf("%x\n", &num);
    printf("%x\n", ch1);
    printf("%x\n", ch1+1);
    printf("%x\n", ch1+2);
}