#include <bits/stdc++.h>



using namespace std;
#define int long long


int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector <pair <int, int> > events;
  for (int i = 0; i < n; ++i){
    int l, r;
    cin >> l >> r;
    events.push_back({r, l});
  }
  sort(events.begin(), events.end());
  int rp = events[0].first;
  int ans = 1;
  for (int i = 1; i < n; i++){
    if (events[i].second >= rp){
      ans++;
      rp = events[i].first;
    }
  }
  cout << ans << "\n";
  return 0;
}