// 假设今天是星期日，那么过 a 的 b 次方天之后是星期几？
#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int res = 1;
  while (b--) {
    res *= a;
    res %= 7;
  }
  switch (res) {
    case 0:
      cout << "Sunday" << endl;
      break;
    case 1:
      cout << "Monday" << endl;
      break;
    case 2:
      cout << "Tuesday" << endl;
      break;
    case 3:
      cout << "Wednesday" << endl;
      break;
    case 4:
      cout << "Thursday" << endl;
      break;
    case 5:
      cout << "Friday" << endl;
      break;
    default:
      cout << "Saturday" << endl;
  }
}