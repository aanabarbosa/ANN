#include <stdio.h>

double f(double x);
double df(double x);

void newton(double (*f)(double), double (*df)(double),double x0, int n){
    for(int i =0; i<n;i++){
        double dfx0 = df(x0);
        if(dfx0==0){
            break;
        }
       double xi = x0 - f(x0)/df(x0);
       printf("x_%d = %.16f\n", i+1, xi);
       x0 = xi; //atualizaçao para proxima iteraçao
    }
}

   // raiz é -0.1690770973
    double f(double x){
        return x* (x-1) *(x-2) +0.43123123123;
    };

    double df (double x){
        return 3 * (x - 2) * x + 2;
    };


int main(){
    

//METODO DE NEWTON DANDO ERRADO
 

    double x0 = 2; // chute inicial
    int n = 40; //limitaçao do numero de interaçoes

    newton(f, df, x0, n);// passa a funçao, passa o chute inicila, e o numero maximo de interaçoes

}