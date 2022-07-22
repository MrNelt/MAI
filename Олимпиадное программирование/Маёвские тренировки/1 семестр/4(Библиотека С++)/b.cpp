#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>
#include <set>



using namespace std;
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int n;
    cin >> n;
    set <string> u;
    for (int i = 0; i < n; i++){
    	cin >> s;
    	vector <char> hue;
    	for (auto i : s){
    		hue.push_back(i);
    	}
    	sort(hue.begin(), hue.end());
    	string answer = "";
    	for (auto i : hue){
    		answer += i;
    	}
    	u.insert(answer);
    }
    cout << u.size() << "\n";
	return 0;
}