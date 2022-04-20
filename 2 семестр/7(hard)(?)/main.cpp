#include <stdio.h>


void print_razr(int *M, int *A, int *V, int n, int m) { //Выводим разреженную матрицу
    int NOZERO = 0;
    for (int i = 0; i < n; i++){
        printf("%d ", M[i]);
        NOZERO += M[i];
    }
    printf("\n");
    for (int i = 0; i < NOZERO; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    for (int i = 0; i < NOZERO; i++){
        printf("%d ", V[i]);
    }
    printf("\n");
}

void print_normal(int **matrix, int n, int m) { //Выводим нормальную матрицу
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void to_razr(int **matrix, int *&M, int *&A, int *&V, int n, int m){ //преобразуем нормальную матрицу в разреженную
    M = new int[n]; //информация про строки -- кол-во ненулевых элементов в строке
    int NOZERO = 0; //Кол-во ненулевых элементов в матрице
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (matrix[i][j] != 0) {
                M[i] += 1;
                NOZERO += 1;
            }
        }
    }
    A = new int[NOZERO];
    V = new int[NOZERO];
    int counter = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (matrix[i][j] != 0) {
                A[counter] = j;
                V[counter] = matrix[i][j];
                counter++;
            }
        }
    }
}

void to_normal(int **matrix, int *M, int *A, int *V, int n, int m){ //пребразование из разреженной в полную
    int counter = 0; //указатель на элемент массива A, V
    for (int i = 0; i < n; i++){
        for (int j = 0; j < M[i]; j++){
            int stolbik = A[counter];
            int value = V[counter];
            matrix[i][stolbik] = value;
            counter++;
        }
    }
}

void summ_razr(int *&M, int *&A, int *&V, int *M1, int *A1, int *V1, int *M2, int *A2, int *V2, int n, int m) { //Сложение двух razr матриц
    int *A_temp, *V_temp;
    M = new int[n];

    int nozero_1 = 0;
    int nozero_2 = 0;

    for (int i = 0; i < n; i++) {
        nozero_1 += M1[i];
        nozero_2 += M2[i];  
    }

    int all_nozero = nozero_1 + nozero_2; //максимальное возможное кол-во ненулевых элементов
    //printf("Кол-во ненулевых: %d\n", all_nozero);
    A_temp = new int[all_nozero];
    V_temp = new int[all_nozero];
    int counter_1 = 0;
    int counter_2 = 0;
    int counter = 0;
    for (int k = 0; k < n; k++) {
        int *temp;
        temp = new int[M1[k] + M2[k]]; //текущая информация о рассмотренных столбиках строки
        for (int i = 0; i < M1[k] + M2[k]; i++) {
            temp[i] = -1;
        }
        int counter_temp = 0;
        int no_zero_temp = 0;
        for (int i = counter_1; i < M1[k] + counter_1; i++) {
            int a_temp = A1[i];
            int v_temp = V1[i];
            for (int j = counter_2; j < M2[k] + counter_2; j++) {
                if (a_temp == A2[j]) {
                    v_temp += V2[j];
                }
            }
            if (v_temp != 0) {
                A_temp[counter] = a_temp;
                V_temp[counter] = v_temp;
                temp[counter_temp] = a_temp;
                counter++;
                no_zero_temp++;
                counter_temp++;
            }
        }
        for (int i = counter_2; i < M2[k] + counter_2; i++) {
            int a_temp = A2[i];
            int v_temp = V2[i];
            int flag = 0; //нужно сделать проверку, что этот ненулевый столбик не проверяли в текущей строке
            for (int i = 0; i < M1[k] + M2[k]; i++) {
                if (a_temp == temp[i]) { //уже рассматривали этот столбик
                    flag = 1;
                    break;
                }
            }
            if (flag == 0){ //дальше как обычно
                for (int j = counter_1; j < M1[k] + counter_1; j++) {
                    if (a_temp == A1[j]) {
                        v_temp += V1[j];
                    }
                }
                if (v_temp != 0) {
                    A_temp[counter] = a_temp;
                    V_temp[counter] = v_temp;
                    counter++;
                    no_zero_temp++;
                }
            }

        }
        counter_1 += M1[k];
        counter_2 += M2[k];
        M[k] = no_zero_temp;
        delete [] temp; 
    }

    A = new int[counter];
    V = new int[counter];
    for (int i = 0; i < counter; i++) {
        A[i] = A_temp[i];
        V[i] = V_temp[i];
    }
    delete [] A_temp;
    delete [] V_temp;
}

bool semetr_razr(int *M, int *A, int *V, int n, int m) {
    //проверка в норм форме -- должно быть a[i][j] = a[j][i]
    int temp_1 = 0;
    for (int num_1 = 0; num_1 < n; num_1++) { //рассматриваем все строки
        for (int i = 0; i < M[num_1]; i++) { //рассматриваем ненулевые элементы строки
            int a_temp_i = A[temp_1 + i];
            int v_temp_i = V[temp_1 + i];
            int flag = 0;
            int temp_2 = 0;
            for (int num_2 = 0; num_2 < n; num_2++) {
                for (int j = 0; j < M[num_2]; j++) {
                    int a_temp_j = A[temp_2 + j];
                    int v_temp_j = V[temp_2 + j];
                    if (num_2 == a_temp_i && a_temp_j == num_1 && v_temp_j == v_temp_i) {
                        flag = 1;
                    }
                }
                temp_2 += M[num_2];
            }
            if (!flag) {
                return false;
            }

        }
        temp_1 += M[num_1];
    }
    return true;
}

void summ_normal(int **matrix, int **matrix1, int **matrix2, int n, int m) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            matrix[i][j] += (matrix1[i][j] + matrix2[i][j]);
        }
    }
}

bool semetr_normal(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int **matrix_1, *M_1, *A_1, *V_1;
    int **matrix_2, *M_2, *A_2, *V_2;
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    matrix_1 = new int*[n];
    matrix_2 = new int*[n];

    for (int i = 0; i < n; i++){
        matrix_1[i] = new int[m];
        matrix_2[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix_1[i][j] = 0;
            matrix_2[i][j] = 0;
        }
    }
    M_1 = new int[n];
    M_2 = new int[n];
    int nozero1 = 0;
    int nozero2 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &M_1[i]);
        nozero1 += M_1[i];
    }
    A_1 = new int[nozero1];
    V_1 = new int[nozero1];
    for (int i = 0; i < nozero1; i++) {
        scanf("%d", &A_1[i]);
    }
    for (int i = 0; i < nozero1; i++) {
        scanf("%d", &V_1[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &M_2[i]);
        nozero2 += M_2[i];
    }
    A_2 = new int[nozero2];
    V_2 = new int[nozero2];
    for (int i = 0; i < nozero2; i++) {
        scanf("%d", &A_2[i]);
    }

    for (int i = 0; i < nozero2; i++) {
        scanf("%d", &V_2[i]);
    }

    to_normal(matrix_1, M_1, A_1, V_1, n, m);
    to_normal(matrix_2, M_2, A_2, V_2, n, m);

    printf("RAZR MATRIX_1:\n");
    print_razr(M_1, A_1, V_1, n, m);
    printf("\n");

    printf("RAZR MATRIX_2:\n");
    print_razr(M_2, A_2, V_2, n, m);
    printf("\n");

    printf("FULL ARRAY_1 FROM RAZR_1:\n");
    print_normal(matrix_1, n, m);
    printf("\n");

    printf("FULL ARRAY_2 FROM RAZR_2:\n");
    print_normal(matrix_2, n, m);
    printf("\n");


    int *M, *A, *V; //сюда будет записана сумма
    printf("SUMMA RAZR MATRIX AND IN NORMAL FORM: \n");
    summ_razr(M, A, V, M_1, A_1, V_1, M_2, A_2, V_2, n, m);
    print_razr(M, A, V, n, m);
    int **matrix;
    matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = 0;
        }
    }
    printf("------------------------------\n");
    to_normal(matrix, M, A, V, n, m);
    print_normal(matrix, n, m);
    if (n == m) {
        if (semetr_razr(M, A, V, n, m)) {
            printf("the matrix is symmetric\n");
        }
        else {
            printf("the matrix is not symmetric\n");
        }
    }
    else {
        printf("the matrix is not symmetric\n");
    }

    printf("\n");
    printf("SUMMA NORMAL MATRIX: \n");
    int **matrix_t;
    matrix_t = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix_t[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix_t[i][j] = 0;
        }
    }
    summ_normal(matrix_t, matrix_1, matrix_2, n, m);
    print_normal(matrix_t, n, m);
    int *M_t, *A_t, *V_t;
    to_razr(matrix_t, M_t, A_t, V_t, n, m);
    printf("------------------------------\n");
    print_razr(M_t, A_t, V_t, n, m);
    if (n == m) {
        if (semetr_normal(matrix_t, n, m)) {
            printf("the matrix is symmetric\n");
        }
        else {
            printf("the matrix is not symmetric\n");
        }
    }
    else {
        printf("the matrix is not symmetric\n");
    }
    return 0;
}