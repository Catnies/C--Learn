// 读入一个双精度浮点数，保留 12 位小数，输出这个浮点数。

#include <iostream>
#include <format>
using namespace std;

int main() {
    double a;
    cin >> a;

    cout << format("{0:.12f}", a) << endl;

    return 0;
}