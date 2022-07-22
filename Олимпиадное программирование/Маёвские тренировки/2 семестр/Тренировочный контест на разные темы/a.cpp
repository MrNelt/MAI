#include <bits/stdc++.h>
 
 
 
using namespace std;
#define int long long


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if (a % b == 0){
            cout << 0 << "\n";
        }
        else {
        int temp = a / b;
        int c = b;
        b += c * temp;
        cout << b - a << "\n";
        }
    }
    return 0;
}
