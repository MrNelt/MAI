#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n + 1, 0);
    a[1] = 0;
    a[2] = 2;
    for (int i = 3; i <= n; i++){
        if (i % 3 == 0 && i % 2 != 0){
            a[i] += min(a[i / 3], a[i - 1]) + i;

        }
        else if (i % 2 == 0 && i % 3 != 0){
            a[i] += min(a[i / 2], a[i - 1]) + i;
        }
        else if (i % 2 == 0 && i % 3 == 0) {
            auto temp = min(a[i / 3], a[i / 2]);
            a[i] += min(temp, a[i - 1]) + i;
        }
        else {
            a[i] += a[i - 1] + i;
        }
    }
    cout << a[n];
	return 0;
}