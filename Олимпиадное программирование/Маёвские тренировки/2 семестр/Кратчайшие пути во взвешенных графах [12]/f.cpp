#include <bits/stdc++.h>
 
 
 
using namespace std;
 
#define int long long

using graph = vector < vector < pair<int,int> > >;

const int INF = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    graph g(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int cost;
            cin >> cost;
            if (cost >= 0){
                g[i].push_back({j, cost});
            }
        }
    }
    for (int t = 0; t < q; t++){
        int s;
        cin >> s;
        s--;
        vector<int> d (n, INF),  p (n);
        d[s] = 0;
        vector<char> u (n);
        for (int i=0; i<n; ++i) {
            int v = -1;
            for (int j=0; j<n; ++j)
                if (!u[j] && (v == -1 || d[j] < d[v]))
                    v = j;
            if (d[v] == INF)
                break;
            u[v] = true;
            for (int j=0; j<g[v].size(); ++j) {
                int to = g[v][j].first,
                    len = g[v][j].second;
                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                }
            }
        }
        for (int p = 0; p < n; p++){
            if (d[p] != INF){
                cout << d[p] << " ";
            }
            else {
                cout << "-1" << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
