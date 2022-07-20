#include <stdio.h>
#include <math.h>
#include <locale.h>
const double eps = 0.000001;	
double dabs(double);
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
int main() {
setlocale(LC_ALL, "Rus");
printf("Корень функции f1 методом деления пополам = %.5f\n", dichotomy(f1,0.,1.));
printf("Корень функции f1 методом итераций = %.5f\n", iteration(F1, 0, 1));
printf("Корень функции f1 методом касательных = %.5f\n", tangent(f1,Fp1,0.,1.));
printf("Корень функции f1 методом хорд = %.5f\n\n", chord(f1,0.,1.));

printf("Корень функции f2 методом деления пополам = %.5f\n", dichotomy(f2,0.5,1.));
printf("Корень функции f2 методом итераций = %.5f\n", iteration(F2,0.5, 1));
printf("Корень функции f2 методом касательных = %.5f\n", tangent(f2,Fp2,0.5,1.));
printf("Корень функции f2 методом хорд = %.5f\n\n", chord(f2,0.5,1.));

printf("Корень функции f3 методом деления пополам = %.5f\n", dichotomy(f3,1.,3.));
printf("Корень функции f3 методом итераций = %.5f\n", iteration(F3,1.,3.));
printf("Корень функции f3 методом касательных = %.5f\n", tangent(f3,Fp3,1.,3.));
printf("Корень функции f3 методом хорд = %.5f\n\n", chord(f3,1.,3.));
return 0;
}
double f1(double x) { return sqrt(1-x) - tan(x); }
double F1(double x) { return 1-tan(x)*tan(x); }
double Fp1(double x) { return -(1/(x*sqrt(1-x)) + 1/(cos(x)*cos(x))); }
double f2(double x) { return x + cos(pow(x, 0.52)+2); }
double F2(double x) { return -cos(pow(x, 0.52)+2); }
double Fp2(double x) { return 1 - (13*sin(pow(x,0.52)+2))/(25*pow(x, 0.48)); }
double f3(double x) { return 3*log(x)*log(x)+6*log(x)-5; }
double F3(double x) { return exp((5 - 3*log(x)*log(x))/6); }
double Fp3(double x) { return 6*(log(x)+1)/x; }
double dabs(double x) { return (x > 0 ? x : -x); }
double dichotomy(double f(double), double a, double b) {
double prevX = b, x = (a + b) / 2.;
while(dabs(prevX - x) > eps) {
if(f(x)*f(a) > 0)
a = x;
else
b = x;
prevX = x;
x = (a + b) / 2.;
}
return x;
}
double iteration(double f(double), double a, double b) {
double prevX = (a+b)/2., x = f(prevX);
while(dabs(x-prevX) > eps) {
prevX = x;
x = f(x);
}
return x;
}
double tangent(double f(double), double F(double), double a, double b) {
double prevX = (a+b/2.), x = prevX - f(prevX)/F(prevX);
while(dabs(prevX - x) > eps) {
prevX = x;
x = prevX - f(prevX)/F(prevX);
}
return x;
}
double chord(double f(double), double a, double b) {
double prevX = b, ya = f(a), yb = f(b);
double x = (ya*b-yb*a)/(ya-yb);
while(dabs(prevX - x) > eps) {
if(ya*f(x) > 0)
a = x;
else
b = x;
ya = f(a), yb = f(b);
prevX = x;
x = (ya*b-yb*a)/(ya-yb);
}
return x;
}
/* Результат:

Корень функции f1 методом деления пополам = 0.57677
Корень функции f1 методом итераций = 0.57677
Корень функции f1 методом касательных = 0.57677
Корень функции f1 методом хорд = 0.57677

Корень функции f2 методом деления пополам = 0.98918
Корень функции f2 методом итераций = 0.98918
Корень функции f2 методом касательных = 0.98918
Корень функции f2 методом хорд = 0.98918

Корень функции f3 методом деления пополам = 1.88324
Корень функции f3 методом итераций = 1.88324
Корень функции f3 методом касательных = 1.88324
Корень функции f3 методом хорд = 1.88324

*/
