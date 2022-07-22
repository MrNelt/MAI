#include <bits/stdc++.h>



using namespace std;
#define int long long

bool check(vector <int> a, vector <int> b){
  for (int i = 0; i < 101; i++){
    if (a[i] != b[i]){
      return false;
    }
  }
  return true;
}

int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector <int> a(n);
  vector <int> b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  vector <int> temp_set(101);
  vector <int> b_set(101);
  vector <int> answer;
  if (m > n){
    cout << 0 << "\n";
  }
  else {
  for (int i = 0; i < m; i++){
    b_set[b[i]] += 1;
  }
  for (int i = 0; i < m; i++){
    temp_set[a[i]] += 1;
  }
  int counter = 1;
  if (check(temp_set, b_set)){
    answer.push_back(counter);
  }
  for (int i = m; i < n; i++){
    temp_set[a[counter - 1]] -= 1;
    temp_set[a[i]] += 1;
    counter++;
    if (check(temp_set, b_set)){
      answer.push_back(counter);
    }
  }
  cout << answer.size() << "\n";
  for (auto i : answer){
    cout << i << " ";
  }
  cout << "\n";
  }
  return 0;
}