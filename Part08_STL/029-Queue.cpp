#include <algorithm>
#include <iostream>
#include <chrono>
#include <format>
#include <random>
#include <queue>
using namespace std;

// Queue 队列数据结构, 是一种 先进先出 的列表.
int main() {
    // 定义队列
    queue<int> que;     

    // 使用push方法可以将数值添加到队列内
    for (int i = 0; i < 10; i ++) {
        que.push(i);
    }

    // 使用 pop 方法将队列中的数据弹出.
    while (!que.empty()) {          // 使用 empty 判断队列是否为空.
        int front = que.front();    // 使用 front 读取队列的数据
        que.pop();                  // 使用 pop 弹出队列数据
        cout << front << endl;      // 打印之前读取的数据
    }

}