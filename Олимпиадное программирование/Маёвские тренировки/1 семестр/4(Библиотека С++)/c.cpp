
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    int n, ans = 0;
        cin >> n;
        vector <int> temp(n);
        for (int i = 0; i < n; i++){
            cin >> temp[i];
        }
        sort(temp.begin(), temp.end());

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for (int k = j + 1; k < n; k++){
                    if (temp[i] < temp[j] + temp[k])
                        if (temp[j] < temp[i] + temp[k])
                            if (temp[k] < temp[j] + temp[i])
                                ans++;
                }
            }
        }
        cout << ans;
}
