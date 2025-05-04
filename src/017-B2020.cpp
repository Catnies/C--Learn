// 某个幼儿园里，有 5 位小朋友编号依次为 1,2,3,4,5 他们按照自己的编号顺序围坐在一张圆桌旁。
// 他们身上有若干糖果，现在他们玩一个分糖果游戏。
// 从 1 号小朋友开始，将自己的糖果均分成 3 份（如果有多余的糖果，就自己立即吃掉），自己留一份，其余两份分给和他相邻的两个小朋友。
// 接着 2,3,4,5 号小朋友也这样做。问一轮结束后，每个小朋友手上分别有多少糖果。
#include <iostream>
using namespace std;

int main() {
  int arr[5];
  for (int& i: arr) cin >> i;
  
  int eated = 0;
  for (int i = 0; i < 5; i++) {
    eated += arr[i] % 3;
    int preAmount = arr[i] / 3;
    arr[(i+4)%5] += preAmount;
    arr[(i+1)%5] += preAmount;
    arr[i] = preAmount;
  }

  for (int i: arr) {
    cout << i << " ";
  }
  cout << endl;
  cout << eated;
  
  return 0;
}