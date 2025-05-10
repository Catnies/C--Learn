#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// 类的声明
class People {
  private:
    int age;
  public:
    string name;
    byte gender;
    People() { cout << "父类构造!" << endl; };
    People(int age): age(age) { };
    ~People() { cout << "父类析构!" << endl;  };

    // 公共函数
    string getName() { return this -> name; };
    void setName(string name) { (*this).name = name; };

    void say() { cout << "我是人类" << endl; };

    virtual void chat() { cout << "我是父类" << endl;  }
};


// 类的继承, 在定义的类名后面添加 : + 访问控制符 + 父类类名 即可.
// 子类只能继承父类的 Public + Protected 字段和函数, 类名后面添加的访问控制符指的是重定义继承的字段函数的最小权限, 例如设置 private , 则继承到的所有 Public 和 Protected 字段都会变成 Private 权限.
class Women: public People {
  private:

  public:
    // 对象构造 -> 父类默认构造函数 -> 子类默认构造函数 -> 子类析构函数 -> 父类析构函数;
    Women() { cout << "子类构造!" << endl; }; // 当子类进行构造时, 会先调用父类的默认构造函数, 然后才会调用自身的默认构造函数;
    ~Women() { cout << "子类析构!" << endl; }; // 当子类进行析构时, 会先调用子类的默认析构函数, 然后才会调用自身的析构函数;

    // 函数重写: 当子类定义了与父类中一样的函数时, 会被试做重写.
    void say() { cout<< "我是女人" << endl; };

    // 虚函数, 当父类指针指向子类时, 会以实际类型调用函数
    virtual void chat() { 
      cout << "我是子类" << endl;
      People::chat(); // 其实仍然可以通过 父类::函数 去调用父类的函数, 类似java的 super.chat().
    };

};


// 接口类 & 抽象类;
// 严格来说，C++ 并没有专门的“接口”关键字，但我们可以用抽象类来模拟接口的行为。
class Shape {
  public:
    virtual double area()=0; // 定义纯虚函数, 类似java的接口内部的函数, 函数没有函数体, 后面用=0代替, 代表函数具体实现交给子类实现.
    virtual ~Shape() {}     // 定义虚构析函数, 因为当你使用多态特性创建对象时, 如果父类没有虚析构函数, 那么实际上只会调用父类默认的空析构函数, 而子类的析构是不会被调用的, 所以必须添加!!!
};



int main() {
  cout << endl << "--- 类构造 开始 ---" << endl;
  People* people = new People();  // 创建对象.
  Women* women = new Women();

  cout << endl << "--- 函数重写 开始 ---" << endl;
  people->say();
  women->say();

  cout << endl << "--- 虚函数&多态 开始 ---" << endl;
  People* people2 = new Women();
  people2->say(); // 没有虚函数, 因为定义类型是父类, 所以输出的还是父类的函数体. (和java不同, java本身都带虚函数的特性?)
  people2->chat(); // 有虚函数, 因为实际类型是子类, 所以会使用子类的函数输出.

  cout << endl << "--- 类释放 开始 ---" << endl;
  delete people;      // 记得释放内存
  delete women;
} 