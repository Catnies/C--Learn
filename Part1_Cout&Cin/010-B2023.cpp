// 读入一个字符，一个整数，一个单精度浮点数，一个双精度浮点数，然后按顺序输出它们，并且要求在他们之间用一个空格分隔。输出浮点数时保留 6 位小数。

#include <iostream>
#include <format>
using namespace std;

int main() {
    char a;
    int b;
    float c;
    double d;

    cin >> a >> b >> c >> d;
    cout << format("{} {} {:.6f} {:.6f}", a, b, c, d) << endl;

    return 0;
}