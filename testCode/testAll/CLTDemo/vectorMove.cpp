#include "../../../jian.h"

int main()
{
    vector<int> vec{1,2,3,4,5,6};
    for (auto& v : vec){
        cout << " " << v ;
    }
    putchar('\n');
    //将某个位置的数据放到前面，并保持其他元素相对位置不变
    //先记录，再clear，再插入

    auto it = vec.begin() + 2;//3
    int temp = *it;
    vec.erase(it);
    vec.insert(vec.begin(), temp);

    for (auto& v : vec){
        cout << " " << v ;
    }

}