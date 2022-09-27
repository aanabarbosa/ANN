//ln(x^2)=0.7
#include <math.h>


#include <stdio.h>

void bissection(double (*f)(double), double a, double b, int n, double tol);
double f(double x);

int main() {
    double a =
        0.5896;  // intervalo dado ou chutado para fazer o teorema de bolzano
    double b = 2.6879;  // e descobrir se aqui tem ou nao uma raiz
    int vet[20] = {
       8, 9, 10, 13, 14, 15, 16, 17, 18, 20, 21, 24, 25, 28, 30, 32, 35, 37, 38, 39  };  // ordem de parada por interaçoes.                                        
    double tol =
        0.000000000000000000000000000000000000000001;  // ordem de prada pela
                                                       // tolerancia
    for (int i = 0; i < 20; i++) {
        int n = vet[i];
       // printf("v[i]=%d\n",vet[i]);
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
    if(i+1==n){
            printf("%.16f,\n", m);}

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
    return log(x*x)-0.7;  // aqui vai a funçao na qual se busca encontrar as raizes
};



    