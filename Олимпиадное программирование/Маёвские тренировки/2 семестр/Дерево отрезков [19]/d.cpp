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

    int get(int p) {
        return get(1, p, 1, n);
    }

    int get(int id, int p, int l, int r) {
        if (l == r) {
            return data[id];
        }
        int m = (l + r) / 2;
        if (p <= m) {
            return data[id] + get(id * 2, p, l, m);
        }
        else {
            return data[id] + get(id * 2 + 1, p, m + 1, r);
        }
    }

    void build(int id, int l, int r, const vector <int> & a) {
        if (l == r) {
            data[id] = 0;
            return;
        }
        int m = (l + r) / 2;
        build(id * 2, l, m, a);
        build(id * 2 + 1, m + 1, r, a);
    }

    void set(int x, int lt, int rt) {
        set(1, x, 1, n, lt, rt);
    }

    void set(int id, int x, int l, int r, int lt, int rt) {
        if (lt > rt){
            return;
        }
        if (l == lt && r == rt) {
            data[id] += x;
            return;
        }
        int m = (l + r) / 2;
        set(id * 2, x, l, m, lt, min(rt, m));
        set(id * 2 + 1, x, m + 1, r, max(lt, m + 1), rt);
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
        int type;
        cin >> type;
        if (type == 0) {
            int p;
            cin >> p;
            cout << st.get(p) + a[p - 1] << "\n";
        }
        else {
            int l, r, x;
            cin >> l >> r >> x;
            st.set(x, l, r);
        }
    }
    return 0;
}
