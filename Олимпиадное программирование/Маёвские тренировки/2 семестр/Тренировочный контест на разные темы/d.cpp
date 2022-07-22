#include <bits/stdc++.h>
 
 
 
using namespace std;
#define int long long


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector <int> a(n);
        for (int j = 0; j < n; j++){
            cin >> a[j];
        }
        int ans = 0;
        int min = a[n - 1];
        for (int j = n - 1; j >= 0; j--){
            if (a[j] > min){
                ans++;
            }
            else {
                min = a[j];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
