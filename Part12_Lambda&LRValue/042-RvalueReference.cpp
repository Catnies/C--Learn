#include <iostream>
#include <string>
using namespace std;


// 这是一个普通函数, 只能接受string作为参数.
void fun1(string str) {
    cout << endl << "--- fun1 开始 ---" << endl;

    cout << str << endl;

};

// 这个函数则是接收string的引用.
void fun2(string& str) {
    cout << endl << "--- fun2 开始 ---" << endl;

    cout << str << endl;

};



// 形参是个右值引用
void change(int&& right_value) {
    right_value = 8;
}
 
int fun3() {
    int a = 5; // a是个左值
    int &ref_a_left = a; // ref_a_left是个左值引用
    int &&ref_a_right = std::move(a); // ref_a_right是个右值引用
 
    // change(a); // 编译不过，a是左值，change参数要求右值
    // change(ref_a_left); // 编译不过，左值引用ref_a_left本身也是个左值
    // change(ref_a_right); // 编译不过，右值引用ref_a_right本身也是个左值
     
    change(std::move(a)); // 编译通过
    change(std::move(ref_a_right)); // 编译通过
    change(std::move(ref_a_left)); // 编译通过
 
    change(5); // 当然可以直接接右值，编译通过
    
    // 打印这三个左值的地址，都是一样的
    cout << &a << ' ';
    cout << &ref_a_left << ' ';
    cout << &ref_a_right;
}




int main() {
    string str = "hello";

    int a = 5;      // 其中 a 是左值, 5 是右值.
    int &ref_a = a; // 左值引用指向左值，编译通过
    // int &ref_a = 5; // 左值引用指向了右值，会编译失败. 引用是变量的别名，由于右值没有地址，没法被修改，所以左值引用无法指向右值。
    const int &ref_a = 5;  // 编译通过. const左值引用不会修改指向值，因此可以指向右值


    // 右值引用的标志是&&，顾名思义，右值引用专门为右值而生，可以指向右值，不能指向左值.
    int &&ref_a_right = 5; // ok
    int a = 5;
    // int &&ref_a_left = a; // 编译不过，右值引用不可以指向左值
    ref_a_right = 6; // 右值引用的用途：可以修改右值


    // 探讨:  右值引用有办法指向左值吗？
    int &ref_a_left = a; // 左值引用指向左值
    int &&ref_a_right = std::move(a); // 通过std::move将左值转化为右值，事实上std::move移动不了什么，唯一的功能是把左值强制转化为右值，让右值引用可以指向左值。其实现等同于一个类型转换：static_cast<T&&>(lvalue)。 
    cout << a; // 打印结果：5




    fun1(str);     // 第一个函数没问题, 因为传入的hello会被复制一份.
    fun1("hello"); // 问题, 因为会触发优化, 避免hello被复制一份. (C++17)
    
    fun2(str);      // 没问题.
    // fun2("hello"); // 第二个函数出现了问题, 因为需要的是引用, 而传入的是右值.



    return 0;
}