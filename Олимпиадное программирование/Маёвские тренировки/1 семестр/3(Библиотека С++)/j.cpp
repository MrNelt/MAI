#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>



using namespace std;
#define int long long





int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector <string> answers(m);
    for (int i = 0; i < m; i++){
        int m = 0;
        cin >> m;
        cin >> answers[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (s[i] == answers[j][0]){
                answers[j] = answers[j].substr(1, answers[j].size() - 1);
            }
        }
    }
    for (int i = 0; i < m; i++){
        if (answers[i] == ""){
            cout << "0";
        }
        else {
            cout << "1";
        }
    }
}