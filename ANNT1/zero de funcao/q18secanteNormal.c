//f(x)=2(x+1)(x−0.5)(x−1)

#include<stdio.h>
#include<math.h>


 double f(double x){
    return 2*(x+1)*(x-0.5)*(x-1);
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
   double x0 =-0.4441; //primeiro ponto chutado
   double x1 =0.8991; //segundo ponto chutado
   int n = 5; //numero de iteraçoes

   secante(f, x0,x1, n);


}