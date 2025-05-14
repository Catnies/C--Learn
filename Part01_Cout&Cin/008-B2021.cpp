// 读入一个单精度浮点数，保留 3 位小数输出这个浮点数。

#include <iostream>
#include <format>
using namespace std;

int main() {
    float a;
    cin >> a;

    cout << format("{0:.3f}", a) << endl;

    return 0;
}