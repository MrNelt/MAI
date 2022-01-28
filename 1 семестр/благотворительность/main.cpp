#include <stdio.h>
#include <math.h>
#include <locale.h>
const double eps = 0.000001;





double f1(double x) { return sqrt(1 - x) + tan(x); }
double F1(double x) { return 1 + tan(x) * tan(x); }
double Fp1(double x) { return 1 / tan(sqrt(x - 1)); }




double f2(double x) { return sqrt(1 - 0.4 * x * x) - asin(x); }
double F2(double x) { return sqrt((asin(x) * asin(x) - 1) / (-0.4)); }
double Fp2(double x) {return sqrt((1 - (1 / sin(x) * (1 / sin(x)) / 0.4)); }
double f3(double x) { return 1 - x - sin(x) - log(1 + x); }
double F3(double x) { return 1 - sin(x) - log(1 + x); }
double Fp3(double x) { return -1 * cos(x) - 1 / (1 + x); }



double dichotomy(double f(double), double a, double b){
    double prevX = b, x = (a + b) / 2.;
    while (fabs(prevX - x) > eps){
        if (f(x) * f(a) > 0)
            a = x;
        else
            b = x;
        prevX = x;
        x = (a + b) / 2.;
    }
    return x;
}

double iteration(double f(double), double a, double b){
    double prevX = a, x = f(prevX);
    while (fabs(x - prevX) > eps){
        prevX = x;
        x = f(x);
    }
    return x;
}

double tangent(double f(double), double F(double), double a, double b){
    double prevX = (a + b / 2.), x = prevX - f(prevX) / F(prevX);
    while (fabs(prevX - x) > eps){
        prevX = x;
        x = prevX - f(prevX) / F(prevX);
    }
    return x;
}

double chord(double f(double), double a, double b){
    double prevX = b, ya = f(a), yb = f(b);
    double x = (ya * b - yb * a) / (ya - yb);
    while (fabs(prevX - x) > eps){
        if (ya * f(x) > 0)
            a = x;
        else
            b = x;
        ya = f(a), yb = f(b);
        prevX = x;
        x = (ya * b - yb * a) / (ya - yb);
    }
    return x;
}
int main()
{
    printf("----------------------------------------------------\n");
    printf("| Уравнение | Отрезок | Метод | Результат |\n");
    printf("----------------------------------------------------\n");
    printf("| \t 1 | [0;1] | Дихотомии | %.10f |\n", dichotomy(f1, 0, 1));
    printf("----------------------------------------------------\n");
    printf("| \t 1 | [0;1] | Ньютона | %.10f |\n", tangent(f1, Fp1, 0, 1, eps));
    printf("----------------------------------------------------\n");
    printf("| \t 1 | [0;1] | Итераций | %.10f |\n", iteration(F1, 0, 1));
    printf("----------------------------------------------------\n");
    printf("| \t 2 | [0;1] | Дихотомии | %.10f |\n", dichotomy(f2, 0, 1));
    printf("----------------------------------------------------\n");
    printf("| \t 2 | [0;1] | Ньютона | %.10f |\n", tangent(f2, Fp2, 0, 1, eps));
    printf("----------------------------------------------------\n");
    printf("| \t 2 | [0;1] | Итераций | %.10f |\n", iteration(F2, 0, 1));
    printf("----------------------------------------------------\n");
    printf("| \t 3 | [1;1.5] | Дихотомии | %.10f |\n", dichotomy(f3, 1, 1.5));
    printf("----------------------------------------------------\n");
    printf("| \t 3 | [1;1.5] | Ньютона | %.10f |\n", tangent(f2, Fp3, 1, 1.5, eps));
    printf("----------------------------------------------------\n");
    printf("| \t 3 | [1;1.5] | Итераций | %.10f |\n", iteration(F3, 1, 1.5));
    printf("----------------------------------------------------\n");
    return 0;
}