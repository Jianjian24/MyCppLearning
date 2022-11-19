// #include "../../../jian.h"
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
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


    string A("abc");
    string&& Rval = std::move(A); // && 代表右值引用，但是Rval只是标记了一个右值，实际上他是一个即将销毁的左值（草稿纸） move以A为模板 生成一个右值给Rval,此时A被标记为草稿纸
    string B(Rval);    // this is a copy , not move.
    cout << A << " 1" << endl;   // output "abc"
    cout << &A << " 1locate" << endl;   // output "abc"
    cout << Rval << " 1Rval" << endl;       /* output "" */
    string C(std::forward<string>(Rval));  // move.
    cout << A << " 2" << endl;       /* output "" */
    cout << Rval << " 2Rval" << endl;       /* output "" */
    cout << C << " 2C" << endl;       /* output "" */
    cout << &A << " 2locate" << endl;       /* output "" */

    return 0;
}