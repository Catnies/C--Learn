#include <iostream>
using namespace std;

int main() {
  double price[] = {28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};
  int arr[10];
  for (int& i: arr) cin >> i;
  
  double sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += arr[i] * price[i];
  }

  cout << fixed;
  cout.precision(1);
  cout << sum << endl;
  
  return 0;
} 