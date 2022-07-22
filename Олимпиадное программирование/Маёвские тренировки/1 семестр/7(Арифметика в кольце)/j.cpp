#include <bits/stdc++.h>

using namespace std;
#define int long long


int mod = 1000000000 + 7;


vector <vector <int>> multiply(vector <vector <int>> M1, vector <vector <int>> M2){
	int a11, a12, a21, a22;
	a11 = (M1[0][0] % mod) * (M2[0][0] % mod) % mod + (M1[0][1] % mod) * (M2[1][0] % mod) % mod;
	a12 = (M1[0][0] % mod) * (M2[0][1] % mod) % mod + (M1[0][1] % mod) * (M2[1][1] % mod) % mod;
	a21 = (M1[1][0] % mod) * (M2[0][0] % mod) % mod + (M1[1][1] % mod) * (M2[1][0] % mod) % mod;
	a22 = (M1[1][0] % mod) * (M2[0][1] % mod) % mod + (M1[1][1] % mod) * (M2[1][1] % mod) % mod;
	return {{a11 % mod, a12 % mod}, {a21 % mod, a22 % mod}};
}


vector <vector <int>> binpow(vector <vector <int>> a, int n) {
	if (n == 0){
			return {{1, 0}, {0, 1}};
	}
	if (n % 2 == 1){
		return multiply(binpow(a, n - 1), a);
	}
	else {
		auto b = binpow(a, n / 2);
		return multiply(b, b);
	}
}


int32_t main(){
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		int t;
		cin >> t;
		for (int i = 0; i < t; i++){
			int n;
			cin >> n;
			vector <vector <int>> a = {{1, 1}, {1, 0}};
			auto b = binpow(a, n);
			cout << b[0][1] << "\n";
		}
		return 0;
}