#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    vector <long long> answer;
    vector <long long> sorty;
    vector <long long> numbers;
    bool flag = true;
    long long counter = 0;
    for (long long i = 0; i < n; i++){
        long long b;
        cin >> b;
        if (b >= 0 && b <= n){
            if (b != 0){
                sorty.push_back(b);
                counter++;
            }
            answer.push_back(b);
        }
        else{
            flag = false;
        }
    }
    if (flag){
        sort(sorty.begin(), sorty.end());
        for (int i = 1; i < counter; i++){
            if (sorty[i] == sorty[i - 1]){
                flag = false;
                break;
            }
        }
        if (flag){
            for (int i = 1; i <= n; i++){
                bool f = binary_search(sorty.begin(), sorty.end(), i);
                if (!f){
                    numbers.push_back(i);
                }
            }
            long long counter = 0;
            for (auto i : answer){
                if (i == 0){
                    cout << numbers[counter] << " ";
                    counter++;
                }
                else{
                    cout << i << " ";
                }
            }
            cout << "\n";
        }
        else{
            cout << -1;
            cout << "\n";
        }        
    }
    else{
        cout << -1;
        cout << "\n";
    }
}



