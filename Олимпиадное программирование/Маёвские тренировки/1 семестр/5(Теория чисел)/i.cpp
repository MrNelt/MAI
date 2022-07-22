#include <bits/stdc++.h>

using namespace std;
int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector <int> resheto(4 * 10000000);
    for (int p = 2; p <= 4 * 10000000; p++){
        if (!resheto[p]){
        for (int j = p * 2; j <= 4 * 10000000; j += p){
            resheto[j]++;
        }
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int temp;
        cin >> temp;
        if (temp == 1){
            cout << 0 << "\n";
        }
        else if (!resheto[temp]){
            cout << "Prime \n";
        }
        else {
            cout << resheto[temp] << "\n";
        }
    }
	return 0;
}