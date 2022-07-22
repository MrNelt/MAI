#include <iostream>
#include <iomanip>
#include <cmath>
//2a1 + d(n - 1) / 2 * n

using namespace std;
int main(){
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long w = (x1 + x2 - 1) / x2;
    long long h = (y1 + y2 - 1) / y2;
    cout << w * h;
    
    return 0;
}