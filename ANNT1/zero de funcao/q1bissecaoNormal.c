//e^x−2x^2+x−1.5

#include <stdio.h>
#include <math.h>

void bissection(double (*f)(double), double a, double b, double n, double tol);
double f(double x);


int main(){
    double a =  1.65328;  // intervalo dado ou chutado para fazer o teorema de bolzano               
    double b =   2.62499;// e descobrir se aqui tem ou nao uma raiz
    int n = 7;  // ordem de parada por interaçoes. nesse caso 10 iteraçoes
    double tol =  0.0000000000000000001; //ordem de prada pela tolerancia
    bissection(f, a, b, n, tol);
}

void bissection(double (*f)(double), double a, double b, double n, double tol) { //
    double fa = f(a);  // aqui inicia bolzano
    double fb = f(b);

    if (fa * fb >= 0) {  //verificaçao dp teorema em si
        printf("A existencia de raiz no inertvalo [%.16lf,%.16lf] eh inconclusiva.\n", a, b);
        return;

        
// aqui encerra bolzano
    } else {
        for(int i=0;i<n;i++){
            double m= 0.5 * (a + b); // CALCULO DO PONTO MEDIO DO INTERVALO
            double fm = f(m);
            if(fm == 0){  // VERIFICA SE ESSE PONTO MEDIO JÁ NAO É UMA RAIZ
                printf("%.16lf eh uma raiz\n", m);
                return;
            }



            printf("m_%d = %.16f\n",i+1, m);

            // if(fabs(fm)<tol){
            //     printf("atingiu a tolerancia de m => m_%d = %.16f\n",i+1,m);
            //     return;}

            //  printf("fb-fa = %f\n"),fabs((fb-fa));
            //     printf("tol =%f\n"),tol;
            if(fabs((fb-fa))<tol ){
                printf("%16.f\n"),fabs((fb-fa));
                printf("%16.f\n"),tol;
                printf("atingiu a tolerancia de intervalo => m_%d = %.16f.\n",i+1,m);
                return;
            }



            if(fa * fm <= 0){  // Verifica se f(m) está do lado aposto de fa em realcao ao eixo x.
                b = m ;       // entao pelo teorema de bolzano a raiz esta no intervalo [a,m]. atualiza-se m como o novo b.
                fb = fm;
            }else{   // se fa e fm estao do mesmo lado do eixo x então a raiz esta para a outra metade do intervalo
                a = m;  
                fa = fm;
            }
        }
    }
}
double f(double x){
        return exp(x)-2*x*x+x-1.5;
                  // aqui vai a funçao na qual se busca encontrar as raizes
    };


    