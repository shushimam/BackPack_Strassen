#ifndef MOCHILA_H
#define MOCHILA_H

// DESCRI��O: Retorna o m�ximo entre dois n�meros inteiros.
// ENTRADA: Dois n�meros inteiros a serem comparados (int a, int b).
// SA�DA: Retorna o maior entre a e b.
// PRE-CONDI��O: Nenhuma.
// POS-CONDICAO: O maior n�mero entre a e b � retornado.
int max(int a, int b);

// DESCRI��O: Resolve o problema da mochila utilizando programa��o din�mica.
// ENTRADA: A capacidade m�xima da mochila (W), os pesos dos itens (wt), os valores dos itens (val), o n�mero total de itens (n) e um array para armazenar os itens selecionados (mochila).
// SA�DA: Nenhuma.
// PRE-CONDI��O: Os arrays wt, val e mochila devem ser v�lidos, e n e W devem ser n�o negativos.
// POS-CONDICAO: O array mochila � preenchido com valores indicando os itens selecionados para otimizar o valor total na mochila.
void knapsack(int W, int wt[], int val[], int n,int mochila[]);


#endif
