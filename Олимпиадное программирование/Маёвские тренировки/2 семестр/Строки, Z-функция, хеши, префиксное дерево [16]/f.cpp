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
    int res = 0;
    string s_temp = "";
    for (int i = 0; i < s.size(); i++){
        s_temp = s[i] + s_temp;
        vector <int> z = z_func(s_temp);
        int maxis = 0;
        for (int j = 1; j < z.size(); j++){
            if (z[j] > maxis){
                maxis = z[j];
            }
        }
        int v = s_temp.size();
        res += (v - maxis);
    }
    cout << res << "\n";
    return 0;
}
