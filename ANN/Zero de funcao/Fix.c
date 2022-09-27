#include<stdio.h>
#include<math.h>

double f(double x){ // usando f apenas para conferencia
    return pow(x,2)-2;
}

double g(double x){
    return x/2 + 1/x; // funçao para modificar é essa
}

void fixed_point(double (*g)(double),double (*f)(double), double x0, int n){
    for (int i = 0 ;i < n; i++){
        x0 = g(x0);
        printf("x_%d = %.16f e f(x0) = %.16f\n", i+1, x0, f(x0));

    }
}

int main (int argc, char **argv){

    int n = 10;
    double x0 = 1.23456; // tem q estar dentro de [a,b]


    fixed_point(g,f,x0, n);
}
