#include <bits/stdc++.h>
 
 
 
using namespace std;
using graph = vector<vector<int>>;

#define int long long


void dfs_classic(int u, int prev, graph & g, vector<bool> & visited, int & b, vector <int> &a, bool & flag) {
    visited[u] = true;
            if (u == b && !flag){
                flag = true;
                for (int i : a){
                    cout << i + 1 << " ";
                }
            }
    for (int v : g[u]) {
        if (!visited[v]) {
            a.push_back(v);
            if (v != prev){
                dfs_classic(v, u, g, visited, b, a, flag);
            }
            if (!flag){
                while (a.back() != u){
                    a.pop_back();
                }
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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--;
    b--;
    graph g(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <bool> visited(n);
    vector <int> t;
    t.push_back(a);
    bool flag = false;
    dfs_classic(a,-1, g, visited, b, t, flag);
    if (!flag){
        cout << -1;
    }
    cout << "\n";
    return 0;
}
