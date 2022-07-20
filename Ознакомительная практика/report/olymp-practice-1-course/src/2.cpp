#include <iostream>
#include <string>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
 
    long long chislo1 = 0;
    long long chislo2 = 0;
    string answer;
    int counter = 0;
    while (cin >> s){
        counter++;
        string num1 = "", num2="";
        bool flag = false;
        for (auto i : s){
            if (i != '.' && !flag){
                num1 += i;
            }
            else if (!flag) {
                flag = true;
                continue;
            }
            if (flag){
                num2 += i;
            }
        }
        long long n1 = stoll(num1);
        long long n2 = stoll(num2);
        chislo1 += n1;
        chislo2 += 1e15;
        chislo2 += n2;
        long long k = chislo2 / 1e15;
        if (k > 1){
            chislo2 -= 1e15 * (k - 1);
            chislo1 += (k - 1);
        }
        string temp = to_string(chislo2).substr(1, to_string(chislo2).size() - 1);
        for (int i = temp.size(); i < 15; i++){
            temp += "0";
        }
        answer = to_string(chislo1 - (counter - 1)) + "." + temp;
    }
    cout << answer << "\n";
}