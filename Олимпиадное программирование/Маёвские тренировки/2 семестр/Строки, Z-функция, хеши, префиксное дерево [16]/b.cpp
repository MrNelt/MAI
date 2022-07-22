#include <bits/stdc++.h>
 
#define int long long

using namespace std;

vector <int> z_func(const string & s) {
    int n = s.size();
    vector <int> z(n);
    int l = -1, r = -1;
    z[0] = n;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i);
        }
        while (l + z[i] < n && s[z[i]] == s[i + z[i]]){
            ++z[i];
        }
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
    return z;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string text;
    cin >> text;
    string pattern;
    cin >> pattern;
    string s = pattern + "#" + text;
    int m = pattern.size();
    vector <int> z = z_func(s);
    int ans = 0;
    for (int i = m; i < s.size(); i++){
        if (z[i] == m){
            ans++;
        }
    }
    if (ans == 0){
        cout << "NIE\n";
    }
    else {
        cout << "TAK\n";
        cout << ans << "\n";
    }
    return 0;
}
