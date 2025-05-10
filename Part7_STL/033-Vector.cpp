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
    vector<int> list;     

    // 使用push方法可以将数值添加到队列内
    for (int i = 0; i < 10; i ++) {
        list.push_back(i);
        list.emplace_back(2*i);
    }

    // 使用下标或迭代器进行访问.
    for (auto &&i : list) {
        cout << i << endl;
    }

}