#include <stdio.h>

int main(void){
    int num;
    scanf("%d", &num);
    int last_num = -1; //так как последнюю цифру числа не с чем сравнивать => берем его в любом случае во 2 число,
    //поэтому сравнение идет с -1
    int num1 = 0;
    int num2 = 0;
    int t1 = 1; //степени десятки для первого и второго числа
    int t2 = 1;
    while (num > 0){
        int e = num % 10; //текущая цифра числа
        num /= 10; //отсечение последней цифры числа
        if (e < last_num){
            num1 += t1 * e;
            t1 *= 10;
        }
        else {
            num2 += t2 * e;
            t2 *= 10;
        }
        last_num = e;
    }
    printf("%d, %d, %d \n", num1, num2, num1 + num2);
}