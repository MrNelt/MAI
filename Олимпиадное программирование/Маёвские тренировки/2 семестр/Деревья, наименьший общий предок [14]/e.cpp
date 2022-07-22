#include <bits/stdc++.h>
 
 
#define int long long


using namespace std;
 
using pii = pair <int, int>;

using graph = vector <vector <int> >;


const int MAX_DEPTH = 21;


int binpow (int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		int b = binpow (a, n/2);
		return b * b;
	}
}

int lca(int u, int v, vector <int> &d, vector <vector <int>> &up) {
    if (v == u) {
        return u;
    }
    if (d[v] < d[u]) {
        swap(u, v);
    }
    int delta = d[v] - d[u];
    for (int i = 0; i < MAX_DEPTH; i++) {
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
    vector <int> diam(2, -1);
    diam[0] = 0;
    vector <int> d(n, -1);
    d[0] = 0;
    int prev = 0;
    vector <vector <int>> up(n, vector <int>(MAX_DEPTH, 0));
    //cout << "--------------------\n";
    for (int y = 1; y < n; y++){
        int u;
        cin >> u;
        u--;
        int v = y;
        if (d[v] == -1){
            swap(u, v);
        }
        d[u] = d[v] + 1;
        up[u][0] = v;
        for (int i = 1; i < MAX_DEPTH; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        if (y == 1){
            diam[1] = u;
            int obsh_gant = lca(0, u, d, up);
            prev = d[u] - d[obsh_gant];
            cout << prev << "\n";
        }
        else {
            int obsh_gant1 = lca(u, diam[0], d, up);
            int obsh_gant2 = lca(u, diam[1], d, up);
            int rast1 = abs(d[obsh_gant1] - d[u]) + abs(d[obsh_gant1] - d[diam[0]]);
            int rast2 = abs(d[obsh_gant2] - d[u]) + abs(d[obsh_gant2] - d[diam[1]]);
            //cout << "ДИАМЕТР: " << diam[1] << " " << diam[0] << " ОБЩИЕ ГАНТЫ ПОСЛЕДОВАТЕЛЬНО " << obsh_gant1 << " " << obsh_gant2 << "\n";
            int temp1 = diam[0];
            int temp2 = diam[1];
            if (rast1 > prev){
                prev = rast1;
                diam[0] = u;
                diam[1] = temp1;
            }
            if (rast2 > prev){
                prev = rast2;
                diam[0] = u;
                diam[1] = temp2;
            }
            cout << prev << "\n";
        }
        //cout << "ДИАМЕТРЫ : " << diam[0] << " " << diam[1] << "\n";
        }
    }
    return 0;
}
