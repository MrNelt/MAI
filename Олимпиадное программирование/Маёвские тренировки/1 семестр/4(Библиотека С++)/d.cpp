#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>
#include <map>
#include <set>


using namespace std;
#define int long long



int32_t main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    set <string> chels;
    set <string> logins;
    set <string> active;

    while (cin >> s){
        if (s == "register"){
            string login;
            string password;
            cin >> login;
            cin >> password;
            int check = logins.count(login);
            if (check == 0){
                chels.insert(login + " " + password);
                logins.insert(login);
                cout << "account created \n";
            }
            else {
                cout << "login already in use \n";
            }
        }
        else if (s == "login"){
            string login;
            string password;
            cin >> login;
            cin >> password;
            int check = logins.count(login);
            if (check){
                if (active.count(login) == 0 && chels.count(login + " " + password) == 1){
                    active.insert(login);
                    cout << "logged in \n";
                }
                else if (active.count(login) == 1 && chels.count(login + " " + password) == 1){
                    cout << "already logged in \n";
                }
                else {
                    cout << "wrong account info \n";
                }
            }
            else {
                cout << "wrong account info \n";
            }
        }
        else if (s == "logout"){
            string login;
            cin >> login;
            int flag = logins.count(login);
            if (flag == 1){
                if (active.count(login) == 1){
                    auto it = active.find(login);
                    active.erase(it);
                    cout << "logged out \n";
                }
                else {
                    cout << "incorrect operation \n";
                }
            }
            else {
                cout << "incorrect operation \n";
            }
        }
    }
	return 0;
}