#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// 类的声明
class People {

  private:
    string name;    // 私有字段, 外部不可访问.
    int age;
    int* digits = nullptr;

  public:
    // 构造函数
    People(const string name, const int age): name(name), age(age) {    // 在参数定义后面加 : 后可以设置参数的初始化, 类似 java 的 this.name = name;
      this -> digits = new int;    // 需要注意的是, this关键字所代表的是当前对象的指针, 而非引用, 所以需要箭头函数进行解引用后访问. 这与 java 是不同的.
    };
    // 构析函数 : 当类被回收释放时, 会触发构析函数, 其中的堆字段需要手动释放.
    ~People(); // 这里只做定义, 不为其设置函数体, 函数体可以在类的外部设置.

    // 重载对象构造函数, 因为类中包含指针, 如果不重载, 则当在使用对象a创建对象b时, 指针会复制, 最后导致2个对象的字段指向同一个内存的问题.
    People(const People& other): name(other.name), age(other.age) {
      digits = new int(*other.digits);   // 重新分配内存, 然后将旧对象的值初始化到新的对象上
    }

    // 公共函数
    string getName() { return this -> name; };
    void setName(string name) { (*this).name = name; };
};


// 为构析函数设置函数体, 在类的外部设置类的函数时, 需要为其添加一个 类名:: 作为函数的前缀, 以让编译器识别这是类的内部函数.
People::~People() {
  delete[] digits;
  digits = nullptr;
};


int main() {
  People* people = new People{"橙汁", 16};  // 创建对象.
  people -> setName("柠檬");     // 调用成员函数.

  cout << people -> getName() << endl;

  delete people;      // 记得释放内存
} 