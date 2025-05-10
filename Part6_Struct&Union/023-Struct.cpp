#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// 结构体
void fun1() {
  cout << endl << "--- fun1 开始 ---" << endl;

  // 定义结构体.
  struct Student {
    string name;
    int age;
  };
  Student Zhangsan;         // 声明变量然后赋值.
  Zhangsan.name = "张三";
  Zhangsan.age  = 18;

  // 匿名结构体, 操作与前相同, 但是无法和普通结构体一样正常定义变量.
  struct {
    string name;
    int age;
  } Lisi{.name = "李四"};
  Lisi.age  = 24;
  
  // 可以用 decltype 推导类型声明变量.
  decltype(Lisi) Wangwu{"王五", 20}; 
}


// Pair 结构体
void fun2() {
  cout << endl << "--- fun2 开始 ---" << endl;

  // 可以使用 first 和 second 访问 pair 的元素变量
  pair<string, int> Zhangsan{"张三", 18}; 
  cout << Zhangsan.first << " " << Zhangsan.second << endl;

  // 将 pair 存入 vector 里
  vector<pair<string, int>> students;
  students.emplace_back("李四", 24); // 推荐, 无需使用大括号转义, 且性能更好.
  students.push_back({"王五", 20});
  students.push_back(Zhangsan);

  // 根据年龄排序, 然后打印.
  sort(students.begin(), students.end(), [](pair<string, int> &a, pair<string, int> &b){
      return a.second < b.second;
  });
  for (auto &&i : students) {
    cout << "名字: " << i.first << " 年龄: " << i.second << endl;
  }
  
}



int main() {
  fun1();
  fun2();
} 