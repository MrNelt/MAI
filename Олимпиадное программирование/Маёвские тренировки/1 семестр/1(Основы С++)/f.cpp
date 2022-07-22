#include <iostream>
#include <iomanip>
#include <cmath>
//2a1 + d(n - 1) / 2 * n

using namespace std;
int main(){
    long long a, b, s;
    cin >> a >> b;
    s = 0;
    cout << (a + b) * (max(a, b) - min(a, b) + 1) / 2;
    return 0;
}