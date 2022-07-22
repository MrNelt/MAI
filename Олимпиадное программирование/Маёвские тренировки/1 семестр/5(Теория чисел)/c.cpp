#include <bits/stdc++.h>

using namespace std;
#define int long long


void print(vector <int>& a){
    for (auto i: a){
        cout << i << " ";
    }
    cout << "\n";
}


int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> m(n);
    if (n == 1){
        cout << 0;
    }
    else {
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int answer = 0;
    int temp = 0;
    for (int i = 1; i < n; i++){
        temp += (i * (a[i] - a[i - 1]));
        answer += temp;         
    }
    cout << answer << "\n";
    }
}