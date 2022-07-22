#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;

long long flag(long long a, long long b, long long t){
    return t / a + t / b;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, k, s = 0;
    cin >> n >> k;
    vector <long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++){
        if (!((i + 1) % k == 0)){
            s += a[i];
        }
    }
    cout << s;
}




