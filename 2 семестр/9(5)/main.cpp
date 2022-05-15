#include <stdio.h>
#include <stdlib.h>

int is_sorted = 0;


typedef long double Key; //вещественный ключ


struct DrawingString { //строка таблицы
  Key key;
  char *string;
};

int get_size(FILE *input) { //количество строк в таблице
  int n = 0;
  char *buffer = new char[128];
  size_t l = sizeof(buffer);
  while (!feof(input)) {
    getline(&buffer, &l, input);
    n++;
  }
  delete[] buffer;
  rewind(input);
  return n;
}

void print_table(DrawingString *table, int size) { //вывод таблицы на экран
  for (int i = 0; i < size; ++i) {
    printf("%3Lf  -----  %s", table[i].key,
           table[i].string);
  }
  printf("\n");
}

DrawingString *make_table(FILE *input, int size) { //создание таблицы
  DrawingString *table = new DrawingString[size];
  for (int i = 0; i < size; ++i) {
    table[i].string = new char[128];
  }
  for (int i = 0; i < size; ++i) {
    fscanf(input, "%Lf", &table[i].key);
    fgets(table[i].string, 128, input);
  }
  return table;
}

void sort_table(DrawingString *a, int n) { //индексная сортировка таблицы
  int i, j, k;
  is_sorted = 1;
  DrawingString *b = new DrawingString[n];
  for (int i = 0; i < n; ++i) {
    b[i].string = new char[128];
  }
  for (i = 0; i < n; i++) {
    for (j = k = 0; j < n; j++)
      if (a[j].key < a[i].key || a[j].key == a[i].key && i < j)
        k++;
    b[k] = a[i];
  }
  for (i = 0; i < n; i++)
    a[i] = b[i];
}

void swap_strings(DrawingString *table, int a, int b) { //поменять местами строки
  DrawingString temp;
  temp = table[a];
  table[a] = table[b];
  table[b] = temp;
}

void mix_table(DrawingString *table, int size) { //перемешивание строк
  is_sorted = 0;
  int a, b;
  for (int i = 0; i < size; ++i) {
    a = rand() % size;
    b = rand() % size;
    swap_strings(table, a, b);
  }
}

int bin_search(DrawingString *table, Key key, int size) { //бинарный поиск в отсортированной таблице
  int l = 0, r = size - 1, mid;
  
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

void reverse_strings(DrawingString *table, int size) { //реверс таблицы
  is_sorted = 0;
  for (int i = 0, j = size - 1; i < j; ++i, --j) {
    swap_strings(table, i, j);
  }
}

int main() {
  FILE *input;
  if ((input = fopen("drawing.txt", "r")) == NULL) {
    printf("Error:  can't  input  from  drawing.txt\n");
    return 1;
  }
  int n = get_size(input), action;
  n--;
  DrawingString *table = make_table(input, n);
  print_table(table, n);
  while (1) {
    printf("Menu\n");
    printf("1)  Binary  search\n");
    printf("2)  Sort\n");
    printf("3)  Mix\n");
    printf("4)  Reverse\n");
    printf("5)  Exit\n");
    printf("Choose  an  action\n");
    scanf("%d", &action);
    switch (action) {
    case 1: {
      if (is_sorted) {
        printf("Enter the real key: ");
        Key k;
        scanf("%Lf", &k);
        int search;
        printf("\n");
        search = bin_search(table, k, n);
        if (search == -1) {
          printf("Element  with  such  key  is  not  found!\n");
          break;
        }
        printf("Found  the  string:\n  %s", table[search].string);
      } else
        printf("Table  is  not  sorted!\n");
      break;
    }
    case 2: {
      sort_table(table, n);
      print_table(table, n);
      break;
    }
    case 3: {
      mix_table(table, n);
      print_table(table, n);
      break;
    }
    case 4: {
      reverse_strings(table, n);
      print_table(table, n);
      break;
    }
    case 5:
      return 0;
    }
  }
}
