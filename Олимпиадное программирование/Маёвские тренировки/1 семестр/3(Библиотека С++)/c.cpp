#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;



struct team{
    string name;
    int s;
    int p;
};

bool key (team l, team r){
    if (l.s != r.s){
        return l.s > r.s;
    }
    if (l.p != r.p){
        return l.p < r.p;
    }
    return l.name < r.name;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <team> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].name >> a[i].s >> a[i].p;
    }
    sort(a.begin(), a.end(), key);
    for (auto i : a){
        cout << i.name << "\n";
    }
}




