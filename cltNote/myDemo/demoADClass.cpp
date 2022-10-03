#include <iostream>
using namespace std;

struct AD
{
    virtual ~AD(){}
};

struct Data : public AD
{
    int A;
    double B;
    double Bb;

    Data()
    {
        A = 100;
        B = 100.123;
    }
};

int main()
{
    AD* ad = new Data;
    void* value = new Data;
    // ad->A = 100;
    // ad->B = 100;
    cout << sizeof(AD) << '\n';
    cout << sizeof(Data) << '\n';    
    cout << ((Data*)value)->A << '\n';
    cout << ((Data*)value)->B << '\n';
    return 0;
}

//https://blog.csdn.net/longjialin93528/article/details/80160467