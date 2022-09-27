//f(x)=e^(5x)−2
// df = 5e^(5x)

#include <stdio.h>
#include <math.h>

double f(double x);
double df(double x);

double newton(double (*f)(double), double (*df)(double),double x0, int n){
    double xi;
    for(int i =0; i<n;i++){
        double dfx0 = df(x0);
        if(dfx0==0){
            break;
        }
       xi = x0 - f(x0)/df(x0);
       x0 = xi; //atualizaçao para proxima iteraçao
    }
    return xi;
}

 double f(double x){
        return exp(5*x)-2; //coloca aqui a funçao
    };
    
    double df(double x){
        return 5*exp(5*x); //calular a derivada em algum outro software, VAI NO WOLFAMALPHA, ESCREVE DERIVATIVE NA FRENTE DA FUNÇAO, CLICA EM CALCULAR, DEPOIS POROCURA A ABA "ALTERNATE FORMS", CLICA EM PLAIN TEXT, CLICA EM CIMA DA FUNÇAO QUE ESTA NO CAMPO "COPYABLE PLAIN TEXT"
    };

int main(){
    
   
    double x0 = -1.16633453 ; // chute inicial
    int vet[16] = {1, 25, 50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700};
     //limitaçao do numero de interaçoes
for(int i = 0; i<16;i++){
    double xi;
    xi = newton(f, df, x0, vet[i]);// passa a funçao, passa o chute inicila, e o numero maximo de interaçoes
    printf("%.16f,",xi);
};
}