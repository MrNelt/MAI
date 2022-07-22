#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>



using namespace std;
#define int long long


void print(vector <int>& a){
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}


struct room{
    int begin;
    int end;
};


int32_t main(){
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

    int m;
    cin >> m;
    vector <room> rooms(m);
    vector <int> answers(m, 0);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        rooms[i].begin = min(a, b);
        rooms[i].end = max(a, b);
    }
    for (int j = 0; j < m; j++){
        auto l = lower_bound(a.begin(), a.end(), rooms[j].begin);
        auto r = lower_bound(a.begin(), a.end(), rooms[j].end);
        answers[j] += abs(r - l);
    }
    for (auto i : answers){
        cout << i << "\n";
    }
    return 0;
}



