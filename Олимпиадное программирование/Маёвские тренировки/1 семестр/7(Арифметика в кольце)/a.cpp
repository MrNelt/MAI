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


int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int mod = 1000000000 + 7;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        cout << bin_pow(a, b, mod) << "\n";
    }
	return 0;
}