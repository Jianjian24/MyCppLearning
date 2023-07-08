#include "../../../jian.h"

int * g_a = nullptr;

void test1();
void test2(int *a2);
void test3(int *a3);

void test1()
{
    int *a = new int (98981);
    test2(a);
}

void test2(int *a2)
{
    // shared_ptr<int> spData(a2);
    // info(*spData);
    g_a = a2;
    // g_a = spData.get();
}

void test3(int *a3)
{
    info(*a3);
}

int main()
{
    test1();
    cout << "test1 end....\n";
    
    test3(g_a);

    return 0;
}