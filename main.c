#include <stdio.h>
#include <stdlib.h>
#include "threesum.h"

//Samuel Oliveira Lopes BV3031926

/* Vari�veis Globais */
int *A;

int main()
{
    int n;
    printf("\n ---Projeto 01 - 3SUM--- \n");

    printf("\n Definir o tamanho do Array: ");
    scanf("%d", &n);

    A = (int*) malloc (n * sizeof(int));
    //int A[8] = {30,-40,-20,-10,40,0,10,5};
    //int A[8] = {-40,-20,-10,0,5,10,30,40};
    //int A[5] = {1, -1,2,-2,0};


    for(int i=0; i<n; i++) {
        printf(" Entre com o %d elemento do Array: ", i+1);
        scanf("%d", &A[i]);
    }

    /*TO DO: Conforme forem implementando, removam os coment�rios */

    ImprimeArray(A, "Array Infor.   []", n);
    treeSumForcaBruta(A, n);
    treeSumMelhorado(A, n);

    ImprimeQtdOperacoes();

    return 0;
}

