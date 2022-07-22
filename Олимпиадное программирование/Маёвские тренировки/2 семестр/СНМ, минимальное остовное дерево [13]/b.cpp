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
            mini[i] = i + 1;
            maxi[i] = i + 1;
            summ[i] = i + 1;
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
    int n, m;
    cin >> n >> m;
    dsu d(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (d.find(u) != d.find(v)) {
            d.join(u, v);
            int temp = d.find(u);
            cout << d.summ[temp] << " " <<  d.mini[temp] << " " << d.maxi[temp] << "\n";
        }
        else {
            int temp = d.find(u);
            cout << d.summ[temp] << " " <<  d.mini[temp] << " " << d.maxi[temp] << "\n";
        }

    }
    return 0;
}
