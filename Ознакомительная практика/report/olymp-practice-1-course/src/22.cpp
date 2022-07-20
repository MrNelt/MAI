#include <bits/stdc++.h>
using namespace std;
    
#define int long long

const unsigned long long INF = 1e9;

using pii = pair<int, int>;
using graph = vector<vector<int>>;
using Wgraph = vector<vector<pair<int, int>>>;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());


struct treap {
    struct node {
        node* left;
        node* right;
        int x;
        int64_t y;
        int data;
        int data_max;
        bool reverse;

        node(int num) {
            right = nullptr;
            left = nullptr; 
            x = 1;
            y = rng();
            data = num;
            data_max = num;
            reverse = false;
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
        if (t1->y < t2->y) {
            push(t1);
            t1->right = merge(t1->right, t2);
            update(t1);
            return t1;
        } else {
            push(t2);
            t2->left = merge(t1, t2->left);
            update(t2);
            return t2; 
        }
    }

    int get_max(node* t) { 
        if (t != nullptr) {
            return t->data_max;
        }
        return 0;
    }

    void update(node* t) {
        if (t != nullptr) {
            t->x = 1 + get_key(t->left) + get_key(t->right);
            t->data_max = max(t->data, max(get_max(t->left), get_max(t->right)));
        }
    }

    void push_reverse(node* t) {
        if (t != nullptr) {
            t->reverse ^= 1;
        }
    }

    void push(node* t) {
        if (t != nullptr && t->reverse) {
            push_reverse(t->left);
            push_reverse(t->right);
            swap(t->left, t->right);
            t->reverse = false; 
        }
    }

    void print() {
        print(root, 0);
    }

    void print(node* t, int h) {
        if (t != nullptr) {
            push(t);
            print(t->left, h + 1);
            cout << t->data << " ";
            print(t->right, h + 1);
        }
    }

    void split(node* t, int x0, node* & t1, node* & t2) {
        if (t == nullptr) {
            t1 = nullptr;
            t2 = nullptr;
            return;
        }
        push(t);
        if (x0 > 1 + get_key(t->left)) {
            split(t->right, x0 - 1 - get_key(t->left), t->right, t2);
            t1 = t;
        } else {
            split(t->left, x0, t1, t->left);
            t2 = t;
        }
        update(t);
    }

    void insert(int _x, int _p) {
        node* l = nullptr;
        node* r = nullptr;
        split(root, _p, l, r);
        node* m = new node(_x);
        root = merge(merge(l, m), r);
    }

    void reverse_seg(int ql, int qr) {
        node* l = nullptr;
        node* m = nullptr;
        node* r = nullptr;
        split(root, qr + 1, m, r);
        split(m, ql, l, m);
        push_reverse(m);
        root = merge(l, merge(m, r));
    }

    void replace(int ql, int qr, int index) {
        node* l = nullptr;
        node* m0 = nullptr;
        node* m1 = nullptr;
        node* r = nullptr;
        split(root, qr + 1, m1, r);
        split(m1, ql, m0, m1);
        split(m0, index, l, m0);
        root = merge(merge(l, m1), merge(m0, r));
    }

};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    treap t;
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++){
        int x, p;
        cin >> x >> p;
        p++;
        t.insert(x, p);
    }
    t.print();
    cout << "\n";
    return 0;
}
    