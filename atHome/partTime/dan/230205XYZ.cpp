#include <iostream>
#include <cmath>
using namespace std;


void syracuse(int n, int limit, int& call, int& highest)
{
    call++;
    highest = max(highest, n);

    if (call == limit + 1 || n == 1)
    {

        return;
    }

    cout << n  << "                   ";
    if (n % 2 == 0)
    {
        int result = n / 2;
        cout << result << endl;
        syracuse(result, limit, call, highest);
    }
    else
    {
    int result = (3*n  + 1) / 2;
        cout << result << endl;
        syracuse(result, limit, call, highest);
    }
}

int main()
{
    int n, limit;
    cout << "Number: ";
    cin >> n;
    while (n <= 1)
    {
        cout << "Error: n must be greater than 1. Enter an integer n: ";
        cin >> n;
    }
    cout << "Limit of terms: ";
    cin >> limit;


    while (limit <= 1)
    {
        cout << "Error: limit must be greater than 1. Enter the limit: ";
        cin >> limit;
    }

    cout << "Input Number        Syracuse(n)" << endl;
    cout << "-------------------------------" << endl;

    int call = 0, highest = 0;
    syracuse(n, limit, call, highest);

    if (call < limit)
    {
        cout << "Sequence ended after " << call << " terms." << endl;
    }
    cout << "Highest number reached: " << highest << endl;

    return 0;
}