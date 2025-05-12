#include <iostream>
using namespace std;


void fun1() {
    cout << endl << "--- fun1 开始 ---" << endl;

    int x, y;
    x = 10;
    y = 15;

    // 定义一个lambda表达式, 其中 [] 表示捕获值.
    auto ptr = [x, &y](int a, int b){
        // x++;    // 需要注意的是, 函数中按值捕获的成员都是const修饰的, 所以 lambda 里不能修改按值捕获的成员.
        y++;       // 引用捕获就可以随便修改.
        return a + b + x + y;
    };

    // 可以在lambda表达式后面添加 mutable 关键字, 使值捕获的成员变得可变.
    auto ptr1 = [x, y](int a, int b) mutable {
        x++;
        return a + b + x + y;
    };

    cout << ptr(10, 10) << endl;
    y = 20;     // 尝试修改xy的值时不会生效, 因为x y的捕获是值捕获, 过程会复制值.
    cout << ptr(x, y) << endl;

};



void fun2() {
    cout << endl << "--- fun2 开始 ---" << endl;

    int x, y;
    x = 10;
    y = 15;

    // 使用 [=] 可以以值捕获的形式捕获所有变量
    auto ptr1 = [=](int a, int b){
        return a + b + x + y;
    };

    // 使用 [&] 可以以引用捕获的形式捕获所有变量
    auto ptr2 = [&](int a, int b){
        y++;
        return a + b + x + y;
    };

    cout << ptr1(10, 10) << endl;
    y = 20;     // 这次我们使用引用捕获
    cout << ptr2(x, y) << endl;

};


auto fun3() {
    cout << endl << "--- fun3 开始 ---" << endl;

    int x = 5, y = 10;
    return [&](){return x + y;};
}


void fun4() {
    // 其实还可以创建auto参数类型的lambda, 因为lambda本质上是个匿名类, 所以如果使用auto, 其字段就是泛型 T. 
    auto ptr1 = [&](auto a, auto b){
        return a + b;
    };

    // 这样一个lambda可以支持 int 和 double 类型的参数.
    cout << ptr1(1,2) << endl;
    cout << ptr1(1.0, 2.0) << endl;
}



int main() {
    fun1();
    fun2();

    // 这段代码实际上会无法正常运行, 因为其中lambda是按引用捕获的x 和 y, 但是在函数执行完成时, x 和 y已经被释放, 所以无法正常执行.
    auto f3 = fun3();
    cout << f3() << endl; 
    
    fun4();

    return 0;
}