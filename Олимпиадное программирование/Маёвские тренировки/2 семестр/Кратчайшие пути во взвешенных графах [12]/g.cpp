#include <bits/stdc++.h>
 
 
 
using namespace std;
 
#define int long long

using graph = vector < vector < pair<int,int> > >;

const int INF = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    graph g(n);
    for (int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    vector<int> d(n, -1);
    d[s] = INF;
    vector<char> u(n);
	set < pair<int,int> > q;
	q.insert (make_pair (d[s], s));
	while (!q.empty()) {
		int v = (--q.end())->second;
		q.erase (--q.end());
        for (int j = 0; j < g[v].size(); ++j)
        {
            int to = g[v][j].first,
                len = g[v][j].second;
            if (min(d[v], len) > d[to])
            {
                q.erase (make_pair (d[to], to));
                d[to] = min(d[v], len);
				q.insert (make_pair (d[to], to));
            }
        }
    }
    for (int t = 0; t < n; t++){
        if (t == s){
            cout << "-1" << " ";
        }
        else if (d[t] == -1){
            cout << "0" << " ";
        }
        else {
            cout << d[t] << " ";
        }
    }
    cout << "\n";
    return 0;
}
