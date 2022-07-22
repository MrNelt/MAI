#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;
using graph = vector <vector <int> >;
const unsigned long long INF = 1e18;

using pii = pair <int, int>;



//const unsigned long long INF = 1e9;


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


struct treap {
    struct node {
        node* left;
        node* right;
        int x;
        int y;

        node(int _x, int _y) {
            right = nullptr;
            left = nullptr; 
            x = _x;
            y = _y;
        }
    };

    node* root;
    treap() {
        root = nullptr;
    }

    int get_key(node* t) {
        if (t != nullptr) {
            return t->x;
        }
        return 0;
    }

    node* merge(node* t1, node* t2) {
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        if (t1->y > t2->y) {
            t1->right = merge(t1->right, t2);
            return t1;
        } else {
            t2->left = merge(t1, t2->left);
            return t2; 
        }
    }

    void split(node* t, int x0, node* & t1, node* & t2) {
        if (t == nullptr) {
            t1 = nullptr;
            t2 = nullptr;
            return;
        }
        if (x0 > t->x) {
        // if (x0 > 1 + get_key(t->left)) {
            split(t->right, x0, t->right, t2);
            t1 = t;
        } else {
            split(t->left, x0, t1, t->left);
            t2 = t;
        }
    }

    void print() {
        print(root, 0);
    }

    void print(node* t, int h) {
        if (t != nullptr) {
            // cout << t->x << ", " << t->y << "\n";
            cout << t->x << " " <<t->y << "\n";
            print(t->left, h + 1);
            print(t->right, h + 1);
        }
        else {
            cout << "null\n";
        }
    }

    void insert(int _x, int _y) {
        node* l = nullptr;
        node* r = nullptr;
        split(root, _x, l, r);
        node* m = new node(_x, _y);
        root = merge(merge(l, m), r);
    }

};


    
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    treap t;
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        t.insert(x, y);
        //cout << "Printed" << endl;
    }
    t.print();
    return 0; 
}
 
