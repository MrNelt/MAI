#include <bits/stdc++.h>
 
// #define int long long
 
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


struct seg_tree {
    vector <long long> data;
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

    int64_t get(int ql, int qr) {
        return get(1, ql, qr, 1, n);
    }

    int64_t get(int id, int ql, int qr, int l, int r) {
        if (ql > r || l > qr) {
            return 0;
        }
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
        return get(id * 2, ql, qr, l, m) + get(id * 2 + 1, ql, qr, m + 1, r);
    }

    void build(int id, int l, int r, const vector <int> & a) {
        if (l == r) {
            data[id] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(id * 2, l, m, a);
        build(id * 2 + 1, m + 1, r, a);
        data[id] = data[id * 2] + data[id * 2 + 1];

    }

    void set(int p, int x) {
        set(1, p, x, 1, n);
    }

    void set(int id, int p, int x, int l, int r) {
        if (l == r) {
            data[id] += x;
            return;
        }
        int m = (l + r) / 2;
        if (p <= m) {
            set(id * 2, p, x, l, m);
        }
        else {
            set(id * 2 + 1, p, x, m + 1, r);
        }
        data[id] = data[id * 2] + data[id * 2 + 1];
    }

};


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector <int> a(100000 + 10);
    int n;
    cin >> n;
    vector <int> b(n);
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        a[k] += k;
        b[i] = k;
    }
    // for (int i = 0; i < n + 1; i++){
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    int q;
    cin >> q;
    seg_tree st(a);
    while (q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int l, r;
            cin >> l >> r;
            cout << st.get(l, r) << "\n";
        }
        else {
            int p, x;
            cin >> p >> x;
            st.set(b[p - 1], -b[p - 1]);
            st.set(x, x);
            b[p - 1] = x;
        }
    }
    return 0;
}
