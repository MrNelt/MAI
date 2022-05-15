#include <algorithm>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int is_sort = 0;

struct poetry_line { //структура таблицы - ключ и строка стихотворения
    string key;
    string poetry;
};

void quick_sort_nr_table(vector<poetry_line> &v) //сортировка таблицы
{
    is_sort = 1;
    int n = v.size();
    vector<poetry_line> res(v);
    
    stack<int> begins;
    stack<int> ends;
    begins.push(0);
    ends.push(n - 1);
    
    long i, j, left, right;
    poetry_line tmp_value;
    string p;
    
    while (!begins.empty()) {
        left = begins.top();
        right = ends.top();
        i = left;
        j = right;
        begins.pop();
        ends.pop();
        
        p = res[(left + right) / 2].key;
        
        do {
            while (res[i].key < p) {
                i++;
            }
            while (res[j].key > p) {
                j--;
            }
            
            if (i <= j) {
                tmp_value = res[i];
                res[i] = res[j];
                res[j] = tmp_value;
                ++i;
                --j;
            }
        } while (i <= j);
        
        if (j > left) {
            begins.push(left);
            ends.push(j);
        }
        if (i < right) {
            begins.push(i);
            ends.push(right);
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
        cout << table[i].key << " " << table[i].poetry << "\n";
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

int bin_search(vector <poetry_line>table, string key) { //бинарный поиск в отсортированной таблице
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
            table[counter - 1].key = line;
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
            string k;
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
            quick_sort_nr_table(table);
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