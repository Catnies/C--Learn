#include <algorithm>
#include <iostream>
#include <chrono>
#include <format>
#include <random>
#include <vector>
using namespace std;


class MyInt
{
private:
    int v;
public:
    MyInt() { };
    MyInt(int n) { v = n; };
    ~MyInt() {};

    // 运算符重载， 支持 Myint + Myint 类型.
    MyInt operator+(const MyInt &rsh) {
        return MyInt(v + rsh.v);
    };
    // 支持 Myint + int 的运算符重载.
    MyInt operator+(const int &rsh) {
        return MyInt(v + rsh);
    };
    // 类型转换运算符， 当强制将 myint 转换成 int 时， 会触发此函数进行转换.
    // 如果携带 explicit 关键字， 则代表所有转换必须显式添加 (int) 才可以进行转换. 
    explicit operator int() {
        return v;
    }
    // 实现了以上运算符重载， 但是还是没办法实现 int + myint， 所以需要实现一个友元运算符重载函数.
    // 需要注意的是， 这个函数虽然定义在类内部， 但是它并不是类的成员. 
    friend MyInt operator+(const int &lsh, const MyInt &rsh) {
        return MyInt(rsh.v + lsh);
    }
};



int main() {
    int a(10);
    MyInt b(20), c(30), d;
    d = b + c;
    d = d + 10;
    d = 15 + d;

}