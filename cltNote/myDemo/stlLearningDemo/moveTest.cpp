#include "../../../jian.h"


class Person {
public:
    int num;

public:
    Person (int num) {
        cout << __PRETTY_FUNCTION__ << endl;
        this->num = num;
    }

    Person (const Person & p) {
        cout << __PRETTY_FUNCTION__ << endl;
        this->num = p.num;
        cout << "num=" << this->num << endl;
    }

    Person (Person && p) noexcept {
        cout << __PRETTY_FUNCTION__ << endl;
        this->num = p.num;
        p.num = 0;
        cout << "num=" << this->num << endl;
    }
    
    ~Person () {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

void test01() {

    Person p1(1);
    vector<Person> v;

    cout << __LINE__ << endl;
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    
    // 上面这些操作，是为了扩充 vector 的容量，从而不受容量已满开辟新空间时移动元素时调用相关构造函数对下面代码的影响

    cout << __LINE__ << endl;  // a
    v.push_back(10);  // 会调用一次有参构造+一次移动构造

    cout << __LINE__ << endl;
    v.emplace_back(20);  // 会调用一次有参构造

    cout << __LINE__ << endl;
    v.push_back(p1);  // 会调用一次拷贝构造
    
    cout << __LINE__ << endl;
    v.emplace_back(p1);  // 会调用一次拷贝构造
                               // b
}

int main(){
    test01();
    return 0;
}
