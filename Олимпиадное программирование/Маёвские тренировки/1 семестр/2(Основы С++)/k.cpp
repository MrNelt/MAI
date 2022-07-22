#include <iostream>
#include <string>
#include <vector>

using namespace std;


long long binpow (long a, long n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow(a, n - 1) * a;
	else {
		long long b = binpow(a, n / 2);
		return b * b;
	}
}

//stoi

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	long long a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	long long desyat = 0;
	// перевод в 10 систему счисления из a
	for (int i = 0; i < s.size(); i++){
		if ('0' <= s[i] && s[i] <= '9'){
			desyat += (s[i] - '0') * binpow(a, s.size() - i - 1);
		}
		else if ('a' <= s[i] && s[i] <= 'z'){
			desyat += (s[i] - 'a' + 10) * binpow(a, s.size() - i - 1);
		}
	}
	long long old_desyat = desyat;
	// перевод из 10 в b
	vector <char> answer;
	while (desyat > 0){
		long long ost = desyat % b;
		desyat /= b;
		if (0 <= ost && ost <= 9){
			answer.push_back(char('0' + ost));
		}
		else {
			answer.push_back(char('a' - 10 + ost));

		}
	}
	// вывод числа
	if (old_desyat == 0){
		cout << 0;
	}
	else {
		for (int i = answer.size() - 1; i >= 0; i--){
			cout << answer[i];
		}
	}
	cout << "\n";
	return 0;
}