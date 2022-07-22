#include <bits/stdc++.h>
 
 
 
using namespace std;
 
#define int long long

using graph = vector < vector < pair<int,int> > >;
struct edge {
    int w, u, v;
};

bool operator < (const edge & lhs, const edge & rhs) {
    if (lhs.w != rhs.w) {
        return lhs.w < rhs.w;
    }
    if (lhs.u != rhs.u) {
        return lhs.u < rhs.u;
    }
    return lhs.v < rhs.v;
}

struct dsu {
    vector <int> leader;
    vector <int> size;
    vector <int> mini;
    vector <int> maxi;
    vector <int> summ;
    dsu (int n) {
        leader.resize(n);
        mini.resize(n);
        maxi.resize(n);
        summ.resize(n);
        for (int i = 0; i < n; i++){
            leader[i] = i;
            mini[i] = i;
            maxi[i] = i;
            summ[i] = i;
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
            mini[lead_u] = min(mini[lead_v], mini[lead_u]);
            maxi[lead_u] = max(maxi[lead_v], maxi[lead_u]);
            summ[lead_u] += summ[lead_v];
            leader[lead_v] = lead_u;
            size[lead_u] += size[lead_v];

        } else {
            mini[lead_v] = min(mini[lead_v], mini[lead_u]);
            maxi[lead_v] = max(maxi[lead_v], maxi[lead_u]);
            summ[lead_v] += summ[lead_u];
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
    int n;
    cin >> n;
    vector <int> points(n);
    for (int i = 0; i < n; i++){
        cin >> points[i];
    }
    sort(points.begin(), points.end());
    vector <edge> g;
    for (int i = 1; i < n; i++){
        g.push_back({points[i] - points[i - 1], i - 1, i});
    }
    sort(g.begin(), g.end());
    // for (int i = 0; i < g.size(); i++){
    //     cout << g[i].w << " " << g[i].u << " " << g[i].v << "\n";
    // }
    dsu d(n);
    for (int i = 0; i < g.size(); i++){
        int u = g[i].u;
        int v = g[i].v;
        cout << points[d.mini[d.find(u)]] << " " << points[d.maxi[d.find(u)]] << " " << points[d.mini[d.find(v)]] << " " << points[d.maxi[d.find(v)]] << "\n";
        d.join(u, v); 
    }
    return 0;
}
