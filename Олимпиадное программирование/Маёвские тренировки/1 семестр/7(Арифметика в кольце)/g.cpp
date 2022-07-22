#include <bits/stdc++.h>

using namespace std;
#define int long long


int Mod(int a, int b){
	return abs(((a % b) + b) % b);
}

int bin_pow(int a, int n, int mod) {
		int res = 1;
		while (n > 0) {
				if (n % 2 == 1)
						res = Mod((res * a), mod);
				a = Mod((a * a), mod);
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
		int a, m;
		cin >> a >> m;
		int inv_a = bin_pow(a, phi(m) - 1, m);
		if (Mod(Mod(inv_a, m) * Mod(a, m), m) == 1){
			cout << inv_a;
		}
		else {
			cout << -1;
		}
	return 0;
}