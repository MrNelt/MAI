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

bool lca(int u, int v) {
    if (v == u) {
        return true;
    }
    int delta = d[v] - d[u];
    if (delta < 0) {
        return false;
    }
    for(int i = 0; i < MAX_DEPTH; i++) {
        if (delta & 1) {
            v = up[v][i];
        }

        delta = delta >> 1;
    }
    if (v == u) {
        return true;
    }
    return false;
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int y = 0;
    cin >> y;
    for (int h = 0; h < y; h++) {
        int n;
        cin >> n;
        graph g(n);
        for (int i = 0; i < n - 1; i++){
            int v;
            cin >> v;
            v--;
            g[v].push_back(i + 1);
        }
        int root = 0;
        d.resize(n);
        up.resize(n, vector<int>(MAX_DEPTH));
        dfs(g, root, -1);
        up[root][0] = root;
        for (int i = 1; i < MAX_DEPTH; ++i) {
            for (int u = 0; u < n; ++u) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            }
        }
        int q = 0;
        cin >> q;
        for (int j = 0; j < q; j++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            if (lca(u, v)) {
                cout << "YES \n";
            }
            else {
                cout << "NO \n";
            }
        }
    }
    return 0;

}
