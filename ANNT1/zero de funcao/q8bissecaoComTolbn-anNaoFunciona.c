
//|bn−an|<4.39057⋅10−11,
//f(x)=x^3−7x^2+14x−7

#include <stdio.h>
#include <math.h>

void bissection(double (*f)(double), double a, double b, double n, double tol);
double f(double x);


int main(){
    double a = 3.203647;  // intervalo dado ou chutado para fazer o teorema de bolzano               
    double b = 4.283224;// e descobrir se aqui tem ou nao uma raiz
    int n = 64;  // ordem de parada por interaçoes. nesse caso 10 iteraçoes
    double tol =  4.39057e-11; //ordem de prada pela tolerancia
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



            // printf("m_%d = %.16f\n",i+1, m);

            // if(fabs(fm)<tol){
            //     printf("atingiu a tolerancia de m => m_%d = %.16f\n",i+1,m);
            //     return;}

            //  printf("fb-fa = %f\n"),fabs((fb-fa));




            // if(fabs((fb-fa))<tol ){
            //     printf("atingiu a tolerancia de intervalo => m_%d = %.16f.\n",i+1,m);
            //     return;
            // }




                 if(fabs(fm)<tol) {
                printf("atingiu a tolerancia => x_%d = %.16f\n",i+1,m);
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
        return x*x*x-7*x*x+14*x-7;
                  // aqui vai a funçao na qual se busca encontrar as raizes
    };


    