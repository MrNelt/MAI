#include <bits/stdc++.h>



using namespace std;
#define int long long


int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int counter = 0;
  for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
          if (counter % 2 == 0){
              cout << ".";
          }
          else {
              cout << "#";
          }
      }
      cout << "\n";
      counter++;
  }
  return 0;
}