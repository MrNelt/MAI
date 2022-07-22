#include <bits/stdc++.h>
 
 
 
using namespace std;
using graph = vector<vector<int>>;

#define int long long

set <int> ans;

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


void dfs(int u, int previous, const graph & g, vector<int> & color, vector <int> &path, bool flag)
{
    if (flag){
        return;
    }
    if (color[u] == 1 && !flag){
        flag = true;
        vector <int> answer;
        path.pop_back();
        while (path.back() != u){
            if (color[path.back()] != 2){
                ans.insert(path.back() + 1);
            }
            path.pop_back();
        }
        ans.insert(path.back() + 1);
        return;
    }
    color[u] = 1;
    for (int v : g[u]) {

        if (v != previous && !flag) {
            path.push_back(v);
            dfs(v, u, g, color, path, flag);
        }
        else if (flag){
            return;
        }
    }
    color[u] = 2;
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
    int n;
    cin >> n;
    graph g(n);
    for (int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector <bool> visited(n);
    vector <int> color(n, 0);
    vector <int> path;
    bool flag = false;
    path.push_back(0);
    dfs(0, -1, g, color, path, flag);
    for (int j : ans){
        cout << j << " ";
    }
    cout << "\n";
    return 0;
}
