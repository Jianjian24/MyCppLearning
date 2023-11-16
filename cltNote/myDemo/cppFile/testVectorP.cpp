#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class testVectorP
{
private:
    vector<int> testInt;
public:
    void copyTest(vector<int>* &p)
    {
        p = &testInt;
    }
    testVectorP(/* args */);
    ~testVectorP();
};

testVectorP::testVectorP(/* args */)
{
    testInt.push_back(1);
    testInt.push_back(2);
    testInt.push_back(3);
}

testVectorP::~testVectorP()
{
}


int main()
{
    vector<int>* aaa;
    testVectorP pp;
    pp.copyTest(aaa);

    for(auto it : *aaa)
    {
        std::cout << it << endl;
    }
    cout << "aaaaaaaaaaaaaaaaaaaaa\n";

    vector<int> vecA;
    vector<int> vecB;
    vecA.push_back(10);
    vecA.push_back(10);
    vecA.push_back(20);
    vecA.push_back(30);

    vecB.assign(vecA.begin(), vecA.end());
        for(auto it : vecA)
{
    std::cout << it << endl;
}
    cout << "aaaaaaaaaaaaaaadsfsdfsfdsfaaaaaa\n";

    for(auto it : vecB)
{
    std::cout << it << endl;
}

    return 0;
}