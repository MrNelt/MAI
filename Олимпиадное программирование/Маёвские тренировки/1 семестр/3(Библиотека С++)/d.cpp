#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>



using namespace std;

int main(){
	long long l = 0;
	long long r = 1000000000;
	while (true){
		long long middle = (l + r + 1) / 2;
		cout << middle << "\n";
		cout.flush();
		char answer;
		cin >> answer;
		if (answer == '='){
			break;
		}
		if (answer == '>'){
			r = middle - 1;
		}
		else {
			l = middle + 1;
		}
	}
	return 0;
}