#include <iostream>
using namespace std;

class demo{
public:
   demo():num(new int(0)){
      cout<<"construct!"<<endl;
   }
   //拷贝构造函数
   demo(const demo &d):num(new int(*d.num)){
      cout<<"copy construct!"<<endl;
   }
   ~demo(){
      cout<<"class destruct!"<<endl;
   }
private:
   int *num;
};

demo get_demo(){
    return demo();
}

int main(){
    demo a = get_demo();
    return 0;
}

// #include <iostream>
// using namespace std;
// class demo{
// public:
//     demo():num(new int(0)){
//         cout<<"construct!"<<endl;
//     }

//     demo(const demo &d):num(new int(*d.num)){
//         cout<<"copy construct!"<<endl;
//     }
//     //添加移动构造函数
//     demo(demo &&d):num(d.num){
//         d.num = NULL;
//         cout<<"move construct!"<<endl;
//     }
//     ~demo(){
//         cout<<"class destruct!"<<endl;
//     }
// private:
//     int *num;
// };
// demo get_demo(){
//     return demo();
// }
// int main(){
//     demo a = get_demo();
//     return 0;
// }