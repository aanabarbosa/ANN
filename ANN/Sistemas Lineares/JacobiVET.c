#include<stdio.h>

#define ROWS 4

void jacobi(double A[ROWS][ROWS], double B[ROWS], double chute[ROWS], int n){
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
           if(k+1==n){
            printf("%.16f,",  bi);
           }
            next[i] = bi;
        }
        
        //atualiza o chute
        for(int i=0; i<ROWS;i++){
            chute[i]=next[i];
        }

    }
}

int main(){
    double A[ROWS][ROWS] = {{-7.81,-2.14,-1.03,3.3},{-4.54,-12.6,4.15,2.57},{4.84,2.79,-10.42,1.44},{-4.71,1.93,0.02,-8.02}};
    double B[ROWS] = {2.32, -0.34,-2.66,0.07};

    double chute[ROWS] = {-2.78,-2.85,0.43,2.33};
    //int n =20;

     int vet[12] = {
        2 , 10, 11, 12, 13, 15, 17, 19, 20, 22, 24, 26};

    for (int i = 0; i < 12; i++) {
        int n = vet[i];
    jacobi(A,B,chute,n);
   printf("(%d)\n",vet[i]);
    }
};