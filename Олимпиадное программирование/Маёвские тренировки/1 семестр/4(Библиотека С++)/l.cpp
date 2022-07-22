#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
 
 
using namespace std;
#define int long long

int flag(int &k, vector <int> &d, int &t, vector <int> &copy){
    int s = 0;
    for (int i = 0; i < k; i++){
        int temp = t;
        if ((copy[i] != d[i])){
            if (temp < copy[i]){
                continue;
            }
            temp -= copy[i];
            s++;
        }
        s += temp / d[i];

    }
    return s;
}


 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> d(k);
    vector <int> d_copy(k);
    for (int i = 0; i < k; i++){
        int temp;
        cin >> temp;
        d[i] = temp;
        d_copy[i] = temp;
    }
    sort(d.begin(), d.end());
    sort(d_copy.begin(), d_copy.end());
    int l = 0;
    int r = d[d.size() - 1] * (n - 1);
    int counter = 1;
    int time = 0;
    while (counter < min(n + 1, k)){
        int temp = counter;
        for (int i = 0; i < min(k, temp); i++){
            d_copy[i]--;
            if (d_copy[i] == 0){
                counter++;
                d_copy[i] = d[i];
            }
        }
        time++;
    }
	n -= (counter);
    n++;
    while (r - l > 1){
        long long m = (l + r) / 2;
        if (flag(k, d, m, d_copy) < n){
            l = m;
        }
        else {
            r = m;
        }
    }
    if (k == 1){
        cout << r + time + d[0];
    }
    else {
    cout << r + time << "\n";
    }
}