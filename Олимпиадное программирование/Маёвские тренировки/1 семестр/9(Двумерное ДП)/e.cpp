#include <bits/stdc++.h>



using namespace std;
#define int long long


int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for (int ci = 0; ci < t; ci++){
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int> (m));
    vector <vector <int>> dp(n, vector <int> (m));
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < m; i++){
      dp[0][i] = a[0][i];
    }
    for (int i = 1; i < n; i++){
      for (int j = 0; j < m; j++){
        dp[i][j] = max(dp[i - 1][j], a[i][j]);
        for (int k = 1; k < m; k++){
          if (j - k >= 0){
            dp[i][j] = max(dp[i][j], a[i][j - k] + dp[i - 1][k - 1]);
          }
          else {
            break;
          }
        }
      }
    }
    cout << dp[n - 1][m - 1] << "\n";
  }

  return 0;
}