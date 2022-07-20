#include <bits/stdc++.h>



using namespace std;
#define int long long



int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <pair <int, int>> a;
    set <pair <int, int>> s;
    int answer = 0;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
        s.insert({x, y});
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int d = (a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second);
            int x1 = a[i].first - a[j].first;
            int y1 = a[i].second - a[j].second;
            int dx = y1;
            int dy = -x1;

            int x_a1 = a[i].first + dx;
            int y_a1 = a[i].second + dy;
            int x_a2 = a[j].first + dx;
            int y_a2 = a[j].second + dy;

            int x_b1 = a[i].first - dx;
            int y_b1 = a[i].second - dy;
            int x_b2 = a[j].first - dx;
            int y_b2 = a[j].second - dy;
            if ((s.count({x_a1, y_a1}) && s.count({x_a2, y_a2})) || (s.count({x_b1, y_b1}) && s.count({x_b2, y_b2}))){
                if (d > answer){
                    answer = d;
                }
            }
        }
    }
    cout << answer << "\n";
    return 0;
}