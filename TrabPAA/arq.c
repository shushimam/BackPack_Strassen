#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "mochila.h"
#include "arq.h"

void menu(){
    int ordem;
    int estado;
    FILE * txt;
    char str[100];
    printf("1-Multiplicacao de matriz comum\n2-Mutiplicacao de matriz por Strassen\n3-Problema da mochila\n");
    scanf("%d%*c",&estado);

switch(estado){
case 1:
    printf("Digite o nome do arquivo: ");
    scanf("%[^\n]%*c", str);
    txt = fopen(str,"r");
    if(txt==NULL){
        printf("Arquivo invalido, voltando ao menu principal\n");
    }
    else{
        mult_comum(txt);
    }
    break;
case 2:
    printf("Digite o nome do arquivo: ");
    scanf("%[^\n]%*c", str);
    txt = fopen(str,"r");
    if(txt==NULL){
        printf("Arquivo invalido, voltando ao menu principal\n");
    }
    else{
        mult_strassen(txt);
    }
        break;
case 3:
    printf("Digite o nome do arquivo: ");
    scanf("%[^\n]%*c", str);
    txt = fopen(str,"r");
    if(txt==NULL){
        printf("Arquivo invalido, voltando ao menu principal\n");
    }
    else{
        knap(txt);
    }
    break;
case 4:
    scanf("%d",&ordem);
    Matriz A = criarMatriz(ordem);
    Matriz B = criarMatriz(ordem);
    completaMatriz(&A);
    completaMatriz(&B);
    Matriz resultado = criarMatriz(ordem);

    resultado = multiplicaStrassen(&A,&B);

    // Liberar mem�ria alocada para as matrizes A e B
    for (int i = 0; i < ordem; i++) {
        free(A.matriz[i]);
        free(B.matriz[i]);
    }
    free(A.matriz);
    free(B.matriz);

    printf("a matriz resultado �:\n");
    printMatriz(&resultado);

}
}

void mult_comum(FILE *arquivo) {
    int ordem;
    fscanf(arquivo, "%d%*c", &ordem);

    Matriz A = criarMatriz(ordem);
    Matriz B = criarMatriz(ordem);

    // Preencher a matriz A
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            fscanf(arquivo, "%d%*c", &A.matriz[i][j]);
        }
    }

    // Preencher a matriz B
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            fscanf(arquivo, "%d,", &B.matriz[i][j]);
        }
    }

    // Multiplicar as matrizes
    Matriz resultado = criarMatriz(ordem);

    resultado = multiplicacaoPadrao(&A,&B);

    // Liberar mem�ria alocada para as matrizes A e B
    for (int i = 0; i < ordem; i++) {
        free(A.matriz[i]);
        free(B.matriz[i]);
    }
    free(A.matriz);
    free(B.matriz);

    printf("a matriz resultado �:\n");
    printMatriz(&resultado);

}

void mult_strassen(FILE *arquivo) {
    int ordem;
    fscanf(arquivo, "%d%*c", &ordem);

    Matriz A = criarMatriz(ordem);
    Matriz B = criarMatriz(ordem);

    // Preencher a matriz A
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            fscanf(arquivo, "%d%*C", &A.matriz[i][j]);
        }
    }

    // Preencher a matriz B
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            fscanf(arquivo, "%d%*C", &B.matriz[i][j])
            ;
        }
    }

    // Multiplicar as matrizes
    Matriz resultado = criarMatriz(ordem);

    resultado = multiplicaStrassen(&A,&B);

    // Liberar mem�ria alocada para as matrizes A e B
    for (int i = 0; i < ordem; i++) {
        free(A.matriz[i]);
        free(B.matriz[i]);
    }
    free(A.matriz);
    free(B.matriz);

    printf("a matriz resultado �:\n");
    printMatriz(&resultado);
}

void knap(FILE *txt) {
    int W, n;

    // L� o peso total da mochila
    fscanf(txt, "%d%*c", &W);

    // L� a quantidade de objetos (tamanho dos arrays val e wt)
    fscanf(txt, "%d%*c", &n);

    // L� os valores dos objetos
    int val[n];
    for (int i = 0; i < n; i++) {
        fscanf(txt, "%d%*c", &val[i]);
    }

    // L� os pesos dos objetos
    int wt[n];
    for (int i = 0; i < n; i++) {
        fscanf(txt, "%d,", &wt[i]);
    }

    // Vetor para armazenar se cada item foi inclu�do na mochila
    int mochila[n];
    for(int i =0; i<n;i++){
        mochila[i]=0;
    }
    // Chama a fun��o auxiliar para resolver o problema da mochila
     knapsack(W, wt, val, n, mochila);

    // Imprime os itens inclu�dos na mochila
    printf("Itens inclu�dos na mochila: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", mochila[i]);
    }

    // Imprime o resultado do problema da mochila
    //printf("\nResultado: %d\n", resultado);
}
