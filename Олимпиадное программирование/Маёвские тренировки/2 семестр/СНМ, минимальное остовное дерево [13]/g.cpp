#include <bits/stdc++.h>
 
 
 
using namespace std;
 
#define int long long

using graph = vector < vector < pair<int,int> > >;
struct edge {
    int u, v, w;
};

bool operator < (const edge & lhs, const edge & rhs) {
    return lhs.w < rhs.w;
}

struct dsu {
    vector <int> leader;
    vector <int> size;
    dsu (int n) {
        leader.resize(n);
        for (int i = 0; i < n; i++){
            leader[i] = i;
        }
        size.resize(n, 1);
    }
    int find(int u) {
        if (leader[u] == u) {
            return u;
        }
        int v = find(leader[u]);
        leader[u] = v;
        return v;
    }
    void join(int u, int v) {
        int lead_u = find(u);
        int lead_v = find(v);
        if (lead_u == lead_v) {
            return ;
        }
        if (size[lead_u] > size[lead_v]) {
            leader[lead_v] = lead_u;
            size[lead_u] += size[lead_v];
        } else {
            leader[lead_u] = lead_v;
            size[lead_v] += size[lead_u];
        }
    }
};


const int INF = 1000000000;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <edge> g;
    for (int i = 0; i < n; i++){
        int cost;
        cin >> cost;
        g.push_back({i, n, cost});
    }
    for (int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        g.push_back({x, y, z});
        //g.push_back({y, x, z});
    }
    sort(g.begin(), g.end());
    dsu d(n + 1);
    int ans = 0;
    for (int i = 0; i < g.size(); i++){
        int u = g[i].u;
        int v = g[i].v;
        int w = g[i].w;
        if (d.find(u) != d.find(v)) {
            d.join(u, v);
            //cout << u + 1 << " " <<  v + 1 << "\n";
            ans += g[i].w;
        }
    }
    cout << ans << "\n";
    return 0;
}
