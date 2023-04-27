#include "../../../jian.h"
#include <map>

void testDel()
{
    int aa = 0;
    delete &aa;

}


int main()
{
    // map<int, int> m1;
    // map<int, int> m2;
    
    // m1[100] = 98;
    // m1[100] = 2;
    // m1[11] = 2;

    // m2 = m1;

    // for(auto it : m2)
    // {
    //     cout << it.first << "---" << it.second << "\n";
    // }

    testDel();

    system("pause");
    
    return 0;
}