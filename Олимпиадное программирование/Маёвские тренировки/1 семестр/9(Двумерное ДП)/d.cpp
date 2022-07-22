#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n + 1);
    a[0] = 1;
    vector <int> p(n + 1);
    for (int i = 1; i <= n; i++){
        p[i] = (p[i - 1] % (1000000000 + 7) + a[i - 1]) % (1000000000 + 7);
        p[i] %= (1000000000 + 7);
        if (i - k < 0){
          a[i] = (p[i] - p[0] + 1000000000 + 7) % (1000000000 + 7);
        }
        else {
          a[i] = (p[i] - p[i - k] + 1000000000 + 7) % (1000000000 + 7);
        }
        a[i] %= (1000000000 + 7);

    }
    auto s = a[n];
    s %= (1000000000 + 7);
    cout << s << "\n";
	return 0;
}