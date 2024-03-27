#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

std::vector<std::string> split(std::string &str, const std::string &delimiter)
{
    std::vector<std::string> tokens;
    size_t pos = 0;

    while ((pos = str.find(delimiter)) != std::string::npos)
    {
        std::string token = str.substr(0, pos);
        tokens.push_back(token);
        str = str.substr(pos + 1);
    }

    tokens.push_back(str);
    return tokens;
}

int main()
{
    // 指定 CSV 文件的路径
    string csv_file = "example.csv";

    // 打开 CSV 文件
    ifstream file(csv_file);
    if (!file.is_open())
    {
        cout << "无法打开 CSV 文件！" << endl;
        return 1;
    }

    // 读取 CSV 文件的内容
    string line;
    // vector<string> headers;
    // while (getline(file, line))
    // {
    //     headers.push_back(line);
    // }

    std::string delimiter = ",";
    // 遍历 CSV 文件的每一行数据
    while (getline(file, line))
    {
        vector<string> row = split(line, delimiter);

        // 处理每一行的数据
        for (size_t i = 0; i < row.size(); ++i)
        {
            // cout << headers[i] << ": " << row[i] << endl;
            cout << row[i] << "::";
        }
        cout << endl;
    }

    // 关闭 CSV 文件
    file.close();
    system("pause");
    return 0;
}
