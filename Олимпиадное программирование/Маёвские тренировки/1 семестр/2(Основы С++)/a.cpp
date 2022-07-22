#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long s = 0, n = 0, a = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        s += a;
    }
    cout << s;
    return 0;
}