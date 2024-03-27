#include <iostream>

enum EnTest{
    en1 = 1,
    en2 = 2
};

int main() {

    EnTest aa = en1;
    std::cout << aa << "  \n";

    try {
        // 这里放可能抛出异常的代码
        int a = 1;
        int b = a * 0; // 这里故意让b为0，从而引发异常
        std::cout << "Result: " << a / b << std::endl;
    } catch (const std::exception& e) {
        std::cout << "捕获到异常: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "捕获到未知异常" << std::endl;
    }

    return 0;
}