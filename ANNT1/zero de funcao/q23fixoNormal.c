//g(x)=x/2+1/x

#include<stdio.h>
#include<math.h>

double f(double x){
    return x/2+1/x;
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
    double x0 = 1.65849   ;
    
    fixed_point(f,x0, n);
}
