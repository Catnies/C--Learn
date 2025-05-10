//给定一个整数 N，判断其正负。如果 N>0, 输出 positive ; 如果 N=0, 输出 zero ; 如果 N<0, 输出 negative。
#include <iostream>
using namespace std;

int main() {
    long long a;
    cin >> a;

    if (a > 0) cout << "positive" << endl; 
    else if (a == 0) cout << "zero" << endl;
    else cout << "negative" << endl;
    
    return 0;
}