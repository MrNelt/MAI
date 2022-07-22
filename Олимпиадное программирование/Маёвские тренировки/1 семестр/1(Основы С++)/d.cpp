#include <iostream>
#include <iomanip>


using namespace std;
int main(){
    float d, x, y;
    cin >> d;
    cin >> x >> y;
    if (d * d >= x * x + y * y){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}