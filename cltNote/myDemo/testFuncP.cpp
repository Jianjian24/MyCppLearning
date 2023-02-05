#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>

void info(char* sometext){
    cout << sometext << "\n";
}

void info(int num){
    cout << num << "\n";
}

class CFun
{
public:
    void myFun()
    {
        cout << "hello\n";
    }
};


int main()
{
    CFun::myFun();

    return 0;
}