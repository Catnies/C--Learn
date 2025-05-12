#include <iostream>
using namespace std;


// 函数模板. 例如我们需要实现多个不同类型参数, 但是相同函数逻辑的函数时,  可以使用函数模板. 
// 函数模板本身并不会定义函数, 而是编译阶段根据所用到的类型进行生成对应类型的函数, 例如该模板只用到了int类型, 那么就在编译完成时就会生成一个int类型实参的函数. -> 隐式实例化.
template <class T>      // 函数模板的定义方式, 在函数的上一行添加 Templelate <class 标识>, class关键字也可以换成typename, 本质是一样的.
void sum(T& a, T&b) {
    cout << a + b << endl;
};


// 当然也可以显式实例化模板函数.
template void sum<float>(float& a, float& b);

// 还可以对特定参数类型进行特化, 当使用特定参数类型调用函数时, 则会使用该函数.
template<> 
void sum<long>(long& a, long& b) {
    cout << a + b << endl;
};

int main() {
    int a(10), b(13);
    sum<int>(a, b);     // 在使用模板时, 需要指定模板的类型, 在函数后面添加 <类型> .
    return 0;
}