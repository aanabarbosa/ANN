#include<stdio.h>

#define ROWS 3

void jacobi(double A[ROWS][ROWS], double B[ROWS], double chute[ROWS], int n ){
   double next[ROWS];
    for (int k =0; k < n; k++){
        for(int i =0; i<ROWS; i++){
            double bi = B[i];
            for(int j=0; j<ROWS; j++){
                if(j != i){
                    bi -= A[i][j] * chute[j];
                }
            }
            bi /= A[i][i];
            printf("x_%d^(%d) = %.16f\t", i+1, k+1, bi);
            next[i] = bi;
        }
        printf("\n");
        //atualiza o chute
        for(int i=0; i<ROWS;i++){
            chute[i]=next[i];
        }

    }
}

int main(){
    double A[ROWS][ROWS] = {{7.63, 4.39, -1.94},{-2.15, 7.74, 4.29},{1.58, -0.07, -2.96}};
    double B[ROWS] = {-1.77, -1.44, -4.43};

    double chute[ROWS] = {2.41,4.02,1.95};
    int n =20;

    jacobi(A,B,chute,n);
    
};