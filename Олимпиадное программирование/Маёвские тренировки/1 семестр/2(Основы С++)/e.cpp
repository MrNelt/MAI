#include <iostream>
#include <vector>
#include <string>

using namespace std;
//1234567890
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    long long counter = 0;
    cin >> s;
    for (long long i = 0; i < s.size(); i++){
        if (s[i] == '0') {
            counter++;
        }
        else if (s[i] == '4'){
            counter++;
        }
        else if (s[i] == '6'){
            counter++;
        }
        else if (s[i] == '8'){
            counter++;
            counter++;
        }
        else if (s[i] == '9'){
            counter++;
        }
    }
    cout << counter;

    return 0;
}