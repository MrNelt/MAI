#include <bits/stdc++.h>

using namespace std;
#define int long long


void print(vector <int>& d){
    for (auto i : d){
        cout << i << " ";
    }
    cout << "\n";
}

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int k = 0; k < t; k++){
        int n;
        cin >> n;
        vector <int> d(n);
        vector <int> a(n);
        for (int j = 0; j < n; j++){
            cin >> a[j];
        }
        d[0] = 1;
        int maxis = 1;
        int index = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j <= i; j++){
                if (a[i] > a[j]){
                    d[i] = max(d[j] + 1, d[i]);
                }
            }
            if (d[i] == 0){
                d[i] = 1;
            }
            if (d[i] > maxis){
                maxis = d[i];
                index = i;
            }
        }
        cout << maxis << "\n";
        int flag = maxis;
        int posl = a[index] + 1;
        string answer = "";

        for (int i = index; i >= 0; i--){
            if (d[i] == maxis && a[i] < posl){
                answer = to_string(i + 1) + " " + answer;
                posl = a[i];
                maxis--;
            }
        }
        cout << answer;
        cout << "\n";

    }
	return 0;
}