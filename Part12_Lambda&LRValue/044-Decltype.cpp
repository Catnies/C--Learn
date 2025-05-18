#include <iostream>
#include <vector>
using namespace std;


struct A {
    double b;
};


string&& ft1() {
    string s = "hello";
    return move(s);
};



int main() {
    auto a = 5 + 5;

    // decltype() 可以传入变量或者表达式, 获得他们的类型; 
    decltype(a) b = a * 2;  // 这里通过decltype获得了a的类型, 相当于是int.

    const int c = 5;
    decltype(c) d = c;  // 同理, 类型是 const int.
    decltype(A::b) e = 2.0; // 类型是类A的b字段的类型.


    // 但是当decltype传入表达式时, 又是不同的情况. 
    // 如果表达式是左值时, 推导的类型为 类型的引用
    decltype((a)) f = a; // 这里f的类型是 int&.
    // 如果表达式是右值时, 推导的类型为 类型
    decltype((1+1)) g; // 这里g的类型是 int.
    // 如果表达式是Xvalue时, 推导的类型是右值的引用;
    decltype(ft1()) h = "world";


    return 0;
}