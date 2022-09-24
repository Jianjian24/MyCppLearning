#include <iostream>
void int22char(int a) {
	//int 的最大正值，有10位，转char后有11位（加了个\0）; 负值占11位,转char后有12位（加了个\0）
	//所以定义char数组大小为12
	char str[12];
	//第三个参数10的意义是十进制
	_itoa_s(a, str, 10);
	std::cout << "char:" << str << std::endl;
	std::cout << "int:" << atoi(str) << std::endl;
}
void int6422char(__int64 a) {
	char str[21];
	_i64toa_s(a,str,21,10);
	std::cout << "char:" << str << std::endl;
	std::cout << "int:" << _atoi64(str) << std::endl;
}
int main()
{
	//int正值
	int a = 2147483647;
	int22char(a);
	//int负值
	a = 2147483648;
	int22char(a);
	//int值被截断
	__int64 a_i64 = 9223372036854775807;
	int22char(a_i64);
	//int64
	std::cout << "int64 value:" << std::endl;
	int6422char(a_i64);
	return 0;
}


