#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
using graph = vector <vector <int> >;
const unsigned long long INF = 1e18;
const int MOD = 1e9 + 7;

bool possible(int mask1, int mask2, int m) {
    for(int i = 0; i < m - 1; i++) {
        if ((mask1 & 3) == (mask2 & 3) && ((mask1 & 3) == 0 || (mask1 & 3) == 3)) {
            return false;
        }
        mask1 = mask1 >> 1;
        mask2 = mask2 >> 1;
    }
    return true;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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

    graph dp(n, vector<int>(1 << m));
    for (int mask = 0; mask < (1 << m); ++mask) {
        dp[0][mask] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int mask1 = 0; mask1 < (1 << m); ++mask1) {
            for (int mask2 = 0; mask2 < (1 << m); ++mask2) {
                dp[i][mask1] += (dp[i - 1][mask2] * can[mask2][mask1]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << m); ++mask) {
        ans += dp.back()[mask];
        ans %= MOD;
    }
    cout << ans % MOD << "\n";
    return 0;
}
