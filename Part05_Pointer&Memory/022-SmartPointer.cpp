#include <iostream>
#include <memory>       // 支持 智能指针 .
using namespace std;


// 智能指针
void fun1() {
  cout << endl << "--- fun3 开始 ---" << endl;

  // shared_ptr 指针, 如此定义的指针, 当指针在栈中被销毁时, 申请的内存也会被自动释放.
  shared_ptr<int> sptr = make_shared<int>(114514);
  cout << *sptr << endl;
  shared_ptr sptr_copy = sptr; // 即便复制多份也无妨, 会在最后一个指针被销毁时自动释放内存.


  // unique_ptr 指针, 这个指针是唯一的, 不可被复制;
  unique_ptr<double> uptr = make_unique<double>(3.1415926f);
  cout << *uptr << endl;


  // weak_ptr 指针, 这个指针不会直接申请内存, 实际上是一个弱引用其他指针的指针, 主要用于防止循环依赖导致的内存一直无法释放的问题.
  weak_ptr<int> wptr;
  wptr = sptr;        // 将 shared指针 赋值给 weak指针, 这样不会增加 shared指针 内部的计数, 所以在检查销毁 shared指针 时, weak指针不会阻止.

  // 要解引用 weak指针, 需要使用成员函数 .lock(), 这个函数会返回一个 shared指针. 
  // 如果对象已经被销毁，返回一个空 shared指针, 也就是 p 为 false.(shared指针对象内部存在 bool 转换运算符, 所以可以直接在 if 中进行判断.) 
  if (auto p = wptr.lock(); p) {        
    cout << *p << endl;
  }

}



int main() {
  fun1();
} 