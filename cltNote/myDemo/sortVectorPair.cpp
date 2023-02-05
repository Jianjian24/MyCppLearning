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
    vector<pair<int, int>>vec;
    vec.push_back({ 1,2 });
    vec.push_back({ 1,1 });
    vec.push_back({ 3,3 });
    vec.push_back({ 2,1 });
    vec.push_back({ 3,4 });
    sort(vec.begin(), vec.end());

    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ")" << endl;
    }
    
    return 0;
}