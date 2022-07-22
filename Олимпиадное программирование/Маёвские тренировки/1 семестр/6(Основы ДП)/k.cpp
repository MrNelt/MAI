#include <bits/stdc++.h>

using namespace std;
#define int long long


struct section
{
    int x1;
    int y1;
    int x2;
    int y2;
};

double leng(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2)*((y1 - y2)));
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<section> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }
    vector<vector<double>> dp(n, vector<double>(2));
    dp[0][0] = leng(a[0].x1, a[0].y1, a[0].x2, a[0].y2);
    dp[0][1] = leng(a[0].x1, a[0].y1, a[0].x2, a[0].y2);
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = leng(a[i].x1, a[i].y1, a[i].x2, a[i].y2);
        dp[i][1] = leng(a[i].x1, a[i].y1, a[i].x2, a[i].y2);
        dp[i][1] += min(leng(a[i - 1].x1, a[i - 1].y1, a[i].x1, a[i].y1) + dp[i - 1][0], leng(a[i - 1].x2, a[i - 1].y2, a[i].x1, a[i].y1) + dp[i - 1][1]);
        dp[i][0] += min(leng(a[i - 1].x2, a[i - 1].y2, a[i].x2, a[i].y2) + dp[i - 1][1], leng(a[i - 1].x1, a[i - 1].y1, a[i].x2, a[i].y2) + dp[i - 1][0]);
    }
    cout << setprecision(8);
    cout << min(dp[n - 1][0], dp[n - 1][1]) << "\n";
    return 0;
}