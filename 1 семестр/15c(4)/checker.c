#include <stdio.h>

int main(void)
{
    long long t, n;
    long long answer;
    scanf("%lld", &t);
    scanf("%lld", &n);
    long long a[n][n];
    for (long long t0 = 0; t0 < t; t0++) {
        answer = 0;
        long long m;
        scanf("%lld", &m);
        if (m == 0) {
            printf("0 \n");
            continue;
        }
        for (long long i = 0; i < m; i++) {
            for (long long j = 0; j < m; j++) {
                scanf("%lld", &a[i][j]);
            }
        }
        long long minj = a[0][0];
        long long imin = 0;
        long long maxi = a[0][0];
        long long jmax = 0;
        for (long long i = 0; i < m; i++) {
            for (long long j = 0; j < m; j++) {
                if (a[i][j] < minj) {
                    minj = a[i][j];
                    imin = i;
                }
            }
        }
        for (long long j = 0; j < m; j++) {
            for (long long i = 0; i < m; i++) {
                if (a[i][j] > maxi) {
                    maxi = a[i][j];
                    jmax = j;
                }
            }
        }
        for (long long v = 0; v < m; v++) {
            answer += (a[imin][v] * a[v][jmax]);
        }
        printf("%lld \n", answer);
    }
    return 0;
}