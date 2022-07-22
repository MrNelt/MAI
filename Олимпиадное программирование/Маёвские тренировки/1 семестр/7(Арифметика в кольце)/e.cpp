#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
int bin_pow(int a, int n, int mod) {
    int res = 1;
    while (n > 0) {
        if (n % 2 == 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n /= 2;
    }
    return res;
}
 
int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i != 0){
            continue;
        }
        while (n % i == 0) {
            n /= i;
        }
        res = (res - res / i);
    }
    if (n > 1){
        res = (res - res / n);
    }
    return res;
}
 
 
int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int mod = 1000000000 + 7;
    for (int i = 0; i < t; i++){
        int b1, q, n;
        cin >> b1 >> q >> n;
        if (n >= 2){
            if (q > 1){
                int s1 = ((b1 % mod) * (1 - bin_pow(q, n, mod))) % mod;
                int inv_a = bin_pow(1 - q, mod - 2, mod);
                cout <<(s1 * inv_a) % mod << "\n";
            }
            else if (q == 1){
                cout << ((b1 % mod) * (n % mod)) % mod << "\n";
            }
            else {
                cout << b1 % mod << "\n";
            }
 
        }
        else {
            cout << b1 % mod << "\n";
        }
    }
 
	return 0;
}