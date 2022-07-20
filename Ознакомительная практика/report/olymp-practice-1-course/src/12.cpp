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
        int n, m;
        int s = 0;
        cin >> n >> m;
        for (int j = 0; j < n; j++){
            int temp;
            cin >> temp;
            s += temp;
        }
        if (s == m){
            cout << "YES \n";
        }
        else {
            cout << "NO \n";
        }
    }
    return 0;
}