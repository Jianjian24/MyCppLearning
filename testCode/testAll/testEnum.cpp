#include <iostream>

class testEnum
{
public:
    testEnum() : b(1){};
    // int &num; // 引用必须初始化
    const int b; // 常量必须初始化，所以这两个东西都可以用初始化列表去初始化他
    int a = 1;
    // enum test
    // {
    //     Mon,
    //     Tue
    // };
    enum 
    {
        Tue,
        Mon
    };
};

int main()
{
    testEnum t1;
    std::cout << t1.Tue;

    return 0;
}