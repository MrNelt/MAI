#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans = a[0],
        ans_l = 0,
        ans_r = 0,
        sum = 0,
        min_sum = 0,
        min_pos = -1;
        for (int r = 0; r < n; ++r) {
            sum += a[r];

            int cur = sum - min_sum;
            if (cur > ans) {
                ans = cur;
                ans_l = min_pos + 1;
                ans_r = r;
            }

            if (sum < min_sum) {
                min_sum = sum;
                min_pos = r;
            }
        }
        if (ans > 0){
          cout << ans_l + 1 << " " << ans_r + 2 << "\n";
        }
        else {
          cout << -1 << " " << -1 << "\n";
        }
    return 0;
}