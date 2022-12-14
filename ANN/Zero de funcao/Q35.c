#include <stdio.h>
#include <math.h>

#define V 35.43
#define L 2.71
#define r 3.08

void false_position(double (*f)(double),double a,double b,int n){
    double fa = f(a);
    double fb = f(b);
    if(fa * fb >= 0){
        printf("O Teorema de Bolzano não sabe dizer se existe raiz para f no intervalo [%.16f, %.16f]",a,b);
        return;
    }else {
        double x;
        for(int i =0;i<n;i++){
            x = (a *fb - b * fa) / (fb - fa);
            printf("x_%d = %.16lf\n", i+1,x);
            double fx = f(x);
            if(fx == 0){
                printf("Encontramos uma raiz para f, ela é x = %.16lf",x);
                return;
            }
            if(fa * fx < 0){
                b = x;
                fb = fx;
            }else{
                a = x;
                fa = fx;
            }
        }
    }
}
 double f(double h)
	{

    return L*((0.5*3.14159265359*pow(r,2)) - pow(r,2)*asin(h/r)- h*(sqrt(pow(r,2)-pow(h,2))))-V;
	};

int main(){
   
    //intervalo iniial
    double a = 0;
    double b = 3.07999;

    int n =11; // número de iterações

    false_position(f,a,b,n);
};
