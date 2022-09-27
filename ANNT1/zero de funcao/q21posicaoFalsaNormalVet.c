//f(x)=πx−e^x

#include <stdio.h>
#include <math.h>
#define pi 3.14159265359

double f(double x) { return pi*x-exp(x); };

double secante(double (*f)(double), double a, double b, int n) {
    double x1;
    for (int i = 0; i < n; i++) {
        double fa = f(a);
        double fb = f(b);
        if (fa * fb >=
            0) {  // verifia se  cada ponto esta do aldo oposto do eixo x
            printf(
                "O teorema de Bolzano n sabe dizer se existe raiz para f nesse "
                "intervalo.\n");
            break;
        }
         x1 = ((a * fb - b * fa) / (fb - fa));  // expressao
                                                      // caracteristica
        //printf("x_%d = %.16f\n", i + 1, x1);

        // testes para saber qual lado continuar, bissecao
        double fx1 = f(x1);
        if (fa * fx1 < 0) {
            b = x1;
            fb = fx1;
        } else {
            a = x1;
            fa = fx1;
        }
    }
    return x1;
};

int main() {
    double a = 0.2374;  // primeiro ponto chutado
    double b =  1.0147;  // segundo ponto chutado
    int vet[10] = {2, 4, 5, 6, 10, 11, 14, 15, 17, 18};    // numero de iteraçoes

for(int i=0 ;i<10;i++){
    double xi = secante(f, a, b, vet[i]);
     printf("%.16f,", xi);
}
}