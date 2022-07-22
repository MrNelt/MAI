#include <iostream>
#include <vector>
#include <string>

using namespace std;
//1234567890
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long t = 0;
    cin >> t;
    for (int i = 0; i < t; i++){
        long long n;
        vector <long long> k(5, 0);
        cin >> n;
        if (n >= 5000){
            long long e = n / 5000;
            n -= e * 5000;
            k[4] = e;
        }
        if (n >= 1000){
            long long e = n / 1000;
            n -= e * 1000;
            k[3] = e;
        }
        if (n >= 500){
            long long e = n / 500;
            n -= e * 500;
            k[2] = e;
        }
        if (n >= 200){
            long long e = n / 200;
            n -= e * 200;
            k[1] = e;
        }
        if (n >= 100){
            long long e = n / 100;
            n -= e * 100;
            k[0] = e;
        }
        for (long long i : k){
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}