#include <bits/stdc++.h>


#define int long long

using namespace std;     
    int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n, answer = 0;
        cin >> n;
        string temp, gik;
        for (int i = 0; i < n; i++){
            cin >> temp >> gik;
        }
        cin >> temp >> gik;
        if (temp.size() > gik.size()){
            while (temp.size() > gik.size())
                gik += '_';
        }
        else{
            while (temp.size() < gik.size())
                temp += '_';
        }
        for (int i = 0; i < temp.size(); i++){
            int c1 = 0;
            if (gik[i] == '_') c1 = 1;
            else if (temp[i] == '_') c1 = -1;
            answer += gik[i] - temp[i] + c1;
        }
        cout << answer;
        return 0;
    }