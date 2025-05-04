// 输入两行，第一行为整数 1≤n<100），表示参加这次考试的人数。第二行是这 n 个学生的成绩，相邻两个数之间用单个空格隔开。
// 所有成绩均为 0 到 100 之间的整数。

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int maxx = 0;
    while (n--) {
        int x;
        cin >> x;
        maxx = max(maxx, x);
    }
    cout << maxx << endl;
}