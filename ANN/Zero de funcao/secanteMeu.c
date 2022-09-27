#include<stdio.h>
#include<math.h>



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
 double f(double x){
    return ((3.14159265359*pow(x,2))/(3))*(3*8.01-x)-(548.3390856550);
    };


int main(){
   double x0 = 1.84    ; //primeiro ponto chutado
   double x1 = 15.62    ; //segundo ponto chutado
   int n = 5; //numero de iteraçoes

   secante(f, x0,x1, n);


}

//Q28

// #include<stdio.h>
// #include<math.h>



// void secante(double (*f)(double), double x0, double x1, int n){
//     for(int i =0 ; i< n ; i++){
//         double fx0 = f(x0);
//         double fx1 = f(x1);
//         if(fx0 == fx1){  // verifia se nao vai dar divisao por 0
//             break;
//         }
//        double x2 = ((x0*fx1 - x1*fx0) / (fx1 - fx0)); 
//        printf("x_%d = %.16f\n", i+2,x2);
//        x0 = x1;
//        x1 = x2;
//     }
// };
//  double f(double x){
//     return ((9.81*x)/22.87)*(1-exp(-(22.87/x)*8.89)) - 31.77;
//     };


// int main(){
//    double x0 = 20.56  ; //primeiro ponto chutado
//    double x1 = 38.8  ; //segundo ponto chutado
//    int n = 5; //numero de iteraçoes

//    secante(f, x0,x1, n);


// }