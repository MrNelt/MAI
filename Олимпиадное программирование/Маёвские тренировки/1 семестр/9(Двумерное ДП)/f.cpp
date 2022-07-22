#include <bits/stdc++.h>



using namespace std;
#define int long long

int solve(int n, int m, vector <vector <int>>& a, vector <vector <int>>& dp, int nn, int mm){
  if (dp[n][m] != -100){
    return dp[n][m];
  }
  if (n - 2 >= 0 && m + 1 < mm){
    dp[n - 2][m + 1] = solve(n - 2, m + 1, a, dp, nn, mm);
    if (dp[n - 2][m + 1] > 0){
      dp[n][m] = max(dp[n][m], dp[n - 2][m + 1] + a[n][m]);
    }
  }
  if (n - 2 >= 0 && m - 1 >= 0){
    dp[n - 2][m - 1] = solve(n - 2, m - 1, a, dp, nn, mm);
    if (dp[n - 2][m - 1] > 0){
      dp[n][m] = max(dp[n][m], dp[n - 2][m - 1] + a[n][m]);
    }
  }
  if (n - 1 >= 0 && m - 2 >= 0){
    dp[n - 1][m - 2] = solve(n - 1, m - 2, a, dp, nn, mm);
    if (dp[n - 1][m - 2] > 0){
      dp[n][m] = max(dp[n][m], dp[n - 1][m - 2] + a[n][m]);
    }
  }
  if (n + 1 < nn && m - 2 >= 0){
    dp[n + 1][m - 2] = solve(n + 1, m - 2, a, dp, nn, mm);
    if (dp[n + 1][m - 2] > 0){
      dp[n][m] = max(dp[n][m], dp[n + 1][m - 2] + a[n][m]);
    }
  }
  if (dp[n][m] == -100){
    dp[n][m] = 0;
  }
  return dp[n][m];
}


int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector <vector <int>> a(n, vector <int>(m, -100));
  vector <vector <int>> dp(n, vector <int>(m, -100));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  int maxis = 0;
  dp[0][0] = a[0][0];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      dp[i][j] = solve(i, j, a, dp, n, m);
      if (dp[i][j] > maxis){
        maxis = dp[i][j];
      }
    }
  }
  cout << maxis << "\n";
  return 0;
}