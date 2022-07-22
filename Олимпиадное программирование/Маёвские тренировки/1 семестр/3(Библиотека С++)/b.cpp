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
    vector <int> b;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int g = 0;
    for (int i = 0; i < n; i++){
        int temp = a[i];
        auto h = binary_search(b.begin(), b.end(), a[i]);
        if (!h){
            g++;
            b.push_back(a[i]);
        }
    }
    cout << g;
    cout << "\n";
}



