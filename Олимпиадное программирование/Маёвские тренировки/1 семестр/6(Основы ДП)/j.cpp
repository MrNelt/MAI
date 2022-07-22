#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
double loga(int a, int b)
{
    return log(b) / log(a);
}
 
 
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k, m;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> m;
        cout << ceil(loga(3,m))<<"\n";
 
    }
    return 0;
}