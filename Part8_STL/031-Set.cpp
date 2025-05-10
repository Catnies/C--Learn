#include <algorithm>
#include <iostream>
#include <chrono>
#include <format>
#include <random>
#include <set>
#include <unordered_set>
using namespace std;


/**
 * set            有序  唯一
 * multiset       有序  不唯一
 * unordered_set  无序  唯一
 * 
 * insert   -> 复制并插入
 * erase    -> 删除元素 
 * find     -> 查找, 如找到返回迭代器, 未找到则返回 end 迭代器.
 * count    -> 查找元素是否存在, 返回 true or false.
 * 
 * 有序 元素支持 <
 * 无序 元素支持 hash
 */
int main() {
  unordered_set<int> us;      // 创建对象
  us.insert(114);             // 插入数据
  us.emplace(514);
  cout << us.size() << endl;  // 打印长度

  // 查找集合中的数据, 其中find方法会返回对应元素的迭代器, 如果没找到则返回末尾的迭代器.
  if (auto iter = us.find(114); iter != us.end()) {
    cout << *iter << endl;
  }

  if (us.count(514)) {
    cout << "元素存在!" << endl;
  }
}