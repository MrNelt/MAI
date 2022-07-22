#include <bits/stdc++.h>



using namespace std;
#define int long long


int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  vector <int> b(n + 1);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  for (int i = 0; i < n; i++){
    b[i + 1] = b[i] + a[i];
  }
  int s = 0;
  for (int i = 1; i < n + 1; i++){
    s += (i * b[i] - (n + 1 - i) * b[i - 1]);
  }
  cout << s << "\n";
  return 0;
}