#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <double> a(n);
    vector <double> b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int giant = 0;
    for (int i = 0; i < n; i++){
        cin >> b[i];
        giant += b[i];

    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    double s = 0;
    for (int i = 0; i < n; i++){
        s += a[i] * b[i] / giant;
    }
    cout << setprecision(10);
    cout << s << "\n";
	return 0;
}