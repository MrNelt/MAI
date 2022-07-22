#include <bits/stdc++.h>
 
#define int long long

using namespace std;
using graph = vector <vector <int> >;
const unsigned long long INF = 1e9;
const int MOD = 1e9 + 7;

int solve(graph & g, graph & dp, int mask, int u, int n) {
    if (dp[u][mask] != -1) {
        return dp[u][mask];
    }
    dp[u][mask] = 0;
    for (int v = 0; v < n; ++v) {
        if (g[v][u] != 0 && (mask & (1 << v))) {
            dp[u][mask] += solve(g, dp, mask ^ (1 << u), v, n) * g[v][u];
        }
    }
    return dp[u][mask];
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    
    graph g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    graph dp(n, vector<int>(1 << n, -1));
    int ans = 0;
    for (int i = 0; i < n; i++){
        dp[i][1 << i] = 1;
    }
    for (int i = 0; i < n; i++) {
        ans += solve(g, dp, (1 << n) - 1, i, n);
    }
    cout << ans << "\n";
    return 0;
}
