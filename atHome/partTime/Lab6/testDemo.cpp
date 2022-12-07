#include <iostream>
using namespace std;

//指针常量 &
void test(int* num)
{
    *num = 9;
}

int main()
{
    int num = 1;
    cout << num << '\n';
    test(&num);
    cout << num << '\n';
    
    return 0;
}