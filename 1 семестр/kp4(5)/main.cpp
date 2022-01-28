#include <stdio.h>
#include <cmath>
#include <locale.h>

const double eps = 0.000001;
double dichotomy(double f(double), double, double);
double iteration(double f(double), double, double);
double tangent(double f(double), double F(double), double, double);
double chord(double f(double), double, double);
double f1(double);
double F1(double);
double Fp1(double);
double f2(double);
double F2(double);
double Fp2(double);
double f3(double);
double F3(double);
double Fp3(double);

int main(void){
    setlocale(LC_ALL, "Rus");
    printf("Корень функции f1 методом деления пополам = %.5f\n", dichotomy(f1,0.,2.));
    printf("Корень функции f1 методом итераций = %.5f\n", iteration(F1, 0., 2.));
    printf("Корень функции f1 методом касательных = %.5f\n", tangent(f1,Fp1,0.,2.));
    printf("Корень функции f1 методом хорд = %.5f\n\n", chord(f1,0.,2.));
    printf("Корень функции f2 методом деления пополам = %.5f\n", dichotomy(f2,1.5,3.));
    printf("Корень функции f2 методом итераций = %.5f\n", iteration(F2, 1.5, 3.));
    printf("Корень функции f2 методом касательных = %.5f\n", tangent(f2,Fp2,1.5, 3.));
    printf("Корень функции f2 методом хорд = %.5f\n\n", chord(f2,1.5, 3.));
    printf("Корень функции f3 методом деления пополам = %.5f\n", dichotomy(f3,0.5,0.9));
    printf("Корень функции f3 методом итераций = %.5f\n", iteration(F3, 0.5, 0.9));
    printf("Корень функции f3 методом касательных = %.5f\n", tangent(f3,Fp3,0.5, 0.9));
    printf("Корень функции f3 методом хорд = %.5f\n\n", chord(f3,0.5, 0.9));
    return 0;
}



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

double f1(double x){
    return 0.25 * x * x * x + x - 1.2502;
}

double F1(double x){
    return 1.2502 - 0.25 * x * x * x;
}

double Fp1(double x){
    return 0.75 * x * x + 1;
}


double f2(double x){
    return x * x + log(x) - exp(1.) * x;
}

double F2(double x){
    return ((exp(1.) * x - log(x)) / x);
}

double Fp2(double x){
    return (2 * x + 1 / x - exp(1.));
}

double f3(double x){
    return cos(x) * log(1./x) + exp(1.) * x * x - 1.5;
}

double F3(double x){
    return (1.5 - cos(x) * log(1./x)) / x / exp(1.);
}

double Fp3(double x){
    return -sin(x) * log(1./x) - cos(x) * x / (x * x) + 2 * exp(1.) * x;
}

