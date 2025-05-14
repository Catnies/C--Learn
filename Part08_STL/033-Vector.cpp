#include <algorithm>
#include <iostream>
#include <chrono>
#include <format>
#include <random>
#include <vector>
using namespace std;

// Vector 列表数据结构, 类似 java 的 List.
int main() {
    // 定义
    vector<char> list;     

    // 使用push_back方法可以将数值添加到队列内
    list.push_back('A');
    list.emplace_back('B');
    list.emplace_back('C');

    // 使用下标或迭代器进行访问.
    for (auto &&ch : list) {
        cout << sizeof(ch) << endl;
        cout << "最终显示: " << ch << endl;
    }

}