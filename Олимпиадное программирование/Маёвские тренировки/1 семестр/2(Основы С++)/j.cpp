#include <iostream>
#include <vector>


using namespace std;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
    	cin >> a[i];
    }
    if (n == 1){
        cout << 1 << " " << 1 << "\n";
        cout << 1 << " " << 1 << "\n";
        cout << 1 << " " << 1 << "\n";
    }
    else{
    	int glob_min = 1e9, glob_max = -1e9;
        int count_min = 1e9, count_max = -1e9; 
        vector <int> list_min;
        vector <int> list_max;
        int counter_max = 0, counter_min = 0;

        for (int j = 0; j < n; j++){
            //1 случай - когда слева пусто
            if (j - 1 < 0){
                if (a[j] < a[j + 1]){
                    counter_min++;
                    list_min.push_back(j + 1);
                    if (a[j] < count_min){
                        glob_min = j + 1;
                        count_min = a[j];
                    }
                }
                if (a[j] > a[j + 1]){
                    counter_max++;
                    list_max.push_back(j + 1);
                    if (a[j] > count_max){
                        glob_max = j + 1;
                        count_max = a[j];
                    }
                }
            }
            //2 случай - когда справа пусто
            else if (j + 1 >= n){
                if (a[j - 1] > a[j]){
                    counter_min++;
                    list_min.push_back(j + 1);
                    if (a[j] < count_min){
                        glob_min = j + 1;
                        count_min = a[j];
                    }
                }
                if (a[j - 1] < a[j]){
                    counter_max++;
                    list_max.push_back(j + 1);
                    if (a[j] > count_max){
                        glob_max = j + 1;
                        count_max = a[j];
                    }
                }

            }
            // 3 случай - когда везде пусто => 1 элемент в массиве;
            else if (n == 1){
                counter_min++;
                counter_max++;
                glob_max = j + 1;
                list_max.push_back(j + 1);
                list_min.push_back(j + 1);
                glob_min = j + 1;
            }
            // 4 случай - все ок;
            else {
                if (a[j - 1] > a[j] && a[j] < a[j + 1]){
                    counter_min++;
                    list_min.push_back(j + 1);
                    if (a[j] < count_min){
                        glob_min = j + 1;
                        count_min = a[j];
                    }
                }
                // ai−1<ai>ai+1
                if (a[j - 1] < a[j] && a[j] > a[j + 1]){
                    counter_max++;
                    list_max.push_back(j + 1);
                    if (a[j] > count_max){
                        glob_max = j + 1;
                        count_max = a[j];
                    }

                }
            }

        }
        // вывод
        cout << counter_min << " ";
        for (int i : list_min){
            cout << i << " ";
        }
        cout << "\n";
        cout << counter_max << " ";
        for (int i : list_max){
            cout << i << " ";
        }
        cout << "\n";
        cout << glob_min << " " << glob_max << "\n";
    }
	return 0;
}