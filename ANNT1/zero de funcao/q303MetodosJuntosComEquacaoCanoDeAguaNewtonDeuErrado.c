//Nao coloquei os valores da questão.


//bissecao


#include <stdio.h>
#include <math.h>

void bissection(double (*f)(double), double a, double b, double n, double tol);
double f(double x);




void bissection(double (*f)(double), double a, double b, double n, double tol) { //
    double fa = f(a);  // aqui inicia bolzano
    double fb = f(b);

    if (fa * fb >= 0) {  //verificaçao dp teorema em si
        printf("A existencia de raiz no inertvalo [%.16lf,%.16lf] eh inconclusiva.\n", a, b);
        return;

        
// aqui encerra bolzano
    } else {
        for(int i=0;i<n;i++){
            double m= 0.5 * (a + b); // CALCULO DO PONTO MEDIO DO INTERVALO
            double fm = f(m);
            if(fm == 0){  // VERIFICA SE ESSE PONTO MEDIO JÁ NAO É UMA RAIZ
                printf("%.16lf eh uma raiz\n", m);
                return;
            }



            printf("m_%d = %.16f\n",i+1, m);

            // if(fabs(fm)<tol){
            //     printf("atingiu a tolerancia de m => m_%d = %.16f\n",i+1,m);
            //     return;}

            //  printf("fb-fa = %f\n"),fabs((fb-fa));
            //     printf("tol =%f\n"),tol;
            if(fabs((fb-fa))<tol ){
                printf("%16.f\n"),fabs((fb-fa));
                printf("%16.f\n"),tol;
                printf("atingiu a tolerancia de intervalo => m_%d = %.16f.\n",i+1,m);
                return;
            }



            if(fa * fm <= 0){  // Verifica se f(m) está do lado aposto de fa em realcao ao eixo x.
                b = m ;       // entao pelo teorema de bolzano a raiz esta no intervalo [a,m]. atualiza-se m como o novo b.
                fb = fm;
            }else{   // se fa e fm estao do mesmo lado do eixo x então a raiz esta para a outra metade do intervalo
                a = m;  
                fa = fm;
            }
        }
    }
}
double f(double x){
        return ((9.81*76.64)/x)*(1-exp(-(x/76.64)*7.84))-20.31 ;
                  // aqui vai a funçao na qual se busca encontrar as raizes
    };


    




// newton


double df(double x);

void newton(double (*f)(double), double (*df)(double),double x0, int n){
    for(int i =0; i<n;i++){
        double dfx0 = df(x0);
        if(dfx0==0){
            break;
        }
       double xi = x0 - f(x0)/df(x0);
       printf("x_%d = %.16f\n", i+1, xi);
       x0 = xi; //atualizaçao para proxima iteraçao
    }
}

    double df(double x){
        return -(exp((49*x)/479)*(469899*exp((49*x)/479)-48069*x-469899))/625*x*x; //calular a derivada em algum outro software, VAI NO WOLFAMALPHA, ESCREVE DERIVATIVE NA FRENTE DA FUNÇAO, CLICA EM CALCULAR, DEPOIS POROCURA A ABA "ALTERNATE FORMS", CLICA EM PLAIN TEXT, CLICA EM CIMA DA FUNÇAO QUE ESTA NO CAMPO "COPYABLE PLAIN TEXT"
    };
//-2651000 + 1270776 * exp(x) + (209614/x) * (exp(x) - 1)
//1569887*exp(x)+(280246/x)*(exp(x)-1)-3581685

//secante



void secante(double (*f)(double), double x0, double x1, int n){
    for(int i =0 ; i< n ; i++){
        double fx0 = f(x0);
        double fx1 = f(x1);
        if(fx0 == fx1){  // verifia se nao vai dar divisao por 0
            break;
        }
       double x2 = ((x0*fx1 - x1*fx0) / (fx1 - fx0)); 
       printf("x_%d = %.16f\n", i+2,x2);
       x0 = x1;
       x1 = x2;
    }
};



//Pos falsa



void PosFalsa(double (*f)(double), double a, double b, int n) {
    for (int i = 0; i < n; i++) {
        double fa = f(a);
        double fb = f(b);
        if (fa * fb >=
            0) {  // verifia se  cada ponto esta do aldo oposto do eixo x
            printf(
                "O teorema de Bolzano n sabe dizer se existe raiz para f nesse "
                "intervalo.\n");
            break;
        }
        double x1 = ((a * fb - b * fa) / (fb - fa));  // expressao
                                                      // caracteristica
        printf("x_%d = %.16f\n", i + 1, x1);

        // testes para saber qual lado continuar, bissecao
        double fx1 = f(x1);
        if (fa * fx1 < 0) {
            b = x1;
            fb = fx1;
        } else {
            a = x1;
            fa = fx1;
        }
    }
};

int main() {
    //bissecao
    printf("\n/////////////////////////////bissecao/////////////////////////////\n");
    double a =  0.42;  // intervalo dado ou chutado para fazer o teorema de bolzano               
    double b =   52.44;// e descobrir se aqui tem ou nao uma raiz
    int n = 12;  // ordem de parada por interaçoes. nesse caso 10 iteraçoes
    double tol =  0.0000000000000000001; //ordem de prada pela tolerancia
    bissection(f, a, b, n, tol);



    //newton
    printf("\n/////////////////////////////newton/////////////////////////////\n");
    double x0 = 0.95  ; // chute inicial
    int m = 5; //limitaçao do numero de interaçoes

    newton(f, df, x0, m);// passa a funçao, passa o chute inicila, e o numero maximo de interaçoes


    //posfalsa
    printf("\n/////////////////////////////posicao falsa/////////////////////////////\n");
    double comeco_intervalo = 0.88;  // primeiro ponto chutado
    double final_intervalo = 58.5;  // segundo ponto chutado
    int iteracoes = 11;    // numero de iteraçoes

    PosFalsa(f, comeco_intervalo, final_intervalo, iteracoes);
}