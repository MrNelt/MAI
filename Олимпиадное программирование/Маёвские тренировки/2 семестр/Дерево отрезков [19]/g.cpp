#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
using graph = vector <vector <int> >;
const unsigned long long INF = 1e18;

using pii = pair <int, int>;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector <int> prev(n + 1);
    vector <int> dp(n + 1);
    for (int i = 0; i < n; i++){
        prev[i + 1] = prev[i] + a[i];
    }
    for (int i = 0; i < n; i++){
        dp[i + 1] = dp[i] + (i + 1) * a[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] - (l - 1) * (prev[r] - prev[l - 1]) << "\n";
    }
    return 0;
}
