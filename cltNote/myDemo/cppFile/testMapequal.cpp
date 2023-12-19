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

    // unordered_set<int> s1;
    // s1.insert(100);
    // s1.insert(200);
    // s1.insert(300);

    // s1.erase(200);
    // s1.erase(201);

    std::map<int, int> dest;

    if (dest.find(1) == dest.end() || dest[1] < 2)
    {
        info("123123\n");
    }

    dest[2] = 100;
    // {
    //     std::map<int, int> src;

    //     src[1] = 1;
    //     src[2] = 2;
    //     src[3] = 3;

    //     // 获取src的第一个键值对
    //     auto it = src.begin();

    //     // 拷贝src的键值对到dest
    //     while (it != src.end()) {
    //         dest[std::move(it->first)] = std::move(it->second);
    //         it++;
    //     }

    //     info(src[1]);
    //     info(src[2]);
    // }
    // // testDel();

    // info(dest[1]);
    // info(dest[2]);

    system("pause");

    return 0;
}