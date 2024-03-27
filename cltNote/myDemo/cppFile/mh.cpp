#include <iostream>
#include <string>
#include <algorithm>

std::string convert_to_26_alphabet(int num) {
    std::string result;
    while (num > 0) {
        num--; // Adjust for 1-indexed to 0-indexed
        int remainder = num % 26;
        result.push_back('A' + remainder);
        num /= 26;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    // Array of numbers to convert
    int numbers_to_convert[] = {2, 1, 26, 27, 52, 53, 702, 703, 704};
    int array_size = sizeof(numbers_to_convert) / sizeof(numbers_to_convert[0]);

    for (int i = 0; i < array_size; ++i) {
        int num = numbers_to_convert[i];
        std::cout << "Input: " << num << ", Output: " << convert_to_26_alphabet(num) << std::endl;
    }

    return 0;
}