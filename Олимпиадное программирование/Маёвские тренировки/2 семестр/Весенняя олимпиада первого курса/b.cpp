#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;


const int INF = 1000000000;


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(4);
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        a[b - 1]++;
    }
    cout << a[0] / 2 + a[1] / 2 + a[2] / 2 + a[3] / 2 + ((a[0] % 2) & (a[1] % 2) & (a[2] % 2)) << "\n";
    return 0;
}
