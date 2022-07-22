#include <bits/stdc++.h>
 
 
 
using namespace std;
 
#define int long long

const int INF = 1e18;


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int t = 2; t <= n; t++){
        for (int k = 0; k < t; k++){
            dp[t] += dp[t - k - 1] * dp[k];
            dp[t] %= m;
        }
    }
    cout << dp[n] % m << "\n";
    return 0;
}
