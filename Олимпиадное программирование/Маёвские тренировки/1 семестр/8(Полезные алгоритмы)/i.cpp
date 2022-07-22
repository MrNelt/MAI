#include <bits/stdc++.h>



using namespace std;
#define int long long


int mod(int a, int b){
  return (a % b + b) % b;
}

int bin_pow(int a, int n, int m) {
    int res = 1;
    while (n > 0) {
        if (n % 2 == 1)
            res = mod((res * a), m);
        a = mod((a * a), m);
        n /= 2;
    }
    return res;
}




int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        s += a;
        s %= (1000000000 + 7);
    }
    cout << mod(bin_pow(2, n - 1, 1e9 + 7) * mod(s, 1000000007), (1000000000 + 7)) << "\n";
    return 0;
}