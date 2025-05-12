#include <iostream>
#include <vector>
using namespace std;


void foo() { cout << "global foo" << endl; }

// 使用命名空间可以区分同名函数和字段
namespace MySpace {
    void foo() { cout << "myspace foo" << endl; }
};


int main() {
    ::foo();        // 全局命名空间的函数
    MySpace::foo(); // MySpace命名空间的函数.
    return 0;
}