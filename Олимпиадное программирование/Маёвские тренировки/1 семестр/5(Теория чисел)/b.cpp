#include <bits/stdc++.h>
using namespace std;
#define int long long 
 
 
int func1(int x, int y) {
    return x == 0 ? y : func1(y % x, x);
}
 
int func2(int x, int y) {
    return x / func1(x, y) * y;
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
 
    vector<int> a(n), a1(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    a1[0] = 1;
 
    for (int i = 0; i < n - 1; i++) {
        a1[i + 1] = func2(a[i], a[i + 1]);
        a1[i + 1] = func2(a1[i], a1[i + 1]);
    }
 
    cout << a1[n - 1]; 
}