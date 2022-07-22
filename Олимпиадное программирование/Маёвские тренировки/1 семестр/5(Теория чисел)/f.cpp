#include <bits/stdc++.h>

using namespace std;
#define int long long

int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

bool find_any_solution (int a, int b, int c, int & x0, int & y0, int & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}

int gcd1(int a, int b) {
return a == 0 ? b : gcd1(b % a, a);
}

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int x = 0, y = 0, g = 0;
        int a, b, c;
        cin >> a >> b >> c;
        int g1 = gcd1(a, b);
        if (c % g1 != 0){
            cout << -1 << "\n";
        }
        else {
            find_any_solution(a, b, c, x, y, g);
            cout << g1 << " " << x << " " << y << "\n";

        }

    }
	return 0;
}