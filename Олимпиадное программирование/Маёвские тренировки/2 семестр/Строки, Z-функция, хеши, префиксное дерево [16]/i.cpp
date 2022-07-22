#include <bits/stdc++.h>
using namespace std;
    
#define int long long
#define MOD 1000000007
const int MAXN = 1e6;
const int P = 31;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string t, p;
    cin >> p >> t;
    int n = t.size();
    int m = p.size();
    vector<int64_t> pows(MAXN);
    pows[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        pows[i] = (pows[i - 1] * P) % MOD;
    }
    int64_t hash_p = 0;
    for(int i = 0; i < p.size(); ++i) {
        hash_p = (P * hash_p + p[i] - 'a' + 1) % MOD;
    }

    vector<int64_t> hash_t(n + 1);
    for (int i = 1; i <= n; ++i) {
        hash_t[i] = (P * hash_t[i - 1]+ t[i - 1] - 'a' + 1) % MOD;
    }

    int count = 0;
    for (int i = 0; i <= n - m; ++i) {
        int64_t hash_sub = (hash_t[i + m] - (pows[m] * hash_t[i]) % MOD) % MOD;
        hash_sub = (hash_sub + MOD) % MOD;
        if (hash_sub == hash_p) {
        ++count;
        }
    }
    cout << count << "\n";
    return 0;
}
    
