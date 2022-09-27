// Use o metodo da bisseçao p/ encontrar aproximaçoes p/ a raiz
//  de f(x)=x^2-3 no intervalo [1,2]. execute 10 interaçoes

#include <math.h>
#include <stdio.h>

void bissection(double (*f)(double), double a, double b, int n, double tol);
double f(double x);

int main() {
    double a =
        1.5701;  // intervalo dado ou chutado para fazer o teorema de bolzano
    double b = 5.1364;  // e descobrir se aqui tem ou nao uma raiz
    int vet[20] = {
        2 , 3, 6, 7, 8, 9, 10, 15, 16, 19, 22, 23, 27, 28, 29, 30, 32, 36, 38, 39 };  // ordem de parada por interaçoes.                                        
    double tol =
        0.000000000000000000000000000000000000000001;  // ordem de prada pela
                                                       // tolerancia
    for (int i = 0; i < 20; i++) {
        int n = vet[i];
        printf("v[i]=%d\n",vet[i]);
        bissection(f, a, b, n, tol);
        printf("\n");
    }
}

void bissection(double (*f)(double), double a, double b, int n,
                double tol) {  //
    double fa = f(a);          // aqui inicia bolzano
    double fb = f(b);

    if (fa * fb >= 0) {  // verificaçao dp teorema em si
        printf(
            "A existencia de raiz no inertvalo [%.16lf,%.16lf] eh "
            "inconclusiva.\n",
            a, b);
        return;

        // aqui encerra bolzano
    } else {
        for (int i = 0; i < n; i++) {
            double m = 0.5 * (a + b);  // CALCULO DO PONTO MEDIO DO INTERVALO
            double fm = f(m);
            if (fm == 0) {  // VERIFICA SE ESSE PONTO MEDIO JÁ NAO É UMA RAIZ
                printf("%.16lf eh uma raiz\n", m);
                return;
            }

            printf("m_%d = %.16f\n", i + 1, m);

            if (fabs(fm) < tol) {
                printf("atingiu a tolerancia de m => m_%d = %.16f\n", i + 1, m);
                return;
            }
            if (fabs((fa - fb)) < tol) {
                printf("atingiu a tolerancia de intervalo => m_%d = %.16f.\n",
                       i + 1, m);
                       return;
            }

            if (fa * fm < 0) {  // Verifica se f(m) está do lado aposto de fa em
                                // realcao ao eixo x.
                b = m;  // entao pelo teorema de bolzano a raiz esta no
                        // intervalo [a,m]. atualiza-se m como o novo b.
                fb = fm;
            } else {  // se fa e fm estao do mesmo lado do eixo x então a raiz
                      // esta para a outra metade do intervalo
                a = m;
                fa = fm;
            }
        }
    }
}
double f(double x) {
    return (pow(x,2)-4.6806*x+1.4504);  // aqui vai a funçao na qual se busca encontrar as raizes
};