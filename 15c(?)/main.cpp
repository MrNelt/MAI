#include <time.h>
#include <stdio.h> 
#include <stdlib.h>


int main(void){
    int **a, n, answer = 0;
    scanf("%d", &n);
    a = new int*[n];
    srand(time(0));
    for (int i = 0; i < n; i++){//создание матрицы
        a[i] = new int[n];
    }
    for (int i = 0; i < n; i++){ //ввод матрицы и вывод матрицы
        for (int j = 0; j < n; j++){
            a[i][j] = rand() % 15;
            printf(" %3d", a[i][j]);
        }
        printf("\n");
    }
    int minj = a[0][0]; //минимальный элемент строки
    int imin = 0; //номер строки
    int maxi = a[0][0]; //максимальный элемент столбцы
    int jmax = 0; //номер столбца
    for (int i = 0; i < n; i++){ //поиск номера строки с минимальным элементом(самая первая строка с этим элементом)
        for (int j = 0; j < n; j++){
            if (a[i][j] < minj){
                minj = a[i][j];
                imin = i;
            }
        }
    }
    for (int j = 0; j < n; j++){ //поиск номера столбца с максимальным элементом(самый первый столбец с этим элементом)
        for (int i = 0; i < n; i++){
            if (a[i][j] > maxi){
                jmax = j;
                maxi = a[i][j];
            }
        }
    }
    for (int v = 0; v < n; v++){ //подсчет ответа
        answer += (a[v][jmax] * a[imin][v]);
    }
    printf("%d \n", answer);  
    return 0;
}