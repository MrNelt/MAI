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
int C(int a, int b, int mod){
  int s1 = factmod(b, mod);
  int s2 = bin_pow(factmod(a, mod), mod - 2, mod);
  int s3 = bin_pow(factmod(abs(b - a), mod), mod - 2, mod);
  return (((s1 * s2) % mod) * s3) % mod;
}

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int mod = 1000000000 + 7;
    int n, m;
    cin >> n >> m;
    int s1 = (C(n - m, 2 * n - m, mod) * 2) % mod; 
    int s2 = bin_pow(2, (n * 2 - m + 1), mod);
    cout << (s1 * bin_pow(s2, mod - 2, mod)) % mod;
	return 0;
}