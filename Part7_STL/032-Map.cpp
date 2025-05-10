#include <algorithm>
#include <iostream>
#include <chrono>
#include <format>
#include <random>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

/**
 * map            有序  唯一
 * multimap       有序  不唯一
 * unordered_map  无序  唯一
 * 
 * insert   -> 复制并插入
 * erase    -> 删除元素 
 * find     -> 查找, 但是查找的是 Key , 如找到返回迭代器, 未找到则返回 end 迭代器.
 * []       -> 查找 key 对应的值.
 */
int main() {
  map<string, int> mp;
  multimap<string, int> mmp;
  unordered_map<string, int> ump;      // 创建对象

  ump.insert({"ZhangSan", 114});             // 插入数据
  ump.insert(make_pair("LiSi", 514));   
  ump.emplace("WangWu", 1919);
  cout << ump.size() << endl;  // 打印长度

  // 查找Map中的数据, 其中find方法会返回对应元素的迭代器, 如果没找到则返回末尾的迭代器.
  if (auto iter = ump.find("LiSi"); iter != ump.end()) {
    cout << iter -> first << " " << iter -> second << endl;
  }

  // 直接查找输出
  cout << ump["ZhangSan"] << endl;

  // 注意, 当使用下标查找的值不存在时, 会在map内尝试插入一个新的. 所以map的大小会增加.
  cout << ump["unknown"] << endl;
  cout << ump.size() << endl;     // 打印长度

  // 遍历
  for (auto &&[k, v] : ump) {
    cout << k << " " << v << endl;
  }
  

}