#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a = 0, b = 0, counter = 0;
    cin >> a >> b;
    string word1, word2;
    cin >> word1;
    cin >> word2;
    for (long long i = 0; i < a - b + 1; i++){
        bool flag = true;
        for (long long h = 0; h < b; h++){
            if (word1[i + h] != word2[h]){
                flag = false;
                break;
            }
        }
        if (flag){
            counter++;
        }
    }
    cout << counter;
    return 0;
}