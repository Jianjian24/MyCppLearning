#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test_rand(void)
    {
    unsigned long n;
    srand((unsigned)time(NULL));
    for(int i = 0; i < 100; i++)
    {
        n = rand();
        printf("%d\n", n);
        // nullptr_t
    }
}

int main()
{
    test_rand();
    return 0;
}