#include <bits/stdc++.h>
using namespace std;
#define int long long
 
 
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
 
    int x, y,m=0;
    cin >> y >> x;
    vector<int> a(x + 1, 0);
    a[1] = 1;
    for (int i = 1; i < x + 1; i++) {
        for (int p = i * 2; p < x + 1; p += i) {
            a[p] += a[i];
        }
        a[i] = a[i] % (1000000007);
    }
    m = 0;
    for (int i = y; i < x + 1; i++) {
        m += a[i];
    }
    cout << m % (1000000007);
}