// #include "../../../jian.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
// 用于判断传入的参数是左值还是右值的print()函数
template<typename T>
void print(T& t){
    cout << "lvalue" << endl;
}
template<typename T>
void print(T&& t){
    cout << "rvalue" << endl;
}

template<typename T>
void TestForward(T &&v){
    print(v);
    print(std::forward<T>(v));
    print(std::move(v));
}

int main(){
    TestForward(1);
    cout << "TestForward(1);" << "\n";

    int x = 1;
    print(x);
    TestForward(x);
    cout << "TestForward(x);" << "\n";

    TestForward(std::forward<int>(x));
    cout << "TestForward(std::forward<int>(x));" << "\n";

    return 0;
}