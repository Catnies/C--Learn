#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// 类的声明
class People {
  friend class Shape;   // 友元, 声明类 Shape 为类 People的友元, 那么在 Shape 类中, 可以无限制访问 类People 的成员, 包括私有变量.
  friend int lookHimistu(People& people);   // 同理, 也可以将函数声明为类的友元, 在函数中也可以无限制访问People的私有成员. 
  private:
    string himitsu;
  public:
    const string type = "人类";
    string name;
    int age;
    virtual ~People() {};

    // 公共函数
    string getName() { return this -> name; };
    void setName(string name) { (*this).name = name; };
    void setHimitsu(string content) { this->himitsu = content; };

    void calc(int a) const { 
      // age++;             // 这段代码是错误的, 因为const函数中无法修改内部字段.
      // setName("Kala");   // 这段代码也是错误的, 因为编译器无法知道其他非const函数是否修改了内部字段. 
      cout << a++ << endl; 
      cout << type << endl;   // const 成员函数是可以访问 const 成员的.
    };
};


// 形状类
class Shape {
  public:
    void look(People& people) {
      cout << people.himitsu << endl;   // 因为People声明了Shape为其友元, 所以可以访问People类的私有变量.
    }
};

// 函数
int lookHimistu(People& people) {
  cout << people.himitsu << endl;  // 因为People声明了 lookHimistu函数 为其友元, 所以可以访问People类的私有变量.
  return 0;
}


int main() {
  cout << endl << "--- Const 开始 ---" << endl;
  People people;
  people.setHimitsu("Wow!");
  Shape sp;
  sp.look(people);
  lookHimistu(people);
} 