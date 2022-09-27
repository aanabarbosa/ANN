#include<stdio.h>
#include<math.h>

double f(double x){
    return ((3*pow(x,4)+2*pow(x,2)+3)/(4*pow(x,3)+4*x-1));
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
    double x0 = 1.95018   ;
    //0.739085133215161

    fixed_point(f,x0, n);
}
