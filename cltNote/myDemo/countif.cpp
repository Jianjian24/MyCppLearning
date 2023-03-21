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

int main()
{
    vector<bool> a;
    a.push_back(0);
    // a.push_back(2);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    
    info(std::count_if(a.begin(), a.end(), [](bool val){return val == 2 ? true : false;}));
    return 0;

    
}