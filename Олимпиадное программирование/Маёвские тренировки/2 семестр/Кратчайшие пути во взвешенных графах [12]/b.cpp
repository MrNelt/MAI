#include <bits/stdc++.h>
 
 
 
using namespace std;
 
#define int long long

const int INF = 1e18;


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    vector <vector <int>> dp(n, vector <int>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j =0; j < n; j++){
            cin >> dp[i][j];
        }
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    
    //вывод ответов
    return 0;
}
