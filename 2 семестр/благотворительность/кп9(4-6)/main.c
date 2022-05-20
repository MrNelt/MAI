#include <stdio.h>
#include <stdlib.h>

int is_sorted = 0;


typedef float Key; //вещественный ключ


struct PoetryString { //строка таблицы
  Key key;
  char *string;
};

int get_size(FILE *input) { //количество строк в таблице
  int n = 0;
  char *buffer;
  buffer = (char*) malloc(128 * sizeof(char));
  size_t l = sizeof(buffer);
  while (!feof(input)) {
    getline(&buffer, &l, input);
    n++;
  }
  free(buffer);
  rewind(input);
  return n;
}

void print_table(struct PoetryString *table, int size) { //вывод таблицы на экран
  for (int i = 0; i < size; ++i) {
    printf("%3f  -----  %s", table[i].key,
           table[i].string);
  }
  printf("\n");
}

struct PoetryString *make_table(FILE *input1, FILE *input2, int size) { //создание таблицы
  struct PoetryString* table;
  table = (struct PoetryString*) malloc(size * sizeof(struct PoetryString));
  for (int i = 0; i < size; ++i) {
    table[i].string = (char*) malloc(128 * sizeof(char));
  }
  for (int i = 0; i < size; ++i) {
    fgets(table[i].string, 128, input1);
  }
  for (int i = 0; i < size; ++i) {
    fscanf(input2, "%f", &table[i].key);
  }
  return table;
}

void swapEl(struct PoetryString *arr, int i)
{
 struct PoetryString buff;
 buff = arr[i];
 arr[i] = arr[i - 1];
 arr[i - 1] = buff;
}

void ShakerSort_table(struct PoetryString *arr, int size) { //шейкерная сортировка таблицы
  is_sorted = 1;
  int leftMark = 1;
  int rightMark = size - 1;
  while (leftMark <= rightMark) {
    for (int i = rightMark; i >= leftMark; i--)
      if (arr[i - 1].key > arr[i].key)
        swapEl(arr, i);
    leftMark++;

    for (int i = leftMark; i <= rightMark; i++)
      if (arr[i - 1].key > arr[i].key)
        swapEl(arr, i);
    rightMark--;
  }
}

void swap_strings(struct PoetryString *table, int a, int b) { //поменять местами строки
  struct PoetryString temp;
  temp = table[a];
  table[a] = table[b];
  table[b] = temp;
}

void mix_table(struct PoetryString *table, int size) { //перемешивание строк
  is_sorted = 0;
  int a, b;
  for (int i = 0; i < size; ++i) {
    a = rand() % size;
    b = rand() % size;
    swap_strings(table, a, b);
  }
}

int bin_search(struct PoetryString *table, Key key, int size) { //бинарный поиск в отсортированной таблице
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

void reverse_strings(struct PoetryString *table, int size) { //реверс таблицы
  is_sorted = 0;
  for (int i = 0, j = size - 1; i < j; ++i, --j) {
    swap_strings(table, i, j);
  }
}

int main() {
  FILE *input1;
  FILE *input2;
  if ((input1 = fopen("poetry.txt", "r")) == NULL) {
    printf("Error:  can't  input  from  poetry.txt\n");
    return 1;
  }
  if ((input2 = fopen("keys.txt", "r")) == NULL) {
    printf("Error:  can't  input  from  keys.txt\n");
    return 1;
  }
  int n = get_size(input1), action;
  n--;
  struct PoetryString *table = make_table(input1, input2, n);
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
        scanf("%f", &k);
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
      ShakerSort_table(table, n);
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
