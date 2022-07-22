#include <bits/stdc++.h>
 
 
 
using namespace std;
using graph = vector<vector<int>>;

#define int long long


void dfs_classic(int u, graph & g, vector<bool> & visited, vector <int> & dp, vector <int> &path) {
    visited[u] = true;
    for (int v : g[u]) {
        if (!visited[v]) {
            dfs_classic(v, g, visited, dp, path);
            if (dp[v] + 1 > dp[u]){
                dp[u] = dp[v] + 1;
                path[u] = v;
            }
        }
        else {
            if (dp[v] + 1 > dp[u]){
                dp[u] = dp[v] + 1;
                path[u] = v;
            }
        }
    }
}

 
void bfs(int u,graph &g, vector<int> &dist) {
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while(!q.empty()) {
        int s = q.front();
        q.pop();
        for(int v: g[s]) {
            if(dist[v] == -1) {
                q.push(v);
                dist[v] = dist[s] + 1;
            }
        }
    }
}


int32_t main(){
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
    vector <int> dp(n);
    vector <bool> visited(n);
    vector <int> path(n, -1);
    for (int i = 0; i < n; i++){
        dfs_classic(i, g, visited, dp, path);
    }
    int q = 0;
    int begin = 0;
    for (int i = 0; i < n; i++){
        if (dp[i] > q){
            q = dp[i];
            begin = i;
        }
    }
    cout << q + 1 << "\n";
    cout << begin + 1 << " ";
    int prev = path[begin];
    while (q > 0){
        cout << prev + 1 << " ";
        prev = path[prev];
        q--;
    }
    cout << "\n";
    return 0;
}
