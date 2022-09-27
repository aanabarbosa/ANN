#include <stdio.h>
#include <math.h>

#define ROW 4
#define COL 4

void imprimeMatriz(double matriz[ROW][COL]){
    for(int row = 0; row < ROW; row++){
        for(int col = 0; col < COL; col++){
            printf("%.16f, ", matriz[row][col]);
        }
        printf("\n");
    }
}

void trocaLinha(double matriz[ROW][COL], int r1, int r2){
        for(int k=0;k<COL;k++){
        double temp = matriz[r1][k];
        matriz[r1][k] = matriz[r2][k];
        matriz[r2][k] = temp;
    }
}

void operacaoEmLinha(double matriz[ROW][COL], int row, double num){
    for(int i = 0; i < COL; i++){
        matriz[row][i] *= num; 
    }
}

void opercaoEmDuasLinhas(double matriz[ROW][COL], int target, int r2, double num){
    for(int i = 0; i < COL; i++){
        matriz[target][i] = (num*matriz[r2][i]) + matriz[target][i];
    }
}

void operacoes(double matriz[ROW][COL]){
    /*
	L1 0
    L2 1
    L3 2
	L4 3
	quem soma vem primeiro
	

     −1/3⋅L1+L2→L2, 
     1⋅L1+L3→L3, 
     −2⋅L1+L4→L4, 
     3/5⋅L2+L3→L3, 
     −27/10⋅L2+L4→L4  e  11/3⋅L3+L4→L4

    */
	opercaoEmDuasLinhas(matriz, 1,0,(-1.0/3.0));

	opercaoEmDuasLinhas(matriz, 2, 0, (1.0));

	opercaoEmDuasLinhas(matriz, 3, 0, (-2.0));

	opercaoEmDuasLinhas(matriz, 2, 1, (3.0/5.0));

	opercaoEmDuasLinhas(matriz, 3, 1, (-27.0/10.0));

	opercaoEmDuasLinhas(matriz, 3, 2, (11.0/3.0));

    imprimeMatriz(matriz);
}

int main(){
    double matriz[ROW][COL] = {
		{-3, 1, -8, 8},
        {-1, -3, 6, 3},
        {3, 1, 7, -2},
        {-6, -7, -8, 3},
    };

    printf("Matriz Original:\n");
    imprimeMatriz(matriz);
    printf("Resultado:\n");
    operacoes(matriz);
    return 0;
}