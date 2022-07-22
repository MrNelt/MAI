#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
using graph = vector <vector <int> >;
const unsigned long long INF = 1e18;

using pii = pair <int, int>;

//какая-нибудь перегрузка

// struct item {
//     int elem, id;
// };

// item operator + (item lhs, item rhs) {
//     if (lhs.elem < rhs.elem) {
//         return lhs;
//     }
//     if (rhs.elem < lhs.elem) {
//         return rhs;
//     }
//     return {lhs.elem, min(lhs.id, rhs.id)};
// }


int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}


struct seg_tree {
    vector <int> data;
    int n;

    seg_tree (int _n) {
        n = _n;
        data.resize(4 * n);
    }

    seg_tree(const vector <int> & a) {
        n = a.size();
        data.resize(4 * n);
        build(1, 1, n, a);
    }

    int get(int ql, int qr) {
        return get(1, ql, qr, 1, n);
    }

    int get(int id, int ql, int qr, int l, int r) {
        if (ql <= l && r <= qr) {
            return data[id];
        }
        int m = (l + r) / 2;
        if (qr <= m) {
            return get(id * 2, ql, qr, l, m);
        }
        if (ql > m) {
            return get(id * 2 + 1, ql, qr, m + 1, r);
        }
        return gcd(get(id * 2, ql, qr, l, m),get(id * 2 + 1, ql, qr, m + 1, r));
    }

    void build(int id, int l, int r, const vector <int> & a) {
        if (l == r) {
            data[id] = a[l - 1];
            return;
        }
        int m = (l + r) / 2;
        build(id * 2, l, m, a);
        build(id * 2 + 1, m + 1, r, a);
        data[id] = gcd(data[id * 2], data[id * 2 + 1]);

    }

    void set(int p, int x) {
        set(1, p, x, 1, n);
    }

    void set(int id, int p, int x, int l, int r) {
        if (l == r) {
            data[id] = x;
            return;
        }
        int m = (l + r) / 2;
        if (p <= m) {
            set(id * 2, p, x, l, m);
        }
        else {
            set(id * 2 + 1, p, x, m + 1, r);
        }
        data[id] = gcd(data[id * 2], data[id * 2 + 1]);
    }

};


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int q;
    cin >> q;
    seg_tree st(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << st.get(l, r) << "\n";
    }
    return 0;
}
