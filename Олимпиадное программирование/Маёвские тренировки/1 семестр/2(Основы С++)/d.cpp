#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, s = 1;
    cin >> a;
    if (a == 0){
        cout << 1;
    }
    else{
        for (long long i = 1; i <= a; i++){
            s = (s * i) % (1000000000 + 7);
        }
        cout << s;
    }

    return 0;
}