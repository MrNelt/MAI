#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
using graph = vector <vector <int> >;
const unsigned long long INF = 1e18;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    //cout << (1 << n) << "\n";
    int ans = -1;
    for (int i = 0; i < (1 << n); i++){
        int temp_ans = -1;
        int counter = 0;
        for (int j = 0; j < n; j++){
            if ((i >> j) & 1) {
                counter++;
                if (temp_ans == -1){
                    temp_ans = a[j];
                }
                else {
                    temp_ans ^= a[j];
                }
            }
        }
        if (counter == k) {
            ans = max(ans, temp_ans);
        }
    }
    cout << ans << "\n";
}