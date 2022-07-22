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
        events.push_back({l, 1});
        events.push_back({r + 1, -1});
    }
    sort(events.begin(), events.end());
    int count = 0;
    int ans = 0;
    int y = 0;
    int lp = -1e9;
    for (int i = 0; i < 2 * n; ++i){
        count = count + events[i].second;
        if (count > 0 && lp == -1e9){
            lp = events[i].first;
        }
        if (count == 0){
            y += events[i].first - lp;
            lp = -1e9;
        }
    }
    cout << y << "\n";
    return 0;
}