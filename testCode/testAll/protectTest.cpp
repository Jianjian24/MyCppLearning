#include <iostream>

class A
{
protected:
    int m_a;
    void sayA() { std::cout << "AAA\n"; }
};

class B : public A
{
public:
    int m_B;
};

int main()
{
    // A a;
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

    // getchar();
    return 0;
}