#include <bits/stdc++.h>
 
 
 
using namespace std;
using graph = vector<vector<int>>;

#define int long long

vector <string> ans;


void dfs_classic(int u, int prev, graph & g, vector<bool> & visited, int & b, vector <int> &a, bool & flag) {
    if (u != b){
        visited[u] = true;
    }
    if (u == b){
        flag = true;
        string temp = "";
        for (int i : a){
            temp += to_string(i + 1) + "*";
        }    if (u != b){
        visited[u] = true;
    }
        ans.push_back(temp);
    }
    if (u != b){
        for (int v : g[u]) {
            if (!visited[v]) {
                a.push_back(v);
                if (v != prev){
                    dfs_classic(v, u, g, visited, b, a, flag);
                }
                while (a.back() != u){
                    visited[a.back()] = false;
                    a.pop_back();
                }
            }
        }
    }
}

 
void bfs(int u,graph &g, vector<int> &dist, vector <int>& path) {
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
                path[v] = s;
            }
        }
    }
}

void print_graph(graph g, int n){
    for (int i = 0; i < n; i++){
        cout << i + 1 << ": ";
        for (int j : g[i]){
            cout << j + 1 << " ";
        }
        cout << "\n";
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
    for (int i = 0; i < n; i++){
        sort(g[i].begin(), g[i].end());
    }
    vector <int> dist(n, -1);
    vector <int> path(n, -1);
    bfs(a, g, dist, path);
    if (path[b] != - 1){
        int q = dist[b];
        vector <int> answer;
        int temp = b;
        int prev = path[b];
        answer.push_back(b);
        while (q > 0){
            answer.push_back(prev);
            prev = path[prev];
            q--;
        }
        for (int j = answer.size() - 1; j >= 0; j--){
            cout << answer[j] + 1 << " ";
        }
        cout << "\n";
    }
    else if (a == b){
        cout << a + 1 << "\n";
    }
    else {
        cout << -1 << "\n";
    }

    //print_graph(g, n);
    return 0;
}
