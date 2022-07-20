#include <bits/stdc++.h>
 
 
 
using namespace std;
using graph = vector<vector<int>>;

#define int long long

vector <string> ans;
 
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

 
void bfs_dv(pair <int, int>temp, vector <vector <char>> &enable, vector <vector <int>>& dist, int n, int m) {
    queue<pair<int, int>> q;
    q.push(temp);
    dist[temp.first][temp.second] = 0;
    while(!q.empty()) {
        auto s = q.front();
        q.pop();
        //cout << s.first << " " << s.second << "\n";
        if (s.first + 1 < n && enable[s.first + 1][s.second] != '#' && dist[s.first + 1][s.second] == -1){
            q.push({s.first + 1, s.second});
            dist[s.first + 1][s.second] = dist[s.first][s.second] + 1;
        }
        if (s.first - 1 >= 0 && enable[s.first - 1][s.second] != '#' && dist[s.first - 1][s.second] == -1){
            q.push({s.first - 1, s.second});
            dist[s.first - 1][s.second] = dist[s.first][s.second] + 1;
        }
        if (s.second + 1 < m && enable[s.first][s.second + 1] != '#' && dist[s.first][s.second + 1] == -1){
            q.push({s.first, s.second + 1});
            dist[s.first][s.second + 1] = dist[s.first][s.second] + 1;
        }
        if (s.second - 1 >= 0 && enable[s.first][s.second - 1] != '#' && dist[s.first][s.second - 1] == -1){
            q.push({s.first, s.second - 1});
            dist[s.first][s.second - 1] = dist[s.first][s.second] + 1;
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

void print_chars(vector <vector <char>> a, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int32_t main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <char>> enable(n, vector <char>(m));
    vector <vector <int>> dist(n, vector <int>(m, -1));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> enable[i][j];
        }
    }
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    bfs_dv({a, b}, enable, dist, n, m);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    //print_graph(g, n);
    return 0;
}