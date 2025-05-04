// 输入三个整数，输出最大的数。

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    unsigned int a, b, c;
    cin >> a >> b >> c;
    cout<< max(a, max(b, c));
    return 0;
}