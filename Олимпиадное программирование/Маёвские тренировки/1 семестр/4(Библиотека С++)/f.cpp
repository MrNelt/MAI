#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>
#include <set>
#include <cmath>


using namespace std;
#define int long long
int e = 1000000000 + 7;


int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);

    cout.tie(0);
    int n, a0;
    cin >> n >> a0;
    int max1 = 0;
    int max2 = -1;
    int t = a0 % e;
    for (int i = 0; i < n; i++){
        t *= 5;
        t %= e;
        if (t > max1){
            max2 = max1;
            max1 = t;
        }
        else if (t > max2){
            max2 = t;
        }
    }
    cout << max2 << " " << max1 << "\n";

	return 0;
}
