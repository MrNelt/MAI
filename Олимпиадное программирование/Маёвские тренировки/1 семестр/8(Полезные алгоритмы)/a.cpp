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
    vector <int> b(n + 1, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        b[i + 1] = b[i] + a[i + 1];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    cout << b[r - 1] - b[l - 1] + a[l - 1] << "\n";
    }

    return 0;
}