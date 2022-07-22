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
    int t;
    cin >> t;
    for (int t0 = 0; t0 < t; t0++) {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> enable(n, vector <int>(m, 0));
    dsu d(n * m);
    int ans = 0;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int key = y * n + x;
        ans++;
        enable[x][y] = 1;
        if (x > 0) {
            int key1 = x - 1 + y * n;
            if (enable[x - 1][y] == 1) {
                if (d.find(key1) != d.find(key)) {
                    d.join(key, key1);
                    ans--;
                }
            }
        }
        if (x < n - 1) {
            int key2 = x + 1 + y * n;
            if (enable[x + 1][y] == 1) {
                if (d.find(key2) != d.find(key)) {
                    d.join(key, key2);
                    ans--;
                }
            }
        }
        if (y > 0) {
            int key3 = x + (y - 1) * n;
            if (enable[x][y - 1] == 1) {
                if (d.find(key3) != d.find(key)) {
                    d.join(key, key3);
                    ans--;
                }
            }
        }
        if (y < m - 1) {
            int key4 = x + (y + 1) * n;
            if (enable[x][y + 1] == 1) {
                if (d.find(key4) != d.find(key)) {
                    d.join(key, key4);
                    ans--;
                }
            }
        }
        cout << ans << "\n";
    }
    }
    return 0;
}
