#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
void print(vector <vector <int>> a, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
    cout << "\n";
    }
    cout << "\n";
}


int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    n++;
    m++;
    vector <vector <int> > a(n, vector <int> (m, 0));
 
    for (int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        a[x][y] = -100;
 
    }
    for (int i = 0; i < n; i++){
        if (a[i][0] == -100){
            break;
        }
        a[i][0] = 1;
    }
    for (int j = 0; j < m; j++){
        if (a[0][j] == -100){
            break;
        }
        a[0][j] = 1;
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (a[i][j] < 0){
                continue;
            }
            if (a[i - 1][j]> 0){
                a[i][j] += a[i - 1][j];
            }
            if (a[i][j - 1]> 0){
                a[i][j] += a[i][j - 1];
            }
            auto s = a[i][j];
            s %= 1000000000 + 7;
            a[i][j] = s;
        }
 
    }
    //print(a, n, m);
    auto s = a[n - 1][m - 1];
    s %= 1000000000 + 7;
    if (s > 0){
        cout << s << "\n";
    }

    else {
        cout << 0;
    }
	return 0;
}