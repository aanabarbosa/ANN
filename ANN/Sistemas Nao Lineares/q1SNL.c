#include <stdio.h>
#include<math.h>

    // exemplo
    double f1(double x, double y) {
        return pow(x,2)+2*pow(y,2)-3;
    }

    double f2(double x, double y) {
        return 4*pow(x,2)+pow(y,2)-6;
    }

    double f1x(double x, double y) {
        return 2 * x + 4*y;
    }

    double f1y(double x, double y) {
        return 4 * y;
    }

    double f2x(double x, double y) {
        return 8*x +2*y;
    }

    double f2y(double x, double y) {
        return 2 * y;
    }


int main() {


    int n = 5;
    double x0 = 0.7325;
    double y0 = -0.8106;

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
       double det = a * d - b * c;
       double xk = x0 - (f2y(x0, y0) * f1(x0, y0) -f1y(x0, y0) * f2(x0, y0)) / det;
       double yk = y0 - (-f2x(x0, y0) * f1(x0, y0) + f1x(x0, y0) * f2(x0, y0)) / det;
       x0 = xk;
       y0 = yk;
       printf("x^(%d) = %.12f\ty^(%d) = %.12f\n", i + 1, x0, i + 1, y0);
    }

}
