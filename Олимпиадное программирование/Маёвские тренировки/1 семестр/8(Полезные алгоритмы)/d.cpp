#include <bits/stdc++.h>
 
using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector <pair <int, int> > events;
    for (int i = 0; i < q; ++i){
        int l, r, v;
        cin >> l >> r >> v;
        events.push_back({l, v});
        events.push_back({r + 1, -v});
    }
    sort(events.begin(), events.end());
    int count = 0;
    vector <int> a(n);
    int j = 0;
    for (int i = 0; i < n; ++i){
        while (j < 2 * q && events[j].first <= i + 1){
            count = count + events[j].second;
            ++j;
        }
        a[i] = count;
    }
    for (int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }
    return 0;
}