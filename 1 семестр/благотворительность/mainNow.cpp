#include <stdio.h>
#include <math.h>

int get_byte(int a, int n){
  return (a >> ((n - 1) * 8)) & 255;
}

int main(){
  int n;
  scanf("%d", &n);
  int b_1 = get_byte(n, 1);
  int b_1r = 0;
  for (int i = 128; i > 0; i /= 2){
    b_1r += (b_1 % 2) * i;
    b_1 /= 2; 
  }
  int d = 1;
  int n_new = 0;
  for (int i = 0; i <= 7; i++){
    n_new += (b_1r % 2) * d;
    b_1r /= 2;
    d *= 2;
  }
  printf("%d", n_new);
  return 0;
}