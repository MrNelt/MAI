#include <bits/stdc++.h>

using namespace std;
#define int long long

int factmod (int n, int p) {
	int res = 1;
	while (n > 1) {
		res = (res * ((n/p) % 2 ? p-1 : 1)) % p;
		for (int i=2; i<=n%p; ++i)
			res = (res * i) % p;
		n /= p;
	}
	return res % p;
}
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
    int n, m;
    cin >> n >> m;
    int s = factmod(n + m, mod);
    
    int a1 = bin_pow(factmod(n, mod), mod - 2, mod);
    int a2 = bin_pow(factmod(m, mod), mod - 2, mod);
    int answer = ((s * a1) % mod * a2) % mod;
    cout << answer << "\n";
	return 0;
}