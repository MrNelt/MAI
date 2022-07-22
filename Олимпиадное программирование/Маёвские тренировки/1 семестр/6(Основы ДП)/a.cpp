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
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            if (i - j >= 0){
                a[i] += a[i - j];
                auto s = a[i];
                s %= 1000000000 + 7;
                a[i] = s;
            }
        }
    }
    auto s = a[n];
    s %= 1000000000 + 7;
    cout << s << "\n";
	return 0;
}