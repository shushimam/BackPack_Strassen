#ifndef MOCHILA_H
#define MOCHILA_H

// DESCRIÇÃO: Retorna o máximo entre dois números inteiros.
// ENTRADA: Dois números inteiros a serem comparados (int a, int b).
// SAÍDA: Retorna o maior entre a e b.
// PRE-CONDIÇÃO: Nenhuma.
// POS-CONDICAO: O maior número entre a e b é retornado.
int max(int a, int b);

// DESCRIÇÃO: Resolve o problema da mochila utilizando programação dinâmica.
// ENTRADA: A capacidade máxima da mochila (W), os pesos dos itens (wt), os valores dos itens (val), o número total de itens (n) e um array para armazenar os itens selecionados (mochila).
// SAÍDA: Nenhuma.
// PRE-CONDIÇÃO: Os arrays wt, val e mochila devem ser válidos, e n e W devem ser não negativos.
// POS-CONDICAO: O array mochila é preenchido com valores indicando os itens selecionados para otimizar o valor total na mochila.
void knapsack(int W, int wt[], int val[], int n,int mochila[]);


#endif
