// 给定一个字符，用它构造一个底边长 5 个字符，高 3 个字符的等腰字符三角形。

#include <iostream>
#include <format>
using namespace std;

int main() {
    char a;
    cin >> a;

    cout << std::format("  {0}  ", a) << endl;
    cout << std::format(" {0}{0}{0} ", a) << endl;
    cout << std::format("{0}{0}{0}{0}{0}", a) << endl;

    return 0;
}