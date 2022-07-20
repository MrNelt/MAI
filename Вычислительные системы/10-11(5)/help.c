#include <stdio.h>


int to_3(int n){
  int t = 1;
  int ans = 0;
  while (n > 0){
    int e = n % 3;
    n /= 3;
    ans = ans + e * t;
    t *= 10;
    //printf("%d, %d \n", ans, n);
  }
  return ans;
}

int main(void){
  int n;
  scanf("%d", &n);
  //printf("%d \n", to_3(n));
  for (int i = 0; i <= n; i++){
    if (i % 3 == 0){
      printf("%d, %d \n", i, to_3(i));
    }
  }
  return 0;
}
