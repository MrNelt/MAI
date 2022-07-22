#include <bits/stdc++.h>
 
 
#define int long long


using namespace std;
 
using pii = pair <int, int>;

using graph = vector <vector <int> >;



void bfs(int u,graph &g, vector<int> &dist, vector <int> &path) {
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


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int h = 0; h < q; h++) {
        int n;
        cin >> n;
        graph g(n);
        for (int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int u_b = 0;
        vector <int> path1(n, -1);
        vector <int> path2(n, -1);
        vector <int> dist1(n, -1);
        vector <int> dist2(n, -1);
        bfs(u_b, g, dist1, path1);
        int u_max = 0;
        int maxis = 0;
        for (int i = 0; i < n; i++) {
            if (dist1[i] > maxis) {
                maxis = dist1[i];
                u_max = i;
            }
        }
        bfs(u_max, g, dist2, path2);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dist2[i] > ans) {
                ans = dist2[i];
            }
        }
        cout << ans << "\n";
    }
}
