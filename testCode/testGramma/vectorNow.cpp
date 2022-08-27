#include <iostream>
#include <vector>

using namespace std;

typedef struct test
{
    int num1;
    char ch1;
}CAO;

int main()
{
    vector<int> vecTest(10,2);
    vector<CAO> vecCAO;

    CAO C1{10, 'a'};
    CAO C2{20, 'b'};
    CAO C3{30, 'c'};
    CAO C4{40, 'd'};

    vecCAO.push_back(C1);
    vecCAO.push_back(C2);
    vecCAO.push_back(C3);
    vecCAO.push_back(C4);

    for(auto it = vecCAO.begin(); it != vecCAO.end(); ++it)
    {
        if (it->num1 == 10)
        {
            it->num1 = 90;
        }
    }

    for (auto it : vecCAO)
    {
        cout << it.ch1 << " " << it.num1 << "\n";
    }

    return 0;


}