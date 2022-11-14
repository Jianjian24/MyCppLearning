#include <iostream>
using namespace std;

int main()
{
    double max = 0x7fffffffffffffff;
    cout << max << endl;
    max++;
    cout << max << endl;
    max+=9223372036854770000;
    cout << max << endl;
    max+=9223372036854770000;
    cout << max << endl;
    max+=9223372036854770000;
    cout << max << endl;
    max+=10*9223372036854770000;
    cout << max << endl;
}