#include <iostream>
#include <string>
using namespace std;


void f1(string& str) {
    cout << "这是左值引用" << endl;
};
void f1(string&& str) {
    cout << "这是右值引用" << endl;
};
void fw1(string& str) {
    f1(str);  
};
void fw1(string&& str) {
    // 其中, str在函数内部, 已经是一个局部变量了, 所以是一个左值.
    f1(str);
};
void fw2(string&& str) {
    // 所以我们得把这个值转成右值才行.
    f1(move(str));
};


void fun1() {
    cout << endl << "--- fun1 开始 ---" << endl;

    // 这段代码中, 最终跑起来的都是左值引用; 因为引用本身是一个左值!!!
    string str = string("Deep Dark Fantasy!");
    fw1(str);
    fw1(string("Deep Dark Fantasy!"));
    fw2(string("Deep Dark Fantasy!"));
};





// 但是如上代码依然有别的问题, 例如当一个函数的参数增加时, 重载函数将会以几何式增长, 所以我们需要一个既可以接受左值和右值, 又能正确转发给目标函数的方法.
// 我们可以使用函数模板, 这个模板可以接受左右值并且正确转发. 
// 其中forward函数, 在接受到左值时会将值转成左值, 右值会转成右值; 

// 其中还有引用折叠问题, 例如当T为 string&& , 那么实际上str的类型为 string&& &&, 代表右值引用的右值引用, 将会被折叠为右值引用.
// 当然还有别的, string& && , string&& &, string& &, 这些引用都会被折叠为左值引用.

// 我们把这个函数模板称为完美转发. 
template<typename T>
void fw3(T&& str) {
    f1(forward<T>(str));    // 为什么不用 move? 因为move会把左值引用转成右值引用, 导致T为左值时, 传入f1的参数会变成右值.
};



void fun2() {
    cout << endl << "--- fun2 开始 ---" << endl;

    string str = string("Do you like what you see?");
    fw3(str);
    fw3(string("Do you like what you see?"));

};



int main() {
    fun1();
    fun2();

    return 0;
}