#include <iostream>

int main()
{
    char c1[] = "ab";
    unsigned char c2 = 'a';
    char* c3 = c1;
    std::cout << ((*c3 & c2) == c2)? true:false;
    //out : 1 由于*c3是第一个字母，所以相等，故在项目中需要保证在比较校正状态的时候，是输入一个字符
    std::cout << (c3[0] == c2)? true:false;

}