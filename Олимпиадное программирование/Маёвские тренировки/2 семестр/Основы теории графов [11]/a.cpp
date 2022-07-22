#include <bits/stdc++.h>
 
 
 
using namespace std;
using graph = vector<vector<int>>;

#define int long long


void dfs_classic(int u, graph & g, vector<bool> & visited, int & i, vector <int> & a) {
    visited[u] = true;
    for (int v : g[u]) {
        if (!visited[v]) {
            a[v] = i + 1;
            i++;
            dfs_classic(v, g, visited, i, a);
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
    int n, m, k;
    cin >> n >> m >> k;
    k--;
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
    vector <int> a(n, -1);
    a[k] = 0;
    int i = 0;
    dfs_classic(k, g, visited, i, a);
    for (int i : a){
        cout << i << " ";
    }
    return 0;
}
