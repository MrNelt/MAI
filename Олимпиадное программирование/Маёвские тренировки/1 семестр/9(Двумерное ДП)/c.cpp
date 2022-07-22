#include <bits/stdc++.h>



using namespace std;
#define int long long


int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector <vector <int>> a(n, vector <int>(n, -1));
  int k = 1;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < k; j++){
      cin >> a[i][j];
    }
    k++;
  }
  vector <vector <int>> dp(n, vector <int>(n));
  dp[0][0] = a[0][0];
  for (int i = 1; i < n; i++){
    for (int j = 0; j < n; j++){
      if (a[i][j] == -1){
        break;
      }
      if (j - 1 < 0){
        dp[i][j] = a[i][j] + dp[i - 1][j];
      }
      else {
        dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
      }
    }
  }
  int maxis = 0;
  for (int i = 0; i < n; i++){
    if (dp[n - 1][i] > maxis){
      maxis = dp[n - 1][i];
    }
  }
  cout << maxis << "\n";
  return 0;
}