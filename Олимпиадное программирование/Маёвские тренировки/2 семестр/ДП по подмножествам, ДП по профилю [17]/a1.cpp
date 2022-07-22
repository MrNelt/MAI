#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
using graph = vector <vector <int> >;
const unsigned long long INF = 1e18;


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    
    graph g(n, vector<int>(n));
    for (int i =0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    int ans = 1e12;
    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
            perm[i] = i;
    }
    do {
        int w = 0;
        for (int i = 1; i < n; ++i) {
            w += g[perm[i - 1]][perm[i]];
        }
        if (perm[0] == 0){
            ans = min(ans, w);
        }
    } while (next_permutation(perm.begin(), perm.end()));
    cout << ans << "\n";
    return 0;
}
