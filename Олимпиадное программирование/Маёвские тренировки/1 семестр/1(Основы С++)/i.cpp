#include <iostream>
#include <iomanip>
#include <cmath>
//2a1 + d(n - 1) / 2 * n

using namespace std;
int main(){
    double x1, y1, x2, y2, x3, y3;
    double d1, d2, d3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    d1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    d2 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    d3 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double p = (d1 + d2 + d3) / 2;
    cout << setprecision(10);
    cout << sqrt(p * (p - d1) * (p - d2) * (p - d3));
    
    
    return 0;
}