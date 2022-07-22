#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
using graph = vector <vector <int> >;
const unsigned long long INF = 1e18;
 
int mex(vector <int> a){
    int n = a.size();
    sort(a.begin(), a.end());
    if (a[0] > 0){
        return 0;
    }
    for (int i = 1; i < n; i++){
        if (a[i - 1] + 1 < a[i]) {
            return a[i - 1] + 1;
        }
    }
    return a.back() + 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    if (n % 2 == 1 && m % 2 == 1) {
        cout << 2 << "\n";
    }
    else {
        cout << 1 << "\n";
    }
    return 0;
}
