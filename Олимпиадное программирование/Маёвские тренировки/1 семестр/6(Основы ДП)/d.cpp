#include <bits/stdc++.h>

using namespace std;
#define int long long

void print(vector <int>& a){
    for (auto i : a){
        cout << i << " ";
    }
    cout << "\n";
}


int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> a(n + 1, 0);
    vector <int> answer(n + 1, -1);
    for (int i = 1; i < n; i++){
        cin >> a[i];
    }
    for (int i = 1; i < n + 1; i++){
        int temp = a[i - 1];
        int number = i - 1;
        for (int j = 1; j <= k; j++){
            if (i - j >= 0){
                if (a[i - j] < temp){
                    temp = a[i - j];
                    number = i - j;
                }
            } 
        }
        a[i] += temp;
        answer[i] = number;
    }
    cout << a[n] << "\n";
    string ans = to_string(n);
    int croads = 2;
    int flag = answer[n];

    for (int i = n; i >= 1; i--){
        if (i == flag){
            flag = answer[i];
            croads++;
            ans = to_string(i) + " " + ans;
        }
    }
    cout << croads << "\n";
    cout << "0 "<< ans << "\n";

	return 0;
}