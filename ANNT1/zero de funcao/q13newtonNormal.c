//f(x)=x−2^(−x)
//df = 1+ln(2)*2^(-x)
#include <stdio.h>
#include<math.h>
#define pi 3.14159265359

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

  double f(double x){
        return x-pow(2,-x); //coloca aqui a funçao
    };
    
    double df(double x){
        return 1+log(2)*pow(2,-x); //calular a derivada em algum outro software, VAI NO WOLFAMALPHA, ESCREVE DERIVATIVE NA FRENTE DA FUNÇAO, CLICA EM CALCULAR, DEPOIS POROCURA A ABA "ALTERNATE FORMS", CLICA EM PLAIN TEXT, CLICA EM CIMA DA FUNÇAO QUE ESTA NO CAMPO "COPYABLE PLAIN TEXT"
    };

int main(){
    
  
    double x0 = 1.5618  ; // chute inicial
    int n = 5; //limitaçao do numero de interaçoes

    newton(f, df, x0, n);// passa a funçao, passa o chute inicila, e o numero maximo de interaçoes

}