#include <iostream>

using namespace std;


enum myNum
{
    id1,
    id2,
    id3
};

void testEnum(myNum demo)
{
    cout << demo << "\n" << "aaaaaaaa";
}

int main()
{
    // default: output "0" represent the first item
    myNum num;
    testEnum(num);
    return 0;
}