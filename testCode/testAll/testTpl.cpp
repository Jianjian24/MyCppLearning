#include "../../../jian.h"

template<typename T, T threshold>
bool lt2(T a) {return a < threshold;}

void f(int&) {cout << "f(int&)" << "\n";}
void f(int&&) {cout << "f(int&&)" << "\n";}

template<typename T>
void wrapper1(T a) {f(a);}

template<typename T>
void wrapper2(T &&a) {f(forward<T>(a))};


int main()
{
    double a{100.9};
    cout << lt2<int,2>(a);
    // lt2<double, double(2.1)>(a); // error:类型不匹配????搞不懂
    
    int x = 0;
    int &&rrx = move(x);


    return 0;
}