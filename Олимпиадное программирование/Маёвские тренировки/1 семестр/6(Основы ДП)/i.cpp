#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 100;
    int s = 1000;
    vector <vector <int>> a(n + 1, vector <int>(s));
    for (int j = 0; j <= 9; j++){
        a[1][j] = 1; //суммы с разрядом == 1
    }
    int max_s = 9;
    int mode = 1000000000 + 7;
    for (int i = 2; i <= n; i++){
        max_s += 9;
        a[i][0] = 1;
        for (int j = 1; j <= max_s; j++){
            for (int k = 0; k <= 9; k++){
                if (j - k >= 0){
                    a[i][j] += a[i - 1][j - k];
                    a[i][j] %= mode;
                }
            }
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n0, s0;
        cin >> n0 >> s0;
        cout << a[n0][s0] << "\n";
    }
	return 0;
}