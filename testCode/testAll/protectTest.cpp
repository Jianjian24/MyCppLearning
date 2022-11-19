#include <iostream>
using namespace std;
class A
{
public:
    A()
    {
        cout << "A construct\n";
    }
    virtual ~A()
    {
        cout << "A delete\n";
    }
protected:
    int m_a;
    void sayA() { std::cout << "AAA\n"; }
};

class B : public A
{
public:
    B()
    {
        cout << "B construct\n";
    }
    int m_B;
    ~B()
    {
        cout << "B delete\n";
    }
};

int main()
{
    A a;
    B b;
    // A::sayA(); // 只能在类内访问哇！！
    int *arr;
    arr = new int[10 + 1];
    arr[10] = 0;
    // int arr[10] = {1,1,1,1,1,1,1,1,1,1};
    // for (auto it : arr)
    // {
    //     std::cout << it << " " ;
    // }
    std::cout << arr[10] << " " ;
    bool flag = true;
    flag = ~flag;
    std::cout << (~flag) << " " ;
    // A *pb = new B;
    // delete pb;
    // getchar();
    return 0;
}