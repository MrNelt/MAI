#include <iostream>
#include <vector>
#include <string>

using namespace std;
//1234567890
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a = 1, b = 1, n;
    bool flag = false;
    cin >> n;
    long long counter = 0;
    while (b <= n){
        counter++;
        if (b == n){
            flag = true;
        }
        long long temp = a;
        a = b;
        b = temp + b;
    }
    if (n == 1){
        cout << 1;
    }
    else if (flag){
        cout << counter + 1;
    }
    else if(n == 0){
        cout << 0;
    }
    else{
        cout << -1;
    }
    return 0;
}