#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    vector <long long> y(n);
    for (long long i = 0; i < n; i++){
        cin >> y[i];
    }
    while (true){
        long long a = -1, b = - 1, t = 0;
        cin >> a >> b;
        if (a == 0 && b == 0){
            break;
        }
        long long u = b;
        for (long long j = a - 1; j < (a + b) / 2; j++){
            long long t = y[j];
            y[j] = y[u - 1];
            y[u - 1] = t;
            u--;
        }
    }
        
    for (long long i : y) {
        cout << i << " ";
    }
    return 0;
}