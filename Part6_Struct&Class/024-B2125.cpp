#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, string>> students(n);
  for (int i = 0; i < n; i++) {
    int socre;
    string name;
    cin >> socre >> name;
    students.emplace_back(socre, name);
  }

  cout << max_element(students.begin(), students.end()) -> second << endl;
} 