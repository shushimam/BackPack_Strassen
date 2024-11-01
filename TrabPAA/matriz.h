#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct {
    int ordem;
    int **matriz;
} Matriz;

// DESCRIÇÃO: Cria uma matriz quadrada de ordem dada.
// ENTRADA: Um inteiro representando a ordem da matriz a ser criada.
// SAÍDA: Retorna a matriz recém-criada (Matriz).
// PRE-CONDIÇÃO: A ordem deve ser maior que zero.
// POS-CONDICAO: Uma nova matriz é alocada e retornada.
Matriz criarMatriz(int ordem);

// DESCRIÇÃO: Libera a memória alocada para a matriz.
// ENTRADA: Um ponteiro para a matriz a ser liberada (Matriz *).
// SAÍDA: Nenhuma.
// PRE-CONDIÇÃO: O ponteiro para a matriz deve ser válido.
// POS-CONDICAO: A memória alocada para a matriz é liberada.
void liberarMatriz(Matriz *m);

// DESCRIÇÃO: Preenche a matriz com valores fornecidos pelo usuário.
// ENTRADA: Um ponteiro para a matriz a ser preenchida (Matriz *).
// SAÍDA: Nenhuma.
// PRE-CONDIÇÃO: O ponteiro para a matriz deve ser válido.
// POS-CONDICAO: A matriz é preenchida com valores fornecidos pelo usuário.
void completaMatriz(Matriz *m);

// DESCRIÇÃO: Imprime os elementos da matriz.
// ENTRADA: Um ponteiro para a matriz a ser impressa (Matriz *).
// SAÍDA: Nenhuma.
// PRE-CONDIÇÃO: O ponteiro para a matriz deve ser válido.
// POS-CONDICAO: Os elementos da matriz são impressos.
void printMatriz(Matriz *m);

// DESCRIÇÃO: Realiza a multiplicação de duas matrizes.
// ENTRADA: Duas matrizes a serem multiplicadas (Matriz ma, Matriz mb).
// SAÍDA: Retorna a matriz resultante da multiplicação.
// PRE-CONDIÇÃO: As matrizes ma e mb devem ser compatíveis para multiplicação.
// POS-CONDICAO: A matriz resultante é retornada.
Matriz multiplicarMatrizes(Matriz ma, Matriz mb);

// DESCRIÇÃO: Retorna uma submatriz da matriz original.
// ENTRADA: Um ponteiro para a matriz original (Matriz *matriz) e índices de início e fim para linhas e colunas.
// SAÍDA: Retorna a submatriz desejada.
// PRE-CONDIÇÃO: O ponteiro para a matriz deve ser válido e os índices devem estar dentro dos limites da matriz.
// POS-CONDICAO: A submatriz é retornada.
Matriz subMatriz(Matriz *matriz, int inicioLinhas, int fimLinhas, int inicioColunas, int fimColunas);

// DESCRIÇÃO: Realiza a soma de duas matrizes.
// ENTRADA: Ponteiros para as matrizes a serem somadas (Matriz *a, Matriz *b).
// SAÍDA: Retorna a matriz resultante da soma.
// PRE-CONDIÇÃO: Os ponteiros para as matrizes a e b devem ser válidos e as matrizes devem ser compatíveis para soma.
// POS-CONDICAO: A matriz resultante da soma é retornada.
Matriz soma(Matriz *a, Matriz *b);

// DESCRIÇÃO: Realiza a subtração de duas matrizes.
// ENTRADA: Ponteiros para as matrizes a serem subtraídas (Matriz *a, Matriz *b).
// SAÍDA: Retorna a matriz resultante da subtração.
// PRE-CONDIÇÃO: Os ponteiros para as matrizes a e b devem ser válidos e as matrizes devem ser compatíveis para subtração.
// POS-CONDICAO: A matriz resultante da subtração é retornada.
Matriz subtracao(Matriz *a, Matriz *b);

// DESCRIÇÃO: Realiza a multiplicação de duas matrizes utilizando o método padrão.
// ENTRADA: Ponteiros para as matrizes a serem multiplicadas (Matriz *a, Matriz *b).
// SAÍDA: Retorna a matriz resultante da multiplicação.
// PRE-CONDIÇÃO: Os ponteiros para as matrizes a e b devem ser válidos e as matrizes devem ser compatíveis para multiplicação.
// POS-CONDICAO: A matriz resultante da multiplicação é retornada.
Matriz multiplicacaoPadrao(Matriz *a, Matriz *b);

// DESCRIÇÃO: Realiza a multiplicação de duas matrizes utilizando o algoritmo de Strassen.
// ENTRADA: Ponteiros para as matrizes a serem multiplicadas (Matriz *a, Matriz *b).
// SAÍDA: Retorna a matriz resultante da multiplicação.
// PRE-CONDIÇÃO: Os ponteiros para as matrizes a e b devem ser válidos e as matrizes devem ser compatíveis para multiplicação.
// POS-CONDICAO: A matriz resultante da multiplicação é retornada.
Matriz multiplicaStrassen(Matriz *a, Matriz *b);



#endif
