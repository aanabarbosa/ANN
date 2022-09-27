//f(x)=πx−e^x

#include<stdio.h>
#include<math.h>
#define pi 3.14159265359

 double f(double x){
    return pi*x-exp(x);
    };

void secante(double (*f)(double), double x0, double x1, int n){
    for(int i =0 ; i< n ; i++){
        double fx0 = f(x0);
        double fx1 = f(x1);
        if(fx0 == fx1){  // verifia se nao vai dar divisao por 0
            break;
        }
       double x2 = ((x0*fx1 - x1*fx0) / (fx1 - fx0)); 
       printf("x_%d = %.16f\n", i+2,x2);
       x0 = x1;
       x1 = x2;
    }
};


int main(){
   double x0 =1.23934; //primeiro ponto chutado
   double x1 = 2.00994; //segundo ponto chutado
   int n = 5; //numero de iteraçoes

   secante(f, x0,x1, n);


}