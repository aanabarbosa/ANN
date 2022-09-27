#include <stdio.h>

#define L 4
#define C 4


//so funciona para sistemas nxn
void jacobi(double A[L][C], double B[L], double chute[L], int n){
    double next[L];
    for(int k=0;k<n;k++){
        for(int i=0;i<L;i++){
            double bi=B[i];
            for(int j=0;j<C;j++){
                if(j!=i) bi-=A[i][j]*chute[j];
            }
            bi/=A[i][i];
            printf("x_%d(%d) = %.16f | ", i+1, k+1, bi);
            next[i]=bi;
        }
        printf("\n");
        //atualizar o chute
        for(int i=0;i<L;i++) chute[i]=next[i];
    }
}

int main(){
    double A[L][C]={{-13.25, 4.35, 4.22, 3.21},{-3.92, -9.8, 4.05, 0.35},{3.55, -4.39, 12.13, -2.72},{3.47, -1.19, -0.71, 6.84}};
    double B[L]={4.39, -4.67, -2.05, 2.41}; // result

    double chute[L]={4.21,1.24,0.76,-4.93}; // x0
    int n=26;

    jacobi(A, B, chute, n);

    return 0;
}