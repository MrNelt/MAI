#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>



using namespace std;
#define int long long


void funct(int n, vector <char>& seq, int bal = 0, int ind = 0) {
  if (ind == 2 * n) {
    for (auto& i : seq) {
       cout << i;
    }
    cout << "\n";
  } 
  else{
    if (bal == 2 * n - ind) {
        seq[ind] = ')';
        bal--;
        funct(n, seq, bal, ind + 1);
    } else {
        seq[ind] = '(';
        bal++;
        funct(n, seq, bal, ind + 1);
        if (bal > 1) {
            seq[ind] = ')';
            bal -= 2;
            funct(n, seq, bal, ind + 1);
       }
    }
  }
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <char> s(2 * n);
    funct(n, s);
}



