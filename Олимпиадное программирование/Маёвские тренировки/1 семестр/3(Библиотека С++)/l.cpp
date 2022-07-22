#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>



using namespace std;
#define int long long



int32_t main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n, m;
        cin >> n >> m;
        vector <int> a(n);
        for (int j = 0; j < n; j++){
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        int counter = 0;
        for (int j = 0; j < n; j++){
            auto t = lower_bound(a.begin(), a.end(), m / a[j] + 1);
            int temp = (t - a.begin() - j);
            if (temp > 0){
                counter += temp;
                counter--;
            }
        }
        cout << counter << "\n";

    }
    return 0;
}