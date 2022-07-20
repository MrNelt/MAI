#include <stdio.h>


int main(void)
{
    int t, n;
    scanf("%d", &t);
    scanf("%d", &n);
    int a[n][n];
    for (int g = 0; g < t; g++) {
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++) { //ввод матрицы
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        int i = (m + 1) / 2 - 1;  //центральная точка матрицы(начальная точка обхода)
        int j = (m + 1) / 2 - 1;
        if (m > 0) {
            printf("%d ", a[i][j]);
        }
        for (int counter = 1, k = 0; counter < m; counter++, k++) {
            if (k % 2 == 0) {
                for (int i0 = 0; i0 < counter; i0++) {
                    printf("%d ", a[++i][j]);
                }
                for (int j0 = 0; j0 < counter; j0++) {
                    printf("%d ", a[i][++j]);
                }
            }
            if (k % 2 == 1) {
                for (int i0 = counter - 1; i0 >= 0; i0--) {
                    printf("%d ", a[--i][j]);
                }
                for (int j0 = counter - 1; j0 >= 0; j0--) {
                    printf("%d ", a[i][--j]);
                }
            }
        }
        if (m != 1 && i == 0) {
            for (int h = 1; h < m; h++) {
                printf("%d ", a[h][j]);
            }
        } else if (m != 1 && i == m - 1) {
            for (int h = m - 2; h >= 0; h--) {
                printf("%d ", a[h][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
