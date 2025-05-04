// 读入三个整数，按每个整数占  8 个字符的宽度，右对齐输出它们，按照格式要求依次输出三个整数，之间以一个空格分开。

#include <iostream>
#include <format>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;


    // Cout写法
    cout.right;
    cout.width(8);
    cout << a << " ";
    cout.width(8);
    cout << b << " ";
    cout.width(8);
    cout << c << endl;

    // Format写法
    cout << format("{:>8} {:>8} {:>8}", a, b, c) << endl;


    return 0;
}