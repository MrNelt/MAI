#include <bits/stdc++.h>



using namespace std;
#define int long long


int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s1;
  string s2;

  cin >> s1 >> s2;
  //cout << s1.size() << " " << s2.size() << "\n";
  vector <vector <int>> dp(s1.size() + 1, vector <int>(s2.size() + 1, 0));
  for (int i = 1; i <= s1.size(); i++){
    for (int j = 1; j <= s2.size(); j++){
      int temp = max(dp[i - 1][j], dp[i][j - 1]);
      if (s1[i - 1] == s2[j - 1]){
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else {
        dp[i][j] = temp;
      }
      //cout << dp[i][j] << "\n";
    }

  }
  cout << dp[s1.size()][s2.size()] << "\n";
  return 0;
}