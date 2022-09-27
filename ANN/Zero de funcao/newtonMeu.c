#include <stdio.h>
#include <math.h>

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
        return ((3.14159265359*pow(x,2))/(3))*(3*8.01-x)-(548.3390856550); //coloca aqui a funçao
    };
    
    double df(double x){
        return  x*(50.3283-3.14159*x); //calular a derivada em algum outro software, VAI NO WOLFAMALPHA, ESCREVE DERIVATIVE NA FRENTE DA FUNÇAO, CLICA EM CALCULAR, DEPOIS POROCURA A ABA "ALTERNATE FORMS", CLICA EM PLAIN TEXT, CLICA EM CIMA DA FUNÇAO QUE ESTA NO CAMPO "COPYABLE PLAIN TEXT"
    };

int main(){
    
  
    double x0 = 7.4   ; // chute inicial
    int n = 50; //limitaçao do numero de interaçoes

    newton(f, df, x0, n);// passa a funçao, passa o chute inicila, e o numero maximo de interaçoes

}

//Q28 reafzer

// #include <stdio.h>
// #include <math.h>

// double f(double x);
// double df(double x);

// void newton(double (*f)(double), double (*df)(double),double x0, int n){
//     for(int i =0; i<n;i++){
//         double dfx0 = df(x0);
//         if(dfx0==0){
//             break;
//         }
//        double xi = x0 - f(x0)/df(x0);
//        printf("x_%d = %.16f\n", i+1, xi);
//        x0 = xi; //atualizaçao para proxima iteraçao
//     }
// }

//   double f(double x){
//         return ((9.81*x)/22.87)*(1-exp(-(22.87/x)*8.89)) - 31.77; //coloca aqui a funçao
//     };
    
//     double df(double x){
//         return  exp((-203.314/x))*(-87.2109/x - 0.428946) + 0.428946 ; //calular a derivada em algum outro software, VAI NO WOLFAMALPHA, ESCREVE DERIVATIVE NA FRENTE DA FUNÇAO, CLICA EM CALCULAR, DEPOIS POROCURA A ABA "ALTERNATE FORMS", CLICA EM PLAIN TEXT, CLICA EM CIMA DA FUNÇAO QUE ESTA NO CAMPO "COPYABLE PLAIN TEXT"
//     };

// int main(){
    
  
//     double x0 = 26.76; // chute inicial
//     int n = 6; //limitaçao do numero de interaçoes

//     newton(f, df, x0, n);// passa a funçao, passa o chute inicila, e o numero maximo de interaçoes

// }

