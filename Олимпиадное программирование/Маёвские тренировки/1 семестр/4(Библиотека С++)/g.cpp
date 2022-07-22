#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <iomanip>
#include <set>



using namespace std;
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a;
    cin >> n;
    multiset<int> tttt;
    for(int i = 0; i < n; i++){
        cin >> a;
        tttt.insert(a);
    }
    while(tttt.size() > 1){
        int y, x = *tttt.begin();
        tttt.erase(tttt.find(x));
        y = *tttt.begin();
        tttt.erase(tttt.find(y));
        tttt.insert(x + y);
        cout << x << " " << y << '\n';
    }
	return 0;
}