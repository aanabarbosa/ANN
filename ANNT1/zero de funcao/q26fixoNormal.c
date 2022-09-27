//g(x)=(3x^4+2x^2+3)/(4x^3+4x−1)

#include<stdio.h>
#include<math.h>

double f(double x){
    return (3*x*x*x*x+2*x*x+3)/(4*x*x*x+4*x-1);
}

void fixed_point(double (*f)(double), double x0, int n){
    for (int i = 0 ;i < n; i++){
        double x1 = f(x0);
        printf("%.16f,", x1);
        x0 = x1;
    }
}

int main (int argc, char **argv){

    int n = 8;
    double x0 =1.95018   ;
    
    fixed_point(f,x0, n);
}
