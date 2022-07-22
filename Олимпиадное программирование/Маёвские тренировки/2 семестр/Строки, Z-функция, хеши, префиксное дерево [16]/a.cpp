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
    vector <int> z = z_func(s);
    for (int elem : z) {
        cout << elem << " ";
    }
    cout << "\n";
    return 0;
}
