#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int temp;
        cin >> temp;
        if (temp == 0){
            cout << "10";
        }
        else if (temp == 1){
            cout << 1;
        }

        else{
            vector <int> h;
            for (int j = 9; j >= 2; j--){
                while (temp % j == 0){
                    temp /= j;
                    h.push_back(j);
                }
            }
            if (temp == 1){
            for (int g = h.size() - 1; g >= 0; g--){
                cout << h[g];
                }
            }
            else {
                cout << "-1";
            }
        }

        cout << "\n";
    }
	return 0;
}