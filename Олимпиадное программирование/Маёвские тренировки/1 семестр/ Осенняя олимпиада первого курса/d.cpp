#include <bits/stdc++.h>



using namespace std;
#define int long long




int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int t0 = 0; t0 < t; t0++){
        int n, k;
        cin >> n >> k;
        vector <int> a(n);
        vector <int> b(k);
        int u = 0;
        int temp = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            u += a[i];
        }
        for (int i = 0; i < k; i++){
            cin >> b[i];
            temp += b[i];
        }
        if (temp >= u){
            cout << n << "\n";
            continue;
        }
        int begin = 0;
        int answer = 0;

            while (temp){
                if (a[begin % n] != 0){
                    a[begin % n] -= 1;
                    if (a[begin % n] == 0){
                        answer++;
                    }
                    temp--;
                }
                begin++;
            }
        cout << answer << "\n";
    }
    return 0;
}