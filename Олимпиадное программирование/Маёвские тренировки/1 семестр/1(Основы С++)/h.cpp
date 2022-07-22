#include <iostream>
#include <iomanip>
#include <cmath>
//2a1 + d(n - 1) / 2 * n

using namespace std;
int main(){
    double a, b, c;
    cin >> a >> b >> c;
    cout << setprecision(10);
    if (a == 0) {
        cout << -(c / b);
    }
    else {
        double d = b * b - 4 * a * c;
        if (d == 0) {
            cout << -b / (2 * a);
        }
        else {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        cout << min(x1, x2) << " " << max(x1, x2);
        }
    }
    return 0;
}