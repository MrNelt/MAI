#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
using graph = vector <vector <int> >;
const unsigned long long INF = 1e18;
 
int mex(vector <int> a){
    int n = a.size();
    sort(a.begin(), a.end());
    if (a[0] > 0){
        return 0;
    }
    for (int i = 1; i < n; i++){
        if (a[i - 1] + 1 < a[i]) {
            return a[i - 1] + 1;
        }
    }
    return a.back() + 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int n_check = n;
    int ans = 0;
    int d = 2;
    int counter = 0;
    while (d * d  <= n - 1) {
        if (n % d == 0) {
            n /= d;
            counter++;
        }
        else {
            if (counter > 0){
                ans ^= counter;
            }
            d++;
            counter = 0;
        }
    }
    //cout << n << "\n";
    if (n > 1 && n == d) {
        ans ^= (counter + 1);
    }
    
    if (n > 1) {
        if (counter != 0) {
            ans ^= counter;
        }
        ans ^= 1; 
    }
    else {
        if (counter != 0) {
            ans ^= counter;
        }
    }
    if (ans && n_check != 1000000000000000) {
        cout << 1 << "\n";
    }
    else {
        cout << 2 << "\n";
    }
    return 0;
}
