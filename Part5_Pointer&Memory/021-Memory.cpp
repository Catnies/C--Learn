#include <iostream>
#include <cstdlib>      // 支持 malloc/free . 
using namespace std;


// 使用 malloc 手动在堆空间中开辟内存, 函数将会返回开辟的内存的开始地址的 void 指针.
void fun1() {
  cout << endl << "--- fun1 开始 ---" << endl;

  int* ptr = (int*)malloc(sizeof(int));                       // 入参为开辟内存的字节数, 因为返回的是 void 指针, 所以需要强制转换.
  cout << "内存地址: " << ptr << " 的值为: " << *ptr << endl;  // 打印内容, 需要注意的是, 申请到的内存并不会初始化, 有可能是其他进程残留的数据.
  *ptr = 114514;                                              // 将内存中的数据设置初始化.
  cout << "内存地址: " << ptr << " 的值为: " << *ptr << endl;  // 打印内容.
  free(ptr);                                                  // 在使用完成后, 需要手动释放堆内存中的数据, 如果指针被销毁了, 那么这段内存将不再可以通过正常方法访问.

  // 使用  calloc 申请内存, 传入的入参为, 元素数量 和 元素大小, 例如此处创建了一个长度为5的int数组.
  int (*arrptr)[5] = (int(*)[5])calloc(5, sizeof(int));       
  (*arrptr)[0] = 1;
  (*arrptr)[1] = 2;
  (*arrptr)[2] = 3;
  (*arrptr)[3] = 4;
  (*arrptr)[4] = 5;
  for (auto &&i : *arrptr) {
    cout << "数组值: " << i << endl;
  }

  // 使用 realloc 可以传入 原指针 + 新大小 重新给这个指针分配内存, 例如此处将先前创建的20字节的指针扩容到了40字节.
  int (*newptr)[10] = (int(*)[10])realloc(arrptr, 10 * sizeof(int));
  for (auto &&i : *newptr) {
    cout << "扩容数组值: " << i << endl;
  }
  
}



// 使用 new 关键字在堆空间申请内存, 同上, 将会返回开辟的内存的开始地址的指针, 但是返回的指针类型将会是 new 对应的类型.
void fun2() {
  cout << endl << "--- fun2 开始 ---" << endl;

  int* ptr1 = new int;                   // 申请内存, 不初始化值.
  int* ptr2 = new int();                 // 申请内存, 初始化值, 不指定默认为 0 .                     
  int* ptr3 = new int(114514);           // 申请内存, 初始化值为 114514 .
  cout << "内存地址: " << ptr1 << " 的值为: " << *ptr1 << endl;  // 打印内容, 申请到的内存没有初始化, 有可能是其他进程残留的数据.
  cout << "内存地址: " << ptr2 << " 的值为: " << *ptr2 << endl;  // 打印内容
  cout << "内存地址: " << ptr3 << " 的值为: " << *ptr3 << endl;  // 打印内容
  delete ptr1;    // 同 malloc, 需要手动释放内存. 
  delete ptr2;    // 同 malloc, 需要手动释放内存. 
  delete ptr3;    // 同 malloc, 需要手动释放内存. 


  int* ptr4 = new int[5]();              // 申请内存, 申请的大小是:  (int 的大小) * 5! 然后初始化为 0
  int* ptr5 = new int[5]{1,2,3,4,5};     // 申请内存,  申请的大小是:  (int 的大小) * 5! 然后初始化为 1, 2, 3, 4, 5.
  cout << "内存地址: " << ptr4 << " 的值为: " << *ptr4 << endl;  // 打印内容
  cout << "内存地址: " << ptr5 << " 的值为: " << *ptr5 << endl;  // 打印内容

  int (*ptr5_array)[5] = (int(*)[5])ptr5; // 强制转换为数组指针并打印.
  for (auto &&i : *ptr5_array) {
    cout << "数组值: " << i << endl;
  }
  
  delete[] ptr4; // 对于数组, 需要使用 delete[]
  delete[] ptr5; // 记住配对使用： new 对应 delete，new[] 对应 delete[]。类型别名（using 或 typedef）不会改变这个基本规则。
}


int main() {
  fun1();
  fun2();
} 