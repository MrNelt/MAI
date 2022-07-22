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
    string s;
    cin >> s;
    string s_reversed = "";
    for (int i = s.size() - 1; i >= 0; i--){
        s_reversed += s[i];
    }
    string sek = s + "#" + s_reversed;
    int ans = 0;
    auto z = z_func(sek);
    for (int i = s.size() + 1; i < sek.size(); i++){
        if (i - s.size() - 1 + z[i] == s.size()){
            if (z[i] > ans){
                ans = z[i];
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
