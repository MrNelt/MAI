#include <bits/stdc++.h>
using namespace std;

#define int long long



double distance(int x, int y, int x1, int y1, int x2, int y2) {
    if (((x2 - x1) ^ 2 + (y2 - y1) ^ 2) == 0){
        return 0;
    }
    else {
        return abs((x - x1) * (y2 - y1) - (y - y1) * (x2 - x1)) / sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    double s = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2, x, y;
        cout << setprecision(10);
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        cout << distance(x, y, x1, y1, x2, y2) << "\n";
    }
    return 0;
}