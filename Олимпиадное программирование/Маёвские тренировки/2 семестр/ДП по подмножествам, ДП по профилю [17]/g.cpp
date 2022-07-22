#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
using graph = vector <vector <int> >;
const unsigned long long INF = 1e18;
const int MOD = 1e9 + 7;


bool possible(int mask1, int mask2, int m) {
    vector<bool> good(m);
    for (int i = 0; i < m; i++) {
        if (mask1 & (1 << i)) {
            good[i] = true;
        }
    }
    for (int i = 0; i < m; i++) {
        int bit1 = mask1 & (1 << i);
        int bit2 = mask2 & (1 << i);
        if (bit1 && bit2) {
            return false;
        }
        if (bit2 && !bit1) {
            good[i] = true;
        }
    }
    for (int i = 0; i < m - 1; i++) {
        if (!good[i] && !good[i + 1]) {
            good[i] = true;
            good[i + 1] = true;
        }
    }
    for (int i = 0; i < m; i++) {
        if (!good[i]) {
            return false;
        }
    }
    return true;
}


int32_t main() {
    int n;
    cin >> n;
    
    int m;
    cin >> m;

    graph can(1 << m, vector<int>(1 << m));
    for (int mask1 = 0; mask1 < (1 << m); ++mask1) {
        for (int mask2 = 0; mask2 < (1 << m); ++mask2) {
            can[mask1][mask2] = possible(mask1, mask2, m);
        }
    }

    graph dp(n + 1, vector<int>(1 << m));
    dp[0][0] = 1;

    for (int i = 1; i < n + 1; ++i) {
        for (int mask1 = 0; mask1 < (1 << m); ++mask1) {
            for (int mask2 = 0; mask2 < (1 << m); ++mask2) {
                dp[i][mask1] +=(dp[i - 1][mask2] * can[mask2][mask1]) % MOD;
            }
        }
    }
    int ans = dp.back()[0];
    cout << ans % MOD << "\n";
    return 0;
}
