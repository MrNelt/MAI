#include <bits/stdc++.h>



using namespace std;
#define int long long


int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  for (int counter = 0; counter < q; counter++){
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    set <int> b;
    int l = 0;
    int r = 1;
    int maxis = 0;
    b.insert(a[0]);
    while (r != n){
      if (b.count(a[r]) == 0){
        b.insert(a[r]);
        r++;
      }
      else {
        b.erase(a[l]);
        l++;
      }
      //cout << l << " " << r << "\n";
      maxis = max(maxis, r - l);
    }
    cout << maxis << "\n";
  }
  return 0;
}