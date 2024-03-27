#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

std::string decimalToBase26(int ans) {

    ans--;
    string str="";
	while(ans>0){
		int m = ans % 26;
		if(m == 0) m = 26;
		str+=(char)(m+'A');
		ans=(ans-m)/26;
	}
	reverse(str.begin(),str.end());	//反序

    return str;
}

int main() {
    int decimal = 2;
    // std::cout << "请输入一个十进制数: ";
    // std::cin >> decimal;

    std::string base26;
    // base26 = decimalToBase26(decimal);
    // std::cout << "Result: " << base26 << std::endl;
    // decimal = 26;
    // base26 = decimalToBase26(decimal);
    // std::cout << "Result: " << base26 << std::endl;
    decimal = 52;
    base26 = decimalToBase26(decimal);
    std::cout << "Result: " << base26 << std::endl;
    // decimal = 521111;
    // base26 = decimalToBase26(decimal);
    // std::cout << "Result: " << base26 << std::endl;

    return 0;
}
