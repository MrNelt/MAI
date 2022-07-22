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
        g[v].push_back(u);
    }
    vector <int> dist(n, -1);
    for (int i = 0; i < n; i++){
        if (dist[i] == -1) {
            bfs(i, g, dist);
        }
    }
    bfs(0, g, dist);
    bool flag = false;
    graph g1(2 * n);
    int k1 = 0;
    int k2 = 0;
    for (int i = 0; i < n; i++){
        for (int v : g[i]) {
            if (dist[v] == dist[i]) {
                flag = true;
            }
            if (dist[i] % 2 == 0) {
                g1[i].push_back(v);
            }
            else {
            }
        }
    }
    if (flag) {
        cout << -1 << "\n";
    }
    else {
    int ans = 0;
    vector <int> matching(2 * n, -1);
    for (int i = 0; i < n; ++i){
        vector <bool> visited(n);
        if (dfs_kuhn(g1, i, matching, visited)){
            ans++;
        }
    }
    cout << ans << "\n"; 
        for (int i = 0; i < n; ++i){
            if (matching[i] != -1) {
                cout << matching[i] + 1 << " " << i + 1 << "\n";
            }
        }
    }
    return 0;
}
