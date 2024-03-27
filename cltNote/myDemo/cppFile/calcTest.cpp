#include <string>
#include <iostream>

std::string GetCharTest(int number)
{
    std::string result;
    while (number > 0) {
        number -= 1;
        int digit = number % 26;
        result = static_cast<char>(digit + 'A');
        number /= 26;
    }
    return result;
}

std::string GetBoxsNamebySetting(int index) {
    std::string result;
    
    // 计算行号
    char row = 'A';
    int rowCount = 1;
    while (index >= rowCount * 3) {
        row++;
        if (row > 'Z') {
            row = 'A';
            result.push_back(row);
            rowCount = 1;
        }
        index -= 3;
        rowCount++;
    }
    
    // 计算列号
    int col = index + 1;
    
    // 拼接结果
    if (col < 10) {
        result.push_back('0');
    }
    result += std::to_string(col);
    
    return result;
}

// 测试函数
int main() {
    int index = 5;
    // std::string boxName = GetBoxsNamebySetting(index);
    std::string boxName ;
    // std::cout << "The " << index << " Box is:" << boxName << '\n';
    // boxName = GetBoxsNamebySetting(index);
    // index = 3;
    // boxName = GetCharTest(index);
    // std::cout << "The " << index << " Box is:" << boxName << '\n';
    // index = 100;
    // boxName = GetCharTest(index);
    // std::cout << "The " << index << " Box is:" << boxName << '\n';
    index = 52;
    boxName = GetCharTest(index);
    std::cout << "The " << index << " Box is:" << boxName << '\n';
    return 0;
}
