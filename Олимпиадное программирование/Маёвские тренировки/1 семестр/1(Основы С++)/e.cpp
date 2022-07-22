#include <iostream>
#include <iomanip>


using namespace std;
int main(){
    int h1, m1, hu, mu, hp, mp, k;
    cin >> h1 >> m1;
    cin >> hu >> mu;
    cin >> hp >> mp;
    cin >> k;
    int m_all, um_all, p_all, answer;
    m_all = h1 * 60 + m1;

    um_all = hu * 60 + mu;
    p_all = hp * 60 + mp;
    answer = m_all + um_all * k + p_all * (k - 1);
    cout << (answer / 60) % 24 << " " << answer % 60;
    
    return 0;
}