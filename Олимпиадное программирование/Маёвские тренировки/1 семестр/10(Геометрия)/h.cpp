#include <bits/stdc++.h>



using namespace std;
#define int long long

double polyar(int x, int y){
    double ans = atan2(y, x);
    return ans;
}

bool cmp(pair <int, int> a, pair <int, int> b){
    return polyar(a.first, a.second) > polyar(b.first, b.second);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    int x_old = 0, y_old = 0;
    int x_now, y_now;
    int ans = 0;
    for (int i = 0; i < n; i++){
        x_now = x_old + a[i].first;
        y_now = y_old + a[i].second;
        if (y_now * y_old < 0){
            int str1 = 0;
            int str2 = 0;
            double ay = y_now - y_old;
            double ax = x_now - x_old;
            double k1 = -y_old / ay;
            double p1 = k1 * ay;
            double p2 = k1 * ax;
            str1 = abs(p1 * p2);
            if (y_old < 0){
                str1 *= -1;
            }
            ans += str1;
            double p3 = ay - p1;
            double p4 = ax - p2;
            str2 = abs(p3 * p4);
            if (y_now < 0){
                str2 *= -1;
            }
            ans += str2;
            //cout << str1 << " " << str2 << "\n";
        }
        else {
            ans += (y_old + y_now) * a[i].first;
        }
        x_old = x_now;
        y_old = y_now;
    }
    cout << ans << "\n";
    return 0;
}