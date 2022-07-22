#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
using graph = vector <vector <int> >;
const unsigned long long INF = 1e18;
 
int mex(vector <int> a){
    int n = a.size();
    sort(a.begin(), a.end());
    if (a[0] > 0){
        return 0;
    }
    for (int i = 1; i < n; i++){
        if (a[i - 1] + 1 < a[i]) {
            return a[i - 1] + 1;
        }
    }
    return a.back() + 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    vector <int> f(n + 10);
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++){
        vector <int> a;
        a.push_back(f[i - 2]);
        for (int j = 2; j < i; j++){
            a.push_back(f[j - 2] ^ f[i - j - 1]);
        }
        f[i] = mex(a);
    }
    if (f[n] > 0) {
        cout << 1 << "\n";
    }
    else {
        cout << 2 << "\n";
    }
    return 0;
}
