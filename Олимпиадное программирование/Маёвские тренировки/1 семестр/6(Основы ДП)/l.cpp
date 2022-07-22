#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> dp(n + 100);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 3] + 1; 
    }
    cout << dp[n];
	return 0;
}