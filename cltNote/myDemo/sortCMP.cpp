#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>

int main()
{
    vector<int> a;
    vector<int> b;

    a.push_back(233);
    a.push_back(1);
    a.push_back(12);
    a.push_back(16);
    a.push_back(14);

    sort(a.begin(), a.end(), [](int a, int b){return a > b ? true : false;});

    for(auto it : a)
    {
        cout << it << " ";
    }
    cout << "\n";
    
    return 0;
}