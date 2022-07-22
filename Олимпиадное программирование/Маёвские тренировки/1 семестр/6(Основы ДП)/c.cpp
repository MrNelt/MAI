#include <bits/stdc++.h>
    using namespace std;
     
    #define int long long

     
    int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        int n, k, d;
        cin >> n >> k >> d;

        vector<int> v(n + 1, 0);
        for(int i = 0; i < d; i++){
            int l;
            cin >> l;
            v[l] = -1; 
        }
        v[0] = 1;
        for(int i = 1; i < n + 1; i++){
            if (v[i] != -1){
                for (int p = 1; p < k + 1; p++){
                    if (i - p >= 0){
                        if (v[i - p] != -1)
                            v[i] += v[i - p];
                        
                    }
                    else break;
                }
                v[i] = v[i] % (1000000007);
            }
        }
        cout << v[n];

        return 0; 
    }