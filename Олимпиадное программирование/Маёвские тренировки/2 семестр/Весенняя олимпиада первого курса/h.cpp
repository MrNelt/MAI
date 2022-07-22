#include <bits/stdc++.h>
 
 
 
using namespace std;
 
#define int long long

using graph = vector < vector < pair<int,int> > >;

const int INF = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int t0 = 0; t0 < t; t0++) {
    int n, m, k, d_m;
    cin >> n >> m >> k >> d_m;
    vector <int> ubej(k);
    for (int k0 = 0; k0 < k; k0++) {
        cin >> ubej[k0];
    }
    cout << "\n";
    graph g(n);
    for (int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        g[y].push_back({x, z});
    }
    vector<int> d (n, INF);
    for (int s0 = 0; s0 < k; s0++){
        int s = ubej[s0];
        s--;
        d[s] = 0;
        set < pair<int,int> > q;
        q.insert (make_pair (d[s], s));
        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase (q.begin());
            for (size_t j=0; j<g[v].size(); ++j) {
                int to = g[v][j].first,
                    len = g[v][j].second;
                if (d[v] + len < d[to]) {
                    q.erase (make_pair (d[to], to));
                    d[to] = d[v] + len;
                    q.insert (make_pair (d[to], to));
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (d[i] <= d_m) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
    }
    return 0;
}
