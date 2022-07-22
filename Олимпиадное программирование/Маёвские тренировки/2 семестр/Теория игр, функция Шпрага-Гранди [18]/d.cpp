#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
using graph = vector <vector <int> >;
const unsigned long long INF = 1e18;

int mex(vector<int> a) {
    set<int> b(a.begin(), a.end());
    for (int i=0; ; ++i)
        if (!b.count(i))
            return i;
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
    f[2] = 0;
    f[3] = 1;
    f[4] = 1;
    f[5] = 0;
    for (int i = 6; i <= n; i++){
        vector <int> a;
        for (int j = 1; j * j <= i; j++){
            a.push_back(f[i - j * j]);
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
