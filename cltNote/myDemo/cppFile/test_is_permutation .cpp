#include "../../../jian.h"

int main()
{
    std::vector<double> data1{44.5, 22.0, 15.6, 1.5};
    std::vector<double> data2{22.5, 44.5, 9, 15.6};
    std::vector<double> data3{1.5, 44.5, 15.6, 22.0,6};

    auto test = [] (const auto& d1, const auto& d2)
    {
        std::copy(std::begin(d1), std::end(d1), std::ostream_iterator<double> {std::cout," "});
        std::cout << (is_permutation(std::begin (d1), std::end(d1), std::begin(d2), std::end(d2))?"is":"is not");
        std::copy(std::begin(d2), std::end(d2), std::ostream_iterator<double>{std::cout, " "});
        std::cout << std::endl;
    };
    test(data1, data2);
    test(data1, data3);
    test(data3, data2);

    // system("pause");

    // 转化连接字符串   

    

}