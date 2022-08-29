#include <iostream>
#include <vector>

using namespace std;    

int main()
{
    int arr2[2][3] = {{1,2,3},{4,5,6}};

    vector<double> a[2];

    a->push_back(1);
    a->push_back(3);
    a->push_back(2);
    a->push_back(2);
    a->push_back(2);

    for( auto it : a)
    {
        cout << (it[1]) << " ";
    }

    // for (int i = 0; i < 6; i++)
    // {
    //     std::cout << arr2[i] << " ";//用法不对，这样是直接访问地址
    //     std::cout << "HELLO" << " ";
    // }
    // system("pause");
    return 0;
}