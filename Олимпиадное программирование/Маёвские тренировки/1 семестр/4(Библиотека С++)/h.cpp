#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>


using namespace std;
#define int long long



int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a, m, k, mod;
    cin >> n;
    cin >> a >> m >> k >> mod;
    vector <int> e(mod);
    for (int i = 0; i < n; ++i){
        e[a % mod]++;
        a = (a * m + k) % mod;

    }
    int counter = 0;
    int s = 0;
    cout << "\n";
    for (int i = 0; i < mod; i++){
        for (int j = 0; j < e[i]; j++){
            s += ((counter + 1) * (i));
            s %= (1000000000 + 7);
            counter++;
        }
    }
    cout << s << "\n";
	return 0;
}