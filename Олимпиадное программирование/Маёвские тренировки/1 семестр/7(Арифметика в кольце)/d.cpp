#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <queue>
#include <deque>
#include <map>
using namespace std;
#define int unsigned long long
 

int bin_pow(int a, int n, int mod) {
    int res = 1;
    while (n > 0) {
        if (n % 2 == 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n /= 2;
    }
    return res;
}

int faqtorial(int n,int p)
{
	int res = 1;
	while (n > 1) {
		res = (res * ((n/p) % 2 ? p-1 : 1)) % p;
		for (int i=2; i<=n%p; ++i)
			res = (res * i) % p;
		n /= p;
	}
	return res % p;
}
 
int32_t main()
{
    string str;
    int mod = (1e9 + 7);
    cin >> str;
    int intq[27] = { 0 };
 
    for (int i = 0; i < str.length(); ++i)
        intq[str[i] - 'a']++;
 
    int tempq = faqtorial(str.length(),mod);
    for (int i = 0; i < 27; ++i){
        //int inv_a = bin_pow(a, phi(mod) - 1, mod);
        int a = bin_pow(faqtorial(intq[i], mod), mod - 2, mod);
        tempq = (tempq * a) % mod;
    }
    cout << tempq % mod;
    return 0;
}