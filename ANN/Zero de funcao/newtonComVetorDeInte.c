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
        return (x*(x-1)*(x-2)+0.42); //coloca aqui a funçao
    };
    
    double df(double x){
        return (3*pow(x,2)-6*x+2); //calular a derivada em algum outro software, VAI NO WOLFAMALPHA, ESCREVE DERIVATIVE NA FRENTE DA FUNÇAO, CLICA EM CALCULAR, DEPOIS POROCURA A ABA "ALTERNATE FORMS", CLICA EM PLAIN TEXT, CLICA EM CIMA DA FUNÇAO QUE ESTA NO CAMPO "COPYABLE PLAIN TEXT"
    };

int main(){
    
   
    double x0 = 2.99373205 ; // chute inicial
    int vet[39] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180, 185, 190, 195};
     //limitaçao do numero de interaçoes
for(int i = 0; i<39;i++){
    double xi;
    xi = newton(f, df, x0, vet[i]);// passa a funçao, passa o chute inicila, e o numero maximo de interaçoes
    printf("%.16f,",xi);
};
}