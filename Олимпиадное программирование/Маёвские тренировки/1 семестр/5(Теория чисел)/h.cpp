#include <bits/stdc++.h>

using namespace std;
#define int long long


int gcd(int a, int b) {
return a == 0 ? b : gcd(b % a, a);
}


int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int dx;
		int dy;
		dx = 0 - x1;
		dy = 0 - y1;
		x2 += dx;
		y2 += dy;
		if (x2 == 0 && y2 == 0){
			cout << 1 << "\n";
		}
		else if (x2 == 0){
			cout << abs(y2) + 1 << "\n";
		}
		else if (y2 == 0){
			cout << abs(x2) + 1 << "\n";
		}
		else {
			cout << gcd(abs(x2), abs(y2)) + 1 << "\n";
		}

	}
	return 0;
}