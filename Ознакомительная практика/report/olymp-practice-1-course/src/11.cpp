#include <bits/stdc++.h>



using namespace std;
#define int long long




int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    int flag = 0;
    vector <int> ans;
    for (int i = 0; i < n; i++){
        if (a[i].first >= m){
            flag = 1;
            break;
        }
        else {
            m += a[i].first;
            ans.push_back(a[i].second);
        }
    }
    if (flag == 0){
        cout << "YES \n";
        for (auto i : ans){
            cout << i << " ";
        }
    }
    else {
        cout << "NO";
    }
    return 0;
}