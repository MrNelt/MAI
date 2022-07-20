#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>
 
 
 
using namespace std;
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string t;
    deque <string> dack;
    while (cin >> t){
        if (t == " "){
            continue;
        }
        else if (t == "*"){
            auto t1 = dack.back();
            dack.pop_back();
            auto t2 = dack.back();
            dack.pop_back();
            dack.push_back(to_string(stoll(t1) * stoll(t2)));
        }
        else if (t == "-"){
            auto t1 = dack.back();
            dack.pop_back();
            auto t2 = dack.back();
            dack.pop_back();
            dack.push_back(to_string(stoll(t2) - stoll(t1)));
        }
        else if (t == "+"){
            auto t1 = dack.back();
            dack.pop_back();
            auto t2 = dack.back();
            dack.pop_back();
            dack.push_back(to_string(stoll(t1) + stoll(t2)));
        }
        else{
            dack.push_back(t);
        }
    }
    cout << dack[0];
    return 0;
}