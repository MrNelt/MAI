#include <bits/stdc++.h>



using namespace std;
#define int long long

#define PI 3.1415926535

int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++){
    double x, y;
    cin >> x >> y;
    cout << setprecision(10);
    double ans = atan2(y, x);
    if (ans < 0){
      ans = atan2(-y, -x) + PI;
    }
    cout << ans << "\n";
  }
  return 0;
}