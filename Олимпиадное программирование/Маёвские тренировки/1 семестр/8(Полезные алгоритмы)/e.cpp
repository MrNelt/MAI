#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int s = 0;
  for (int i = 0; i < n; i++){
    int maxis = a[i];
    for (int j = i; j < n; j++){
      maxis = max(maxis, a[j]);
      s += maxis;
    }
  }
  cout << s << "\n";
  return 0;
}