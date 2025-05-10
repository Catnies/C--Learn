#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// 联合常用于某个数据具有多种格式的情况, 
// 所以联合的内存空间将会由联合中占用内存最大的字段决定.
// 一个联合体在某一时刻只能使用其中的一种类型.
union Cat {
  char name[8]; // 通过在变量后面添加 [8] 显式指定使用 8 个字节.
  int age;
  struct {
    unsigned char i;
  }str;
};



// 枚举
// 枚举可以与数值转换, 从上倒下从0开始, 如图 RED=0, GREEN=1...
enum ColorType{
  RED,
  GREEN,
  YELLOW
};


// 类的作用域枚举, 避免全局枚举重复导致的冲突问题, 这样需要 类名::值 使用.
enum class Animal{
  CAT,
  RABBIT=2,     // 允许手动赋值序号, 但是注意下一项的序号就是上一项+1, 即 BEAR=3 .
  BEAR
};


int main() {
  cout << endl << "--- 联合 开始 ---" << endl;
  Cat data;
  data.name[0] = 'A';
  data.age     = 13;  // 下面的赋值可能会覆盖上面的数据, 因为联合体本身只有一块内存.

  cout << endl << "--- 枚举 开始 ---" << endl;
  ColorType color;
  color = RED;
  Animal animal;
  animal = Animal::CAT;
} 