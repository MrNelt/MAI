#include <bits/stdc++.h>



using namespace std;
#define int long long
#define INF 10000000000

int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int co = 0; co < t; co++){
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
  	vector <int> d(n + 1);
  	vector <int> pos(n + 1);
  	vector <int> prev(n);
  	int length = 0;

  	pos[0] = -1;
  	d[0] = -INF;

  	for (int i = 1; i <= n; i++)
  		d[i] = INF;

  	for (int i = 0; i < n; i++)
  	{
  		int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();

  		if (d[j - 1] < a[i] && a[i] < d[j])
  		{
  			d[j] = a[i];
  			pos[j] = i;
  			prev[i] = pos[j - 1];
  			length = max(length, j);
  		}
  	}

  	//восстановление ответа
  	vector <int> answer;
  	int p = pos[length];

  	while (p != -1){
  		answer.push_back(p);
  		p = prev[p];
  	}
    cout << answer.size() << "\n";
  	reverse(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++){
      cout << answer[i] + 1 << " ";
    }
    cout << "\n";
  }
}