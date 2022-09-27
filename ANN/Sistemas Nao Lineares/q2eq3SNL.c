#include <stdio.h>
#include<math.h>

    // exemplo
    double f1(double x, double y) {
        return pow(x,2)+pow(y,2)-5;
    }

    double f2(double x, double y) {
        return x-3/x+pow(y,3);
    }

    double f1x(double x, double y) {
        return 2 * x;
    }

    double f1y(double x, double y) {
        return 2 * y;
    }

    double f2x(double x, double y) {
        return (pow(x,2)+3)/pow(x,2);
    }

    double f2y(double x, double y) {
        return 3*pow(y,2);
    }


int main() {


    int n = 5;
    double x0 =  -2.4215;
    double y0 =  0.5636;

    // newton
    for (int i = 0; i < n; i++) {
        // jacobiano
        //[f1x f1y]
        //[f2x f2y]
        // inversa, antes de 1 / det
       // [f2y -f1y] [f1]
       // [-f2x f1x] [f2]
       double a = f1x(x0, y0);
       double b = f1y(x0, y0);
       double c = f2x(x0, y0);
       double d = f2y(x0, y0);
       long double det = a * d - b * c;
       long double xk = x0 - (f2y(x0, y0) * f1(x0, y0) -f1y(x0, y0) * f2(x0, y0)) / det;
       long double yk = y0 - (-f2x(x0, y0) * f1(x0, y0) + f1x(x0, y0) * f2(x0, y0)) / det;
       x0 = xk;
       y0 = yk;
       printf("x^(%d) = %.7lf\ty^(%d) = %.7lf\n", i + 1, x0, i + 1, y0);
    }

}
