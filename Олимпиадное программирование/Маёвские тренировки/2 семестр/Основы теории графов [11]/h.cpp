#include <bits/stdc++.h>
 
 
 
using namespace std;
using graph = vector<vector<int>>;

#define int long long

vector <vector <int>> multy(const vector <vector <int>> a1, const vector <vector <int>> a2, int mod){
    int n = a1.size();
    vector <vector <int>> a(n, vector <int>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                a[i][j] += (a1[i][k] * a2[k][j]) % mod;
                a[i][j] %= mod;
            }
        }
    }
    return a;
}

vector <vector <int>> e_matrix(int n){
    vector <vector <int>> a(n, vector <int>(n, 0));
    for (int i = 0; i < n; i++){
        a[i][i] = 1;
    }
    return a;
}

void print_vector(const vector <vector <int>> a){
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a.size(); j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}


vector <vector <int>> binpow(vector <vector <int>> a, int n, int mod) {
	if (n == 0)
		return e_matrix(a.size());
	if (n % 2 == 1)
		return multy(binpow (a, n - 1, mod), a, mod);
	else {
		auto b = binpow (a, n / 2, mod);
		return multy(b, b, mod);
	}
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int mod = 1000000000 + 7;
    int t;
    cin >> t;
    for (int v = 0; v < t; v++){
        int n, m, k;
        cin >> n >> m >> k;
        graph g(n);
        for (int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            g[u].push_back(v);
        }
        vector <vector <int>> dp(n, vector <int>(n, 0));
        for (int i = 0; i < n; i++){
            for (int j : g[i]){
                dp[i][j] = 1;
            }
        }
        auto ans = binpow(dp, k, mod);
        cout << ans[0][0] << "\n";
    }
    return 0;
}
