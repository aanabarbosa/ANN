#include<stdio.h>

#define numRows 4
#define numCols 5



void print_matrix(double m[numRows][numCols]){
    for(int i=0 ; i < numRows ; i++){
        for(int j =0 ; j<numCols ;j++){
            printf("%.8f\t", m[i][j]);
        }
        printf("\n");
    }
};


//só funciona para sistemas NxN
void gauss(double E[numRows][numCols]){
    for(int j = 0; j < numCols - 1 ;j++){
        for(int i = j; i <numRows ;i++){
            if(E[i][j] != 0){
                if(i != j){
                    //troca linhas i e j
                    for(int k =0 ; k< numCols; k++){
                        double temp = E[i][k];
                        E[i][k] = E[j][k];
                        E[j][k] = temp;
                    }
                }
                //zerar todos os elementos da coluna j
                //abaixo do elemento na posiçao j,j
                for( int k = 0 ;k < numRows ;k++){
                    if(k==j){
                        continue;
                    }
                    double m = -E[k][j]/ E[j][j];
                    for(int p = j; p < numCols ; p++){
                        E[k][p] = m * E[j][p] + E[k][p];
                    }
                }
                printf("\n");
                print_matrix(E);
                break;
            }
        }
    }
    printf("\n");
    for(int i = 0; i< numRows; i++){
        double xi = E[i][numCols - 1]/E[i][i];
        printf("x_%d = %.16f\n",i+ 1, xi);
    }
};

int main(){
    double E[numRows][numCols] = {
        {2, 4, 6, 2, 4},
        {1, 2, -1, 3, 8},
        {-3, 1, -2, 1, -2},
        {1, 3, -3, -2, 6}
    };

    print_matrix(E);
    printf("\nComeca aqui:\n");
    gauss(E);



};