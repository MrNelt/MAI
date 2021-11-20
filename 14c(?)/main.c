#include <stdio.h>


int main(void){
  int a[10][10];
  int n;
  printf("Введите размер матрицы n * n: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++){ //ввод матрицы
    for (int j = 0; j < n; j++){
      a[i][j] = (i + 1) * 10 + j + 1;
    }
  }
  printf("Заданная матрица: \n");
  for (int i = 0; i < n; i++){ //вывод матрицы
    for (int j = 0; j < n; j++){
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  int i = (n + 1) / 2 - 1;  //центральная точка матрицы(начальная точка обхода)
  int j = (n + 1) / 2 - 1;
  if (n > 0){ //на случай если в матрице 0 элементов
    printf("%d ", a[i][j]);
  }
  for (int counter = 1, k = 0; counter < n; counter++, k++){
    if (k % 2 == 0){
      for (int i0 = 0; i0 < counter; i0++){ //вертикальный нижний цикл
        printf("%d ", a[++i][j]);
      }
      for (int j0 = 0; j0 < counter; j0++){ //горизонтальный правый цикл
        printf("%d ", a[i][++j]);
      }
    }
    if (k % 2 == 1){
      for (int i0 = counter - 1; i0 >= 0; i0--){ //вертикальный верхний цикл
        printf("%d ", a[--i][j]);
      }
      for (int j0 = counter - 1; j0 >= 0; j0--){ //горизонтальный левый цикл
        printf("%d ", a[i][--j]);
      }
    }
  }
  if (n != 1 && i == 0){ //заполнение последней вертикальной линии
      for (int h = 1; h < n; h++){ //вертикальный нижний цикл
          printf("%d ", a[h][j]);
      }
  }
  else if (n != 1 && i == n - 1){
      for (int h = n - 2; h >= 0; h--){ //вертикальный верхний цикл
          printf("%d ", a[h][j]);
      }
  }
  printf("\n");
  return 0;
}
