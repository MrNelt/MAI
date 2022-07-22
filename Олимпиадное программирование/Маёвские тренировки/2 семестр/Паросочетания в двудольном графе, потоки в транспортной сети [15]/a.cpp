#include <bits/stdc++.h>

using namespace std;
#define int long long

using pii = pair <int, int>;

using graph = vector <vector <int> >;

bool dfs_kuhn(graph &g, int u, vector <int> &matching, vector <bool> &visited) {
    if (visited[u]) {
        return false;
    }
    visited[u] = true;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (matching[v] == -1 or dfs_kuhn(g, matching[v], matching, visited)){
            matching[v] = u;
            return true;
        }
    }
    return false;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    int ans = 0;
    vector <int> matching(n, -1);
    for (int i = 0; i < n; ++i){
        vector <bool> visited(n);
        if (dfs_kuhn(g, i, matching, visited)){
            ans++;
        }
    }
    cout << ans << "\n"; 
        for (int i = 0; i < n; ++i){
            if (matching[i] != -1) {
                cout << matching[i] + 1 << " " << i + 1 << "\n";
            }
        }
    return 0;
}
