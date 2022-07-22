#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int> >a(n, vector <int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int temp;
            cin >> temp;
            a[i][j] = temp;
        }
    }
    for (int i = 1; i < n; i++){
        a[i][0] = a[i - 1][0] + a[i][0];
    }
    for (int j = 1; j < m; j++){
        a[0][j] = a[0][j - 1] + a[0][j];
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            vector <int> grando(3);
            grando[0] = a[i - 1][j];
            grando[1] = a[i][j - 1];
            grando[2] = a[i - 1][j - 1];
            int maxis = 0;
            for (auto k : grando){
                if (k > maxis){
                    maxis = k;
                }
            }
            a[i][j] = maxis + a[i][j];
        }
    }
    cout << a[n - 1][m - 1];
	return 0;
}