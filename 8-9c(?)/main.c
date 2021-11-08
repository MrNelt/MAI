#include <stdio.h>

int max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}

int min(int a, int b){
    return a + b - max(a, b);
}

int inside(int x, int y){
  if (x >= -10 && y <= -x + 10 && y >= x + 10){
    return 1;
  }
  return 0;
}

int main(void){
    const int i_b = 29, j_b = -6, l_b = 1;
    //scanf("%d %d %d", &i_b, &j_b, &l_b);
    int k = 50;
    int i0 = i_b;
    int j0 = j_b;
    int l0 = l_b;
    int counter;
    for (counter = 1; counter < k + 1 && !inside(i0, j0); counter++){
        int i = min(max(min(i0 - j0, i0 - l0), j0 - l0), i0 - (counter - 1)) % 30;
        int j = max(min(max(i0 - j0, i0 - l0), j0 - l0), i0 - (counter - 1)) % 30;
        int l = i0 % 30 - j0 % 30 + l0 % 30 - (counter - 1) % 30;
        printf("%d %d %d %d \n", i, j, l, counter);
        i0 = i;
        j0 = j;
        l0 = l;
    }
    printf("i = %d j = %d l = %d k = %d \n", i0, j0, l0, counter - 1);
    printf("%d \n", -21, 4;
    return 0;
}