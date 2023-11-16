#include "../../../jian.h"

struct autoDel{
    int a = 0;

    ~autoDel()
    {
        cout << "del" << a << '\n';
    }
};


int * g_a = nullptr;

autoDel* testDel = new autoDel[3];


void test1();
void test2(int *a2);
void test3(int *a3);
void testDe1();

void test1()
{
    testDel[0].a = 10;
    testDel[1].a = 20;
    testDel[2].a = 30;
    // int *a = new int (98981);
    // test2(a);

    testDe1();
}

void testDe1()
{
    shared_ptr<autoDel[]> spData(testDel);
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
    
    // test3(g_a);
    cout << "test3 end....\n";

    return 0;
}