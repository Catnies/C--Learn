#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// 可以使用 throw 抛出异常.
double divide(const double &a, const double &b) {
    if (b == 0) {
        throw runtime_error("除数不能为0!");
    };
    return a/b;
};


// 对于需要开辟内存空间的对象, 可能会在发生异常后无法正常释放. 我们可以使用智能指针封装.
void trycatch() {
    vector<int>* v1 = new vector<int>{1,2,3,4,5,6,7,8,9,10};
    shared_ptr<vector<int>> sptr(v1);
    throw runtime_error("模拟异常");        // 即便异常中断了代码, 智能指针也会自动释放内存.
}


// 异常
int main() {
    try {
        divide(1.0, 0.0);
    } catch (const std::exception& e) {
        std::cerr << e.what() << endl;
    };

    return 0;
}