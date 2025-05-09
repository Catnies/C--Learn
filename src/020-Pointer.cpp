#include <iostream>
#include <vector>
using namespace std;

// 指针的定义
void fun1() {
  cout << endl << "--- fun1 开始 ---" << endl;

  int a = 20;
  int* b = &a;        // 定义指针 -> 在类型后面添加 * 号, 即可获得该类型的指针对象.
  cout << b << endl;  // 直接打印指针会返回指针的地址值.
  cout << *b << endl; // 在指针变量前面加 * 即可解引用, 将会解析出 &a 的值.
  *b = 16;
  cout << a << " " << *b << endl; // 修改解引用的指针值时, 原变量会一起改变, 因为它们实际上指向的都是同一块内存.
}



// 指针运算
void fun2() {
  cout << endl << "--- fun2 开始 ---" << endl;

  int arr[5] = {1, 2, 3, 4, 5};           // 定义一个数组, 数组是内存连续的.
  int* ptr = arr;                         // 定义一个int类型的指针, 指向数组.  #注意! 这里的arr实际上发生了隐式转换, (int*)arr, 所以可以获得数组的第一个元素的内存起始.#
  *ptr++;                                 // 指针可以进行自增, 每次自增时可以向前移动指针类型数量的字节, 当前为int类型, 所以+1后指针会向前继续移动4个字节.
  cout << "value:" << ptr[1] << endl;     // 也可以使用 下标 运算对其进行增加减少, 并且该操作会自动解引用, 故前面不用加 * , 是c++的语法糖. 
}



// 数组的类型?
void fun3() {
  cout << endl << "--- fun3 开始 ---" << endl;

  int arr[5] = {1, 2, 3, 4, 5};           // 定义一个数组, 数组的类型其实是 元素+长度, 此处为 int[5] .
  int (*ptr)[5] = &arr;                   // 获取数组的指针, 不能直接写 "int *ptr[5] = &arr", 因为这代表是指针类型的数组, 所以需要添加括号, 表示是一个 int[5]* 类型.
  cout << "指针类型: " << typeid(ptr).name() << endl;
  cout << "数组类型: " << typeid(*ptr).name() << endl; // 指针解引用后就是数组, 所以这里返回的是数组的类型.

  using Array5 = int[5];                  // 为了避免前面的弱智写法, 可以使用c++的类型别名功能. 为类型取一个别名, 便可以轻松解决太绕的问题.
  Array5 arr2 = {1, 3, 5, 7, 9};         
  Array5* ptr2 = &arr2;
  cout << "指针类型-2: " << typeid(ptr2).name() << endl;
  cout << "数组类型-2: " << typeid(*ptr2).name() << endl; // 指针解引用后就是数组, 所以这里返回的是数组的类型.
}



// 数组传参实际上是指针!!! 
void fun4(int arr[], int length) {        // 在 C 语言中，数组作为函数参数时，int arr[] 会被自动隐式转换为 int* arr，也就是说：
  cout << endl << "--- fun4 开始 ---" << endl;

  for (int i = 0; i < length; i++) {
    cout << "arr value: " << *arr << endl;
    arr++;
  }
}



// 在函数里传递真正的数组, 实际上就是函数类型需要真正的数组指针.
void fun5(int (*arr)[5]) {
  cout << endl << "--- fun5 开始 ---" << endl;

  for (int &i: *arr) {
    cout << "real arr value: " << i << endl;
  }
}



// C++的自动推断类型, 可以直接推导出数组的引用.
void fun6(auto& arr) {
  cout << endl << "--- fun6 开始 ---" << endl;

  for (auto &i: arr) {
    cout << "auto arr value: " << i << endl;
  }
}



// 二维数组遇到指针
void fun7() {
  cout << endl << "--- fun7 开始 ---" << endl;

  int matrix[2][3];
  int (*ptr)[3] = matrix;       // 当指针直接指向 matrix 时, matrix 会退化成指向大数组(长度2)的第一个元素, 也就是内部的数组(长度3).
  int (*ptr2)[2][3] = &matrix;  // 这个才是指向整个二维数组的指针.

  // 通过这种方法, 先循环外部大数组, 再循环内部小数组的方式遍历整个二维数组.
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ptr[i][j] = i * 4 + j;    // 这里实际上是先处理 (ptr[i]) -> 返回的是大数组中的第 i 个小数组, 然后再使用下标访问第 j 个元素. 
    }
  }

  // 直接去线性遍历数组.
  int* arr = &matrix[0][0];     // 这里实际上是把指针指向二维数组的第一个元素, 因为数组内存是连续的, 所以可以直接线性遍历数组.
  // int* arr = matrix[0];      // 指向大数组的第一个元素(小数组), 然后小数组自动隐式转换为小数组的第一个元素, 其效果和上一行相同.
  for (int i = 0; i < 6; i++) {
    cout << "2d value: " << arr[i] <<endl;
  }
}



// 字符与指针
void fun8(){
  cout << endl << "--- fun8 开始 ---" << endl;

  // 直接输出字符指针并不会得到地址值, 而是会自动尝试解引用指针所指向的地址, 然后不断+1偏移, 直到遇到\0.
  char str[] = "hello";
  char* p = str;
  cout << p << endl;

  // 初始化指针但是没有赋值时实际上会随机分配一个内存地址, 这个内存地址实际上并不一定存在.
  // 结合以上, 所以下面的写法会直接导致程序崩溃, 因为内存地址不存在.
  // char* p;
  // cout << p << endl;

  // 而以下则会出现异常, 因为没有明确的 \0 ,所以最终会一直不断输出乱码.
  char ch = 'a';
  char* p2 = &ch;
  cout << p2 << endl; 
}



// 对象指针
void fun9() {
  cout << endl << "--- fun9 开始 ---" << endl;

  vector<int> vec;
  vector<int>* vecptr = &vec;
  (*vecptr).push_back(1);
  vecptr -> push_back(2); // C++的语法糖, 支持使用 -> 表示解引用 + 访问;
}



// 函数指针 - 在函数中传递函数时, 实际上传递的也是函数指针.
int add(int a, int b) { return a + b; }
void fun10() {
  cout << endl << "--- fun10 开始 ---" << endl;

  int (*ptr)(int, int) = add; // 与数组类似, 可以在前面写函数的返回值, 后面写函数的参数, 即可设置一个指向函数的指针.
  cout << ptr(1, 2) << endl;  // 可以将函数指针当做普通函数一样使用. (感觉有点类似 Kotlin ?)

}



int main() {
  fun1();
  fun2();
  fun3();

  int arr[5] = {1, 2, 3, 4, 5};
  fun4(arr, sizeof(arr) / sizeof(arr[0]));
  fun5(&arr);
  fun6(arr);

  fun7();
  fun8();
  fun9();
  fun10();
}