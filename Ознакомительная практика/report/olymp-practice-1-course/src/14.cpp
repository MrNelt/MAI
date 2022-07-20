#include <bits/stdc++.h>
 
 
 
using namespace std;
 
#define int long long

using graph = vector < vector < pair<int,int> > >;

const int INF = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    int s = 0;
    vector<int> d (n, INF),  p (n);
	d[s] = 0;
	set < pair<int,int> > q;
	q.insert (make_pair (d[s], s));
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase (q.begin());
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				q.erase (make_pair (d[to], to));
				d[to] = d[v] + len;
				p[to] = v;
				q.insert (make_pair (d[to], to));
			}
		}
	}
        int t = n - 1;
        if (d[t] == INF){
            cout << -1 << "\n";
        }
        else {
            vector<int> path;
            for (int v=t; v!=s; v=p[v])
                path.push_back (v);
            path.push_back (s);
            reverse (path.begin(), path.end());
            for (int b = 0; b < path.size(); b++){
                cout << path[b] + 1 << " ";
            }
            cout << "\n";
        }
    return 0;
}