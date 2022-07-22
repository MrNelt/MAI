#include <bits/stdc++.h>
#include <string>
#include <sys/types.h>
using namespace std;
    
#define int long long
//const int MOD = 1e18 + 7;
const int MAXN = 1e6;
const int P = 29;


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map <int, int> mp;
    string s;
    cin >> s;
    string answer = "";
    int len = s.size();
    for (int i = 0; i < len; i++){
        string temp = "";
        int hash_tmp;
        int counter = 1;
        vector <int> hash(len - i + 2);
        for (int j = i; j < len; j++){
            temp += s[j];
            hash[counter] = (P * hash[counter - 1] + s[j] - 'a' + 1);
            int key = hash[counter];
            mp[key] += 1;
            counter++;
        }
    }
    int tmp_value = 0;
    int max_value = 0;
    for (int i = 0; i < len; i++) {
        string temp = "";
        vector <int> hash(len - i + 2);
        int counter = 1;
        for (int j = i; j < len; j++) {
            temp += s[j];
            hash[counter] = (P * hash[counter - 1] + s[j] - 'a' + 1);
            int key = hash[counter];
            tmp_value = (j - i + 1) * mp[key];
            if (tmp_value >= max_value) {
                max_value = tmp_value;
                answer = temp;
            }
            counter++;
        }
    }
    cout << answer << "\n";
    return 0;
}
    
