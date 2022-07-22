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
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    string text;
    cin >> text;
    string old_text = text;
    text = old_text + text;
    string pattern;
    cin >> pattern;
    string s = pattern + "#" + text;
    //cout << s << "\n";
    int m = pattern.size();
    vector <int> z = z_func(s);
    int ans = 0;
    int findless_gant = 0;
    for (int i = pattern.size() + 2; i < s.size(); i++){
        if (z[i] == m){
            ans++;
            findless_gant = i;
            break;
        }
    }
    if (ans == 0){
        cout << -1 << "\n";
    }
    else {
        int old = old_text.size();
        int a = findless_gant - pattern.size() - 1;
        cout <<old - a<< "\n";
    }
    return 0;
}
