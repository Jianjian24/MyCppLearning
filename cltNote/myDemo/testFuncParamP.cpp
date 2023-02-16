#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>

void info(char* sometext){
    cout << sometext << "\n";
}

void info(int num){
    cout << num << "\n";
}

void fun1(float rhs[3])
{
    for (size_t i = 0; i < 3; i++)
    {
        cout << rhs[i] << ' ';
    }
    cout << '\n';

    delete[] rhs;
}

float* fun2()
{
    float temp[3] = {0.f};
    temp[0] = 1.1;
    temp[1] = 2.f;
    temp[2] = 233.1;

    return temp;
}


int main()
{
    float *a = new float[3];
    // a[0] = 1.1;
    // a[1] = 2.f;
    // a[2] = 233.1;

    // fun1(a);

    a = fun2();
    
    for (size_t i = 0; i < 3; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}