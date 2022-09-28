#include <iostream>
using namespace std;

class AD
{

};

class Data : public AD
{
public:
void fun1();
    int A;
    double B;
    double Bb;
};

int main()
{
    Data* ad = new Data;
    ad->A = 100;
    ad->B = 100;
    cout << sizeof(AD) << '\n';
    cout << sizeof(Data) << '\n';
    return 0;
}

//https://blog.csdn.net/longjialin93528/article/details/80160467