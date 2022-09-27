#include <stdio.h>
#include <math.h>
#define L 4
#define C 4

void jacobi(double A[L][C], double B[L], double chute[L], int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<L;i++){
            double bi=B[i];
            for(int j=0;j<C;j++){
                if(j!=i) bi-=A[i][j]*chute[j];
            }
            bi/=A[i][i];
            printf("x_%d(%d) = %.16f | ", i+1, k+1, bi);
            chute[i]=bi;
        }
        printf("\n");
    }
}


// INSERIR O TAMANHO DA MATRIZ EM DEFINE
//***************************************************************************

int main(){
    double A[L][C]={{7.52, -3.36, 2.43, 0.37}, {-0.7, 9.29, 2.44, 4.79}, {2.1, 4.72, -10.15, -1.98}, {-0.19, -3.12, -1.14, 5.81}};
    double B[L]={-3.37, 0.06, 2.88, -0.26}; // result

    double chute[L]= {0.09, -1.62, -3.37, -4.85}; //x0
    int n=25;

    jacobi(A, B, chute, n);

    return 0;
}