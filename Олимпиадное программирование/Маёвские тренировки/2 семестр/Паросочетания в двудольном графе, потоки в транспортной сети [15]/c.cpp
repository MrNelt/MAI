#include <bits/stdc++.h>
using namespace std;
    

 
using pii = pair<int, int>;
using graph = vector<vector<int64_t>>;
using Wgraph = vector<vector<pair<int, int>>>;


const unsigned long long INF = 1e18;

void build_network(int u, const graph & g, vector<int> & d, int n) {
    d[u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int v = 0; v < n; ++v) {
            if (!g[u][v]) {
                continue;
            }
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int64_t dfs_push(int u, int finish, graph & g, const vector<int>& d, vector<int> &ptr, int n, int64_t flow) {
    if (u == finish) {
        return flow;
    }
    for (; ptr[u] < n; ++ptr[u]) {
        int v = ptr[u];
        if (d[v] != d[u] + 1) {
            continue;
        }
        if (!g[u][v]) {
            continue;
        }
        int64_t edge = g[u][v];
        int64_t pushed = dfs_push(v, finish, g, d, ptr, n, min(flow, edge));
        if (pushed) {
            g[u][v] -= pushed;
            g[v][u] += pushed;
            return pushed;
        }
    }
    return 0;
}

int64_t find_max_flow(graph & g, int n) {
    int64_t res = 0;
    while (true) {
        vector<int> d(n, -1);
        build_network(0, g, d, n);
        if (d[n - 1] == -1) {
            break;
        }
        vector<int> ptr(n);
        while (true) {
            int64_t flow = dfs_push(0, n - 1, g, d, ptr, n, INF);
            if (flow) {
                res += flow;
            } else {
                break;
            }
        }
    }
    return res;
}

    
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int m;
    cin >> m;
    graph g(n, vector<int64_t>(n));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int64_t c;
        cin >> c;
        --u;
        --v;
        g[u][v] += c;
    }
    int64_t flow = find_max_flow(g, n);
    cout << flow << "\n";
    return 0;
}
