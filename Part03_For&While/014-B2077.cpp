// 所谓角谷猜想，是指对于任意一个正整数，如果是奇数，则乘 3 加 1，如果是偶数，则除以 2，得到的结果再按照上述规则重复处理，最终总能够得到 1。
// 程序要求输入一个整数，将经过处理得到 1 的过程输出来。

#include <iostream>
#include <format>
using namespace std;

int main() {
    long long a;
    cin >> a;

    while (a != 1) {
        if (a % 2 == 1){
            cout << format("{}*3+1={}", a, a * 3 + 1) << endl;
            a = a * 3 + 1;
        } else {
            cout << format("{}/2={}", a, a / 2) << endl;
            a = a / 2;
        }
    }

    cout << "End" << endl;
    
    return 0;
}