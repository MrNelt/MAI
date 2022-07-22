#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>


using namespace std;

long long flag(long long a, long long b, long long t){
    return t / a + t / b;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <char> deck;
    bool flag = true;
    for (int i = 0; i < n; i++){
        char temp;
        cin >> temp;
        if (temp == '(' || temp == '{' || temp == '['){
            deck.push_back(temp);
        }
        else{
            if (deck.size() != 0){
                auto f = deck.back();
                deck.pop_back();
                if (f == '[' && temp == ']'){
                    continue;
                }
                else if (f == '{' && temp == '}'){
                    continue;
                }
                else if (f == '(' && temp == ')'){
                    continue;
                }
            }
            flag = false;
            break;
        }
    }
    if (flag && deck.size() == 0){
        cout << "Ja";
    }
    else {
        cout << "Nein";
    }
}




