#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

// 把整数转换成对应进制的字符，例如10的十六进制中表示为A
char Int2Char(int target){

    // target++;
    return target + 'A';

}
/*
 * 现在N可以取任意进制了
 * */
void ConvertT2N(int number,int n){
    stack<char> s;  //因为要存字母所以用char
    // if (number == 0) {  //特殊情况，当输入是0时，输出也是0，否则输入0时就卡那了
    //     s.push(0);
    // } else {
    //     while (number) {
    //         s.push(Int2Char(number % (n)));   //在余数入栈时加工一下,把int转换成char
    //         number /= n;
    //     }
    // }
    // // int n = 100;
    char ch = '\0';
    int flag = 0; //    进位标识
    while (number)
    {    
        if (number % 26)
        {   
            //大于26且存在余数，先处理最后一位
            if (number % 27 == 0)
            {
                ch = 'Z';
                s.push(ch);               
            }
            else
            {
                ch = number % 26 - 1 + 'A';
                s.push(ch);
            }
            
        }
        else
        {
            ch = 'Z';
            s.push(ch);
        }
        
        number = number / 26 - (flag ? 1 : 0);
        ++flag;
        // number /= 26 ;

        // if  (number > 1) --number;
    }

    
    // 把栈中的余数输出
    while (!s.empty()) {
        printf("%c", s.top());
        s.pop();
    }
    printf("\n");


}

int main(){
    int number;
    // number = 10;
    // ConvertT2N(number, 27);//把十进制转换为十六进制
    // number = 52;
    // ConvertT2N(number, 26);//把十进制转换为十六进制
    // // number = 26;
    // // ConvertT2N(number, 27);//把十进制转换为十六进制
    number = 702;
    ConvertT2N(number, 26);//把十进制转换为十六进制
    number = 703;
    ConvertT2N(number, 26);//把十进制转换为十六进制
    // number = 52;    //AZ
    // ConvertT2N(number, 26);//把十进制转换为十六进制
    return 0;
}