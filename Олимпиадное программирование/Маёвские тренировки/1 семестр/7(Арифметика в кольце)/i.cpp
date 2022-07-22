#include <bits/stdc++.h>

using namespace std;
#define int long long

int faqtorial(int n,int p){
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
		int n, k;
		cin >> n >> k;
		int mod = 1000000000 + 7;
		int res = 1;

		if (n - k > 0){
		res *= faqtorial(n, mod);
		res *= bin_pow(faqtorial(n - k, mod), mod - 2, mod);
		res %= mod;
		res *= bin_pow(faqtorial(k, mod), mod - 2, mod);
		res %= mod;
	}
		while (k > 0 && n > 0){
			res *= n;
			res %= mod;
			n--;
			k--;
		}
		if (k == 0){
		cout << res % mod << "\n";
		}
		else {
			cout << 0 << "\n";
		}
		return 0;
}