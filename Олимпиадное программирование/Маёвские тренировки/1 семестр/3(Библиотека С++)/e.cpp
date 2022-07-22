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
    long n, a, b;
    cin >> n >> a >> b;
    long long l = 0;
    long long r = max(a, b) * (n - 1);
    while (r - l > 1){
        long long m = (l + r) / 2;
        if (flag(a, b, m) < n - 1){
            l = m;
        }
        else {
            r = m;
        }

    }
    cout << r + min(a, b);
}




