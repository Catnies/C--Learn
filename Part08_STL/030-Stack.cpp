#include <algorithm>
#include <iostream>
#include <chrono>
#include <format>
#include <random>
#include <stack>
using namespace std;

// Stack 栈数据结构, 是一种 后进先出 的列表.
int main() {
    // 定义
    stack<int> stack;     

    // 使用push方法可以将数值添加到栈内
    for (int i = 0; i < 10; i ++) {
        stack.push(i);
    }

    // 使用 pop 方法将队列中的数据弹出.
    while (!stack.empty()) {            // 使用 empty 判断队列是否为空.
        int top = stack.top();          // 使用 top 读取队列的数据
        stack.pop();                    // 使用 pop 弹出队列数据
        cout << top << endl;            // 打印之前读取的数据
    }

}