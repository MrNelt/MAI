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
    dsu d(n);
    vector <pair <int, int>> q(m);
    int ans = n;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        q[i] = {u, v};
    }
    vector <int> answers(m);
    answers[0] = n;
    for (int i = m - 1; i >= 1; i--){
        int u = q[i].first;
        int v = q[i].second;
        if (d.find(u) != d.find(v)){
            d.join(u, v);
            answers[i] = --ans;
        }
        else {
            answers[i] = ans;
        }
    }
    for (int i = 1; i < m; i++){
        cout << answers[i] << "\n";
    }
    cout << answers[0] << "\n";

    return 0;
}