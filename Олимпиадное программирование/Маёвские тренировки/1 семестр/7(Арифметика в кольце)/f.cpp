#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		double n, m;
		cin >> n >> m;
		vector <int> a(n);
		vector <int> b(m);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < m; i++){
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int l, h;
		cin >> l >> h;
		double count = 0;
		double answer = 0;
		for (int i = 0; i < n; i++){
			auto t1 = lower_bound(b.begin(), b.end(), l - a[i]);
			auto t2 = upper_bound(b.begin(), b.end(), h - a[i]);
			answer += (t2 - t1);
		}
		cout << setprecision(100);
		double g = answer / (n * m);
		cout << g << "\n";

	return 0;
}