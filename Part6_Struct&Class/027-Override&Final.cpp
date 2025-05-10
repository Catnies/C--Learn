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
    // 静态变量, 静态变量通过 类名::字段 进行访问. 
    static string type; 
    // 静态成员函数
    static void hello() { cout << "Hi" << endl; };

    string name;
    virtual ~People() {};

    // 公共函数
    string getName() { return this -> name; };
    void setName(string name) { (*this).name = name; };
    virtual void say() { cout << "我是人类" << endl; };
};


// 类的继承
// 在类名后面添加final关键字, 代表此类不能被继承.
class Women final: public People {
  public:
    // Override 关键字, 加在函数参数后面, 代表显式告诉编译器, 此函数是重写父类的同名同参的虚函数.
    void say() override { cout<< "我是女人" << endl; };
    // Final 关键字, 可以确保子类不再能重写这个虚函数.
    virtual void chat() final { cout << "哈哈哈" << endl; }; 
};


int main() {
  cout << endl << "--- 静态成员 开始 ---" << endl;
  People::type = "人类";
  People::hello();


  cout << endl << "--- 虚函数&多态 开始 ---" << endl;
  People* people2 = new Women();
  people2->say(); // 重写的函数
  delete people2;

  
} 