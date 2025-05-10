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
    vector<wchar_t> list;     

    // 使用push_back方法可以将数值添加到队列内
    list.push_back(L'你');
    list.emplace_back(L'好');

    // 使用下标或迭代器进行访问.
    for (auto &&ch : list) {
        cout << sizeof(ch) << endl;
        wcout << "最终显示: " << ch << endl;
    }

}