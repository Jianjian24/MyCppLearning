#include "../../../jian.h"

struct testDelArea
{
    int a = 1;
    int b = 2;

    virtual ~testDelArea()
    {
        cout << "~testDelArea()" << endl;
    }
};

struct testDelArea2 : public testDelArea
{
    int c = 3;

    ~testDelArea2()
    {
        cout << "~testDelArea2()" << endl;
    }
};
struct testDelArea3 : public testDelArea
{
    int d = 4;

    ~testDelArea3()
    {
        cout << "~testDelArea3()" << endl;
    }
};

int main()
{
    std::vector<testDelArea2*> vecTmp;
    testDelArea* td2 = new testDelArea2();
    testDelArea* td3 = new testDelArea3();
    
    // td2->c = 10;
    // vecTmp.push_back(td2);

    // cout << "size testDelArea:" << sizeof(testDelArea) << endl;
    // cout << "size testDelArea2:" << sizeof(testDelArea2) << endl;

    // // 释放内存
    // for (auto it = vecTmp.begin(); it != vecTmp.end(); ++it)
    // {
    //     delete *it;
    // }

    delete td2;
    delete td3;

    return 0;

}