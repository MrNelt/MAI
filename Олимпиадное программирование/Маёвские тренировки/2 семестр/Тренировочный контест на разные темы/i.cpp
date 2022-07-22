#include <bits/stdc++.h>
 
 
 
using namespace std;
#define int long long


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    vector <int> d(n);
    for (int i = 0; i < n; i++){
        d[i] = a[i] - b[i];
    }
    sort(d.begin(), d.end());
    int ans = 0;
    for (int i = 0; i < n; i++){
        int g = d[i];
        ans += d.end() - upper_bound(d.begin() + i + 1, d.end(), -g);
    }
    cout << ans << "\n";
    return 0;
}
