#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>



using namespace std;
#define int long long

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
   	int check = a[0];
   	sort(a.begin(), a.end());
   	bool flag = true;
   	for (int i = 1; i < n; i++){
   		if (a[i] != a[i - 1] + 1){
   			flag = false;
   			break;
   		}
   	}
   	if (flag){
   		cout << "Deck looks good";
   	}
   	else {
   		cout << "Scammed";
   	}
	return 0;
}