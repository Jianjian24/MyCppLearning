
//C++ 处理一个数字，需求是将这个数字转化为字母，规则如下，大写字母A~Z分别代表1~26这26个数字，输入输出示例如下，输入2，输出B；输入1，输出A；输入26，输出Z，输入27，输出AA，输入52，输出AZ，输入53，输出BA
#include <iostream>
#include <string>

using namespace std;

string numberToLetters(int number) {
    string result = "";
    while (number > 0) {
        int digit = number % 26;
        if (digit == 0) {
            digit = 26;
        }
        char letter = 'A' + digit - 1;
        result = letter + result;

        int exNum = 0;
        if (number >= 26)
        {
            exNum = 1;
        }
        
        number = number / 26 - exNum;
    }
    return result;
}

int main() {
    int number;
    string result ;
    // number = 26;
    // result = numberToLetters(number);
    // cout << "result:" << result << endl;
    number = 27;
    result = numberToLetters(number);
    cout << "result:" << result << endl;
    number = 702;
    result = numberToLetters(number);
    cout << "result:" << result << endl;
    return 0;
}