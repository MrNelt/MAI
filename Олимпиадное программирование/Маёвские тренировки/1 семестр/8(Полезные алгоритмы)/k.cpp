#include <bits/stdc++.h>



using namespace std;
#define int long long


int32_t main(){
  ///ios::sync_with_stdio(false);
  //cin.tie(0);
  //cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector <int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int s = 0;
  for (int i = 0; i < n; i++){
    int j = upper_bound(a.begin(), a.end(), a[i] + k) - a.begin();
    //cout << j << "\n";
    if (j - i - 2 > 0){
      s += ((j - i - 1) * (j - i - 2)) / 2;
    }
  }
  cout << s << "\n";
  return 0;
}