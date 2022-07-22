#include <bits/stdc++.h>

    //for (int i = 0; i < n;)
    // for (int i = 0; i < m; i++){
    //     int u, v;
    //     cin >> u >> v;
    //     u--;
    //     v--;
    //     g[u].push_back(v);
    // }

using namespace std;
#define int long long

using pii = pair <int, int>;

using graph = vector <vector <int> >;

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

bool dfs_kuhn(graph &g, int u, vector <int> &matching, vector <bool> &visited) {
    if (visited[u]) {
        return false;
    }
    visited[u] = true;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (matching[v] == -1 || dfs_kuhn(g, matching[v], matching, visited)){
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
    vector <vector <int>> a(n, vector <int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    graph g(n * m);
    int counter = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){

            if (i - 1 >= 0){
                if (a[i - 1][j] != a[i][j]) {
                    g[counter].push_back(counter - m);
                }
            }
            if (i + 1 < n) {
                if (a[i + 1][j] != a[i][j]) {
                    g[counter].push_back(counter + m);
                }
            }
            if (j - 1 >= 0){
                if (a[i][j - 1] != a[i][j]) {
                    g[counter].push_back(counter - 1);
                }
            }
            if (j + 1 < m) {
                if (a[i][j + 1] != a[i][j]) {
                    g[counter].push_back(counter + 1);
                }
            }
            counter++;
        }
    }
    // for (int i = 0; i < n * m; i++){
    //     cout << i << ": ";
    //     for (int j : g[i]){
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
    vector <int> dist(n * m, -1);
    for (int i = 0; i < n * m; i++){
        if (dist[i] == -1) {
            bfs(i, g, dist);
        }
    }
    graph g1(n * m);
    for (int i = 0; i < n * m; i++) {
        for (int j : g[i]) {
            if (dist[i] % 2 == 0){
                g1[i].push_back(j);
            }
        }
    }
    vector <int> matching(n * m, -1);
    for (int i = 0; i < n * m; ++i){
        vector <bool> visited(n * m);
        dfs_kuhn(g1, i, matching, visited);
    }
    // for (int i = 0; i < n * m; i++){
    //     if (matching[i] != -1) {
    //         cout << i << " " << matching[i] << "\n";
    //     }
    // }
    counter = 0;
    vector <vector <int>> ans(n, vector <int>(m));
    for (int i = 0; i < n * m; ++i){
        if (matching[i] != -1){
            int brick1 = matching[i];
            int brick2 = i;
            int x1 = brick1 / m;
            int y1 = brick1 - x1 * m;
            int x2 = brick2 / m;
            int y2 = brick2 - x2 * m;
            ans[x1][y1] = counter + 1;
            ans[x2][y2] = counter + 1;
            counter++;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
