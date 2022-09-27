#include <stdio.h>
#include <math.h>

double f(double x) { 
    return ((3.14159265359*pow(x,2))/(3))*(3*8.01-x)-(548.3390856550); };

void secante(double (*f)(double), double a, double b, int n) {
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
        double x1 = ((a * fb - b * fa) / (fb - fa));  // expressao
                                                      // caracteristica
        printf("x_%d = %.16f\n", i + 1, x1);

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
};

int main() {
    double a = 0;  // primeiro ponto chutado
    double b = 16.02;  // segundo ponto chutado
    int n = 11;    // numero de iteraçoes

    secante(f, a, b, n);
}


// Q28 refazer

// #include <stdio.h>
// #include <math.h>

// double f(double x) { return ((9.81*x)/22.87)*(1-exp(-(22.87/x)*8.89)) - 31.77; };

// void secante(double (*f)(double), double a, double b, int n) {
//     for (int i = 0; i < n; i++) {
//         double fa = f(a);
//         double fb = f(b);
//         if (fa * fb >=
//             0) {  // verifia se  cada ponto esta do aldo oposto do eixo x
//             printf(
//                 "O teorema de Bolzano n sabe dizer se existe raiz para f nesse "
//                 "intervalo.\n");
//             break;
//         }
//         double x1 = ((a * fb - b * fa) / (fb - fa));  // expressao
//                                                       // caracteristica
//         printf("x_%d = %.16f\n", i + 1, x1);

//         // testes para saber qual lado continuar, bissecao
//         double fx1 = f(x1);
//         if (fa * fx1 < 0) {
//             b = x1;
//             fb = fx1;
//         } else {
//             a = x1;
//             fa = fx1;
//         }
//     }
// };

// int main() {
//     double a = 22.93;  // primeiro ponto chutado
//     double b = 180.08;  // segundo ponto chutado
//     int n = 11;    // numero de iteraçoes

//     secante(f, a, b, n);
// }