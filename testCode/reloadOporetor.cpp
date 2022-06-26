#include <iostream>
using namespace std;

class Box
{
private:
    /* data */
    int length, heigh, width, vol;
public:
    Box();
    Box(int length, int heigh, int width){
        this->length = length;
        this->heigh = heigh;
        this->width = width;
    }

    int getvol(){
        vol = this->heigh * this->width * this->length ;
        return vol;
    }
    
    // 写一个关于运算符重载的demo
    // 两个Box 相加 其中长 宽 高 分别对应相加即可
    void operator+ (const Box& b1){
        this->length = this->length + b1.length;
        this->width = this->width + b1.width;
        this->heigh = this->heigh + b1.heigh;
    }
};

int main()
{
    Box b1(1, 2, 3);
    Box b2(2, 3, 4);
    cout << "The vol of b1 is: " << b1.getvol() << endl;
    cout << "The vol of b2 is: " << b2.getvol() << endl;
    b1 + b2;
    cout << "The vol of b1 is: " << b1.getvol() << endl;
    return 0;
}
