#include <algorithm>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int is_sort = 0;

struct poetry_line { //структура таблицы - ключ и строка стихотворения
    double key;
    string poetry;
};

poetry_line min_el(poetry_line a, poetry_line b)
{
    if (a.key < 0) {
        return b;
    }
    if (b.key < 0) {
        return a;
    }
    return a.key < b.key ? a : b;
}


void tournament_sort_table(vector<poetry_line> &v)
{
    is_sort = 1;
    int n = v.size();
    int size;
    int idx;
    for (int i = 1; ; i *= 2) {
        if (i >= n) {
            size = i;
            break;
        }
    }
    vector<poetry_line> res(n);
    vector<poetry_line> tree(2 * size - 1, {-1, ""});
    for (int i = 0; i < n; ++i) {
        tree[i + size - 1] = v[i];
    }
    
    for (int i = size - 2; i >= 0; --i) {
        tree[i] = min_el(tree[(2 * i + 1)], tree[(2 * i + 2)]);
    }
    
    for (int i = 0; i < n; ++i) {
        idx = 0;
        res[i] = tree[idx];
        tree[idx].key = -1;
        
        while (idx < size - 1) {
            if (tree[idx * 2 + 1].key == res[i].key && tree[idx * 2 + 1].poetry == res[i].poetry) {
                tree[idx * 2 + 1] = {-1, ""};
                idx = idx * 2 + 1;
            } else {
                tree[idx * 2 + 2] = {-1, ""};
                idx = idx * 2 + 2;
            }
        }
        
        while (idx) {
            idx -= 1;
            idx /= 2;
            tree[idx] = min_el(tree[(2 * idx + 1)], tree[(2 * idx + 2)]);
        }
        
        
    }
    
    v = res;
}



int get_size_buffer() { //узнать кол-во строчек
    string line;
    ifstream in("keys.txt");
    int n = 0;
    if (in.is_open()) {
        while (getline(in, line)) {
            n++;
        }
    }
    in.close();
    return n;
}

void print_table(const vector <poetry_line>& table) { //вывести таблицу
    for (int i = 0; i < table.size(); i++) {
        cout << table[i].key << " ------- " << table[i].poetry << "\n";
    }
}


void swap_strings(vector <poetry_line>& table, int a, int b) { //поменять местами строки
    poetry_line temp;
    temp = table[a];
    table[a] = table[b];
    table[b] = temp;
}


void mix_table(vector <poetry_line>& table) { //перемешивание строк
    is_sort = 0;
    int a, b;
    for (int i = 0; i < table.size(); ++i) {
        a = rand() % table.size();
        b = rand() % table.size();
        swap_strings(table, a, b);
    }
}

int bin_search(vector <poetry_line>table, double key) { //бинарный поиск в отсортированной таблице
  int l = 0, r = table.size() - 1, mid;
  
  while (l <= r) {
    mid = (r + l) / 2;
    if (key == table[mid].key)
      return mid;
    if (l == r) { //интервал уменьшен до нуля
      return -1;
    }
    if (key < table[mid].key)
      r = mid;
    if (key > table[mid].key)
      l = mid + 1;
  }
  return -1;
}


void reverse_strings(vector <poetry_line>&table) { //реверс таблицы
  is_sort = 0;
  for (int i = 0, j = table.size() - 1; i < j; ++i, --j) {
    swap_strings(table, i, j);
  }
}

int main() {
    int n = get_size_buffer();
    vector <poetry_line> table(n);
    n--;

    //считывание ключей

    string line;
    ifstream in_key("keys.txt");
    int counter = 0;
    if (in_key.is_open()) {
        while (getline(in_key, line)) {
            counter++;
            table[counter - 1].key = stod(line);
        }
    }
    in_key.close();
    //считали ключи

    //считание строк таблицы

    ifstream in_poetry("poetry.txt");
    counter = 0;
    if (in_poetry.is_open()) {
        while (getline(in_poetry, line)) {
            counter++;
            table[counter - 1].poetry = line;
        }
    }
    in_poetry.close();

    //считали строки
    print_table(table);
    int action;
    while (1) {
        cout << "Menu\n";
        cout << "1)  Binary  search\n";
        cout << "2)  Sort\n";
        cout << "3)  Mix\n";
        cout << "4)  Reverse\n";
        cout << "5)  Exit\n";
        cout << "Choose  an  action\n";
        cin >> action;
    switch (action) {
        case 1: {
        if (is_sort) {
            cout << "Enter the string key: ";
            double k;
            cin >> k;
            int search;
            cout << "\n";
            search = bin_search(table, k);
            if (search == -1) {
                cout << "Element  with  such  key  is  not  found!\n";
                break;
            }
            cout << "Found  the  string:\n" << table[search].poetry << "\n";
        } else
            cout << "Table  is  not  sorted!\n";
        break;
        }
        case 2: {
            tournament_sort_table(table);
            print_table(table);
            break;
        }
        case 3: {
            mix_table(table);
            print_table(table);
            break;
        }
        case 4: {
            reverse_strings(table);
            print_table(table);
            break;
        }
        case 5:
            return 0;
        }
    }
    return 0;
}