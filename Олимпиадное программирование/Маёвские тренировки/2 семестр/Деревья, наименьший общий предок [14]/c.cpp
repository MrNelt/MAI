#include <bits/stdc++.h>
 
 
#define int long long


using namespace std;
 
using pii = pair <int, int>;

using graph = vector <vector <int> >;


const int MAX_DEPTH = 21;

vector<vector<int>> up;
vector<int> d;

void dfs(const graph & g, int u, int prev) {
    for (int v : g[u]) {
        if (v != prev) {
            d[v] = d[u] + 1;
            up[v][0] = u;
            dfs(g, v, u);
        }
    }
}

int lca(int u, int v) {
    if (v == u) {
        return u;
    }
    if (d[v] < d[u]) {
        swap(u, v);
    }
    int delta = d[v] - d[u];
    for(int i; i < MAX_DEPTH; i++) {
        if (delta & 1) {
            v = up[v][i];
        }

        delta = delta >> 1;
    }
    if (v == u) {
        return u;
    }
    for (int i = MAX_DEPTH - 1; i >= 0; --i) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[v][0];
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int t0 = 0; t0 < t; t0++){
        int n;
        cin >> n;
        graph g(2 * n);
        d.resize(2 * n);
        up.resize(2 * n, vector<int>(MAX_DEPTH));
        for (int i = 0; i < n; i++){
            char operation;
            int u, v;
            cin >> operation >> v >> u;
            u--;
            v--;
            if (operation == '+') {
                d[u] = d[v] + 1;
                up[u][0] = v;
                for (int i = 1; i < MAX_DEPTH; ++i) {
                    up[u][i] = up[up[u][i - 1]][i - 1];
                }

            }
            else if (operation == '?') {
                cout << lca(u, v) + 1 << "\n";
            }
        }
    }
    return 0;
}
