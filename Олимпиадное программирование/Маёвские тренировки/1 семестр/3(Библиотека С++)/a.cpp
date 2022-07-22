#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i : a){
        cout << i << " ";

    }
    cout << "\n";
}



