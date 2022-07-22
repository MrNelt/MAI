#include <iostream>
#include <vector>

using namespace std;

void print(vector <int> &a){
	for (int i : a){
		cout << i << " ";
	}
	cout << "\n";
}


int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
    	int n;
    	cin >> n;
    	vector <int> a(n);
    	for (int j = 0; j < n; j++){
    		cin >> a[j];
    	}
    	int counter = 0;
    	while (true){
    		int counter_checker = 0;
 			for (int j = 1; j < n; j++){
 				if (a[j - 1] > a[j]){
 					int temp = a[j];
 					a[j] = a[j - 1];
 					a[j - 1] = temp;
 					counter_checker++;
 				}
 			}
 			counter += counter_checker;
 			if (counter_checker == 0){
 				break;
 			}
    	}
    	cout << counter << "\n";
    }
	return 0;
}