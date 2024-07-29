#include <stdio.h>
#include <stdlib.h>
#include "threesum.h"

int qtdOperacoes3SumFB=0;
int qtdOperacoes3SumMelhorado=0;


/* treeSumForcaBruta(): */
void treeSumForcaBruta(int A[], int n) {
    printf("\n\n--- 3SUM - Forca Bruta:---\n");

    int triplasEncontradas = 0;
    int j;
    for(int i=0; i<n; i++){
        int primeiro = A[i];
        int j = i+1;
        int segundo;
        while(j < n){
            segundo = A[j];
            int soma = primeiro + segundo;
            for(int k=j+1;k<n;k++){
                if(A[k] == -soma){
                    printf("\n%d Tripla Encontrada: [%d, %d, %d]", ++triplasEncontradas, primeiro, segundo, -soma);
                    qtdOperacoes3SumFB++;
                    break;
                    }
                qtdOperacoes3SumFB++;
            }
            j++;
            qtdOperacoes3SumFB++;
        }
    qtdOperacoes3SumFB++;
    }
    printf("\n Total de Triplas Encontradas pela Forca Bruta: %d", triplasEncontradas);
}

/* treeSumMelhorado(): */
void treeSumMelhorado(int A[], int n) 
{
    printf("\n\n--- 3SUM - Melhorado:---\n");
    MergeSortRecursivo( A, 0, n-1, n);
    ImprimeArray(A, "Array Ord.     []", n);


    int triplasEncontradas = 0;
    
    for(int i=0; i<n-1; i++){
        int j = n-1;
        while(j > i){
            qtdOperacoes3SumMelhorado++;
            int soma = A[i] + A[j];
            int verifica = BuscaBinaria(-soma, A, i+1, j-1);
            

            if(verifica != -1){
                qtdOperacoes3SumMelhorado++;
                //printf("\n Busca binaria retorna: %d", verifica);
                printf("\n%d Tripla Encontrada: [%d, %d, %d]", ++triplasEncontradas, A[i], -soma, A[j]);
                } 
            j--;
        }
    }
}

/* BuscaBinaria(): */
int BuscaBinaria (int x, int A[], int inicio, int fim)
{
    int meio;
    if(inicio <= fim){
        meio = (inicio+fim)/2;
        if(A[meio] == x){
            return meio;
        } else {
            if(x < A[meio]){
                BuscaBinaria(x, A, inicio, meio-1);
            } else {
                BuscaBinaria(x, A, meio+1, fim);
            }
        }
    } else {
        return -1;
    }
}

/* MergeSortRecursivo(): */
void MergeSortRecursivo(int A[], int inicio, int fim, int n)
{

if(inicio < fim){
    int meio = (inicio + fim)/2;

    MergeSortRecursivo(A, inicio, meio, n);
    MergeSortRecursivo(A, meio+1, fim, n);
    IntercalaSemSentinela(A, inicio, meio, fim, n);
    }
}

/* IntercalaSemSentinela(): */
void IntercalaSemSentinela(int A[], int inicio, int meio, int fim, int n) {


    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;


    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = A[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = A[meio + 1 + j];


    i = 0; 
    j = 0; 
    k = inicio; 
    while (i < n1 && j < n2) {
        qtdOperacoes3SumMelhorado++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }

}

/* ImprimeArray(): */
void ImprimeArray(int A[], char Msg[], int n)
{
    printf("\n%s = ", Msg);
for(int i = 0; i < n; i++){
    printf(" %d", A[i]);
}

}

/* ImprimeQtdOperacoes():  */
void ImprimeQtdOperacoes(){
    printf("\nQuantidade de operacoes - 3SUM - Forca Bruta: %d", qtdOperacoes3SumFB);
    printf("\nQuantidade de operacoes - 3SUM - Melhorado: %d", qtdOperacoes3SumMelhorado);
}
