#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    string temp = "";
    for (auto j : s){
        temp += j;
        if (stoll(temp) < 97){
            continue;
        }
        else {
            int number = stoll(temp);
            number = number % 97;
            temp = to_string(number);
        }
    }
    if (stoll(temp) == 0){
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
	return 0;
}