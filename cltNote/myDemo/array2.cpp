#include <iostream>
using namespace std;

struct myStruct
{
    int a;
    int b;
    void setA(int& num)
    {
        a = num;
    }
};



int main()
{
    myStruct ss[10][2];
    int *a = new int[10];
    a[2] = 10;


    cout << ss[1][2].a <<'\n';
    cout << *(a + 2) <<'\n';
}
