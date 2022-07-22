#include <bits/stdc++.h>



using namespace std;
#define int long long

int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int t = 15485863;
    vector <int> simple_numbers;
    simple_numbers.push_back(0);
    vector <int> a(t + 1,  1);
    int counter = 0;
    for (int i = 2; i <= t; i++){
        if(a[i]){
            simple_numbers.push_back(simple_numbers[counter] + i);
            counter++;
        }
        for (int j = i * i; j <= t; j += i){
            a[j] = 0;
        }
    }
    int answer = 0;

    cout << simple_numbers[m] - simple_numbers[n - 1] + simple_numbers[0] << "\n";
    return 0;
    
}