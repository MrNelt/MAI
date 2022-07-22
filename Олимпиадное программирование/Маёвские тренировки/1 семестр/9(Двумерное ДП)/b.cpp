#include <bits/stdc++.h>



using namespace std;
#define int long long

int solve(int l, int r, vector <vector <int>> &dp, vector <pair <int, int>> &matrix){
  if (dp[l][r] != -1){
    return dp[l][r];
  }
  if (l == r){
    dp[l][r] = 0;
    return 0;

  }
  int res = 1e9;
  for (int k = l; k < r; ++k){
    res = min(res, solve(l, k, dp, matrix) + solve(k + 1, r, dp, matrix) + matrix[l - 1].first * matrix[k - 1].second * matrix[r - 1].second);
  }
  dp[l][r] = res;
  return res;
}

int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector <pair <int, int>> matrix(n);
  for (int i = 0; i < n; i++){
    cin >> matrix[i].first >> matrix[i].second;
  }
  vector <vector <int>> dp(n + 1, vector <int> (n + 1, -1));
  cout << solve(1, n, dp, matrix) << "\n";
  return 0;
  }