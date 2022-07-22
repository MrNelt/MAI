#include <bits/stdc++.h>


using namespace std;
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int counter = 0;
    int k = 0;
    for (int i = 1; i * i < n + 1; i++){
        if (n % i == 0){
            counter++;
            if (n / i != i){
                counter++;
            }
        }
    }
    cout << counter;
	return 0;
}