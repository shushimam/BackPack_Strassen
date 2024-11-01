#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct {
    int ordem;
    int **matriz;
} Matriz;

// DESCRI��O: Cria uma matriz quadrada de ordem dada.
// ENTRADA: Um inteiro representando a ordem da matriz a ser criada.
// SA�DA: Retorna a matriz rec�m-criada (Matriz).
// PRE-CONDI��O: A ordem deve ser maior que zero.
// POS-CONDICAO: Uma nova matriz � alocada e retornada.
Matriz criarMatriz(int ordem);

// DESCRI��O: Libera a mem�ria alocada para a matriz.
// ENTRADA: Um ponteiro para a matriz a ser liberada (Matriz *).
// SA�DA: Nenhuma.
// PRE-CONDI��O: O ponteiro para a matriz deve ser v�lido.
// POS-CONDICAO: A mem�ria alocada para a matriz � liberada.
void liberarMatriz(Matriz *m);

// DESCRI��O: Preenche a matriz com valores fornecidos pelo usu�rio.
// ENTRADA: Um ponteiro para a matriz a ser preenchida (Matriz *).
// SA�DA: Nenhuma.
// PRE-CONDI��O: O ponteiro para a matriz deve ser v�lido.
// POS-CONDICAO: A matriz � preenchida com valores fornecidos pelo usu�rio.
void completaMatriz(Matriz *m);

// DESCRI��O: Imprime os elementos da matriz.
// ENTRADA: Um ponteiro para a matriz a ser impressa (Matriz *).
// SA�DA: Nenhuma.
// PRE-CONDI��O: O ponteiro para a matriz deve ser v�lido.
// POS-CONDICAO: Os elementos da matriz s�o impressos.
void printMatriz(Matriz *m);

// DESCRI��O: Realiza a multiplica��o de duas matrizes.
// ENTRADA: Duas matrizes a serem multiplicadas (Matriz ma, Matriz mb).
// SA�DA: Retorna a matriz resultante da multiplica��o.
// PRE-CONDI��O: As matrizes ma e mb devem ser compat�veis para multiplica��o.
// POS-CONDICAO: A matriz resultante � retornada.
Matriz multiplicarMatrizes(Matriz ma, Matriz mb);

// DESCRI��O: Retorna uma submatriz da matriz original.
// ENTRADA: Um ponteiro para a matriz original (Matriz *matriz) e �ndices de in�cio e fim para linhas e colunas.
// SA�DA: Retorna a submatriz desejada.
// PRE-CONDI��O: O ponteiro para a matriz deve ser v�lido e os �ndices devem estar dentro dos limites da matriz.
// POS-CONDICAO: A submatriz � retornada.
Matriz subMatriz(Matriz *matriz, int inicioLinhas, int fimLinhas, int inicioColunas, int fimColunas);

// DESCRI��O: Realiza a soma de duas matrizes.
// ENTRADA: Ponteiros para as matrizes a serem somadas (Matriz *a, Matriz *b).
// SA�DA: Retorna a matriz resultante da soma.
// PRE-CONDI��O: Os ponteiros para as matrizes a e b devem ser v�lidos e as matrizes devem ser compat�veis para soma.
// POS-CONDICAO: A matriz resultante da soma � retornada.
Matriz soma(Matriz *a, Matriz *b);

// DESCRI��O: Realiza a subtra��o de duas matrizes.
// ENTRADA: Ponteiros para as matrizes a serem subtra�das (Matriz *a, Matriz *b).
// SA�DA: Retorna a matriz resultante da subtra��o.
// PRE-CONDI��O: Os ponteiros para as matrizes a e b devem ser v�lidos e as matrizes devem ser compat�veis para subtra��o.
// POS-CONDICAO: A matriz resultante da subtra��o � retornada.
Matriz subtracao(Matriz *a, Matriz *b);

// DESCRI��O: Realiza a multiplica��o de duas matrizes utilizando o m�todo padr�o.
// ENTRADA: Ponteiros para as matrizes a serem multiplicadas (Matriz *a, Matriz *b).
// SA�DA: Retorna a matriz resultante da multiplica��o.
// PRE-CONDI��O: Os ponteiros para as matrizes a e b devem ser v�lidos e as matrizes devem ser compat�veis para multiplica��o.
// POS-CONDICAO: A matriz resultante da multiplica��o � retornada.
Matriz multiplicacaoPadrao(Matriz *a, Matriz *b);

// DESCRI��O: Realiza a multiplica��o de duas matrizes utilizando o algoritmo de Strassen.
// ENTRADA: Ponteiros para as matrizes a serem multiplicadas (Matriz *a, Matriz *b).
// SA�DA: Retorna a matriz resultante da multiplica��o.
// PRE-CONDI��O: Os ponteiros para as matrizes a e b devem ser v�lidos e as matrizes devem ser compat�veis para multiplica��o.
// POS-CONDICAO: A matriz resultante da multiplica��o � retornada.
Matriz multiplicaStrassen(Matriz *a, Matriz *b);



#endif
