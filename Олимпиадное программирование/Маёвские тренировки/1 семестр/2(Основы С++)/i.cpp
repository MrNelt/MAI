#include <iostream>

using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    int a = min(x1, x2);
    if (x1 != a) {
        a = x1;
        x1 = x2;
        x2 = a;
    }
    a = min(y1, y2);
    if (y1 != a) {
        a = y1;
        y1 = y2;
        y2 = a;
    }
    a = min(x3, x4);
    if (x3 != a) {
        a = x3;
        x3 = x4;
        x4 = a;
    }
    a = min(y3, y4);
    if (y3 != a) {
        a = y3;
        y3 = y4;
        y4 = a;
    }
 
    int c = 0, b = 0;
    if (x2 > x4) {
        if (x1 < x4) {
            if (x1 > x3) c = x4 - x1;
            else c = x4 - x3;
        }
    }
    else {
        if (x2 > x3) {
            if (x1 < x3) c = x2 - x3;
            else c = x2 - x1;
        }
    }
    if (y2 > y4) {
        if (y1 < y4) {
            if (y1 > y3) b = y4 - y1;
            else b = y4 - y3;
        }
    }
    else {
        if (y2 > y3) {
            if (y1 < y3) b = y2 - y3;
            else b = y2 - y1;
        }
    }
    cout << ((x2 - x1) * (y2 - y1)) + ((x4 - x3) * (y4 - y3)) - c * b;
}