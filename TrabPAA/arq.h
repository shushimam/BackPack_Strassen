#ifndef ARQ_H
#define ARQ_H

// DESCRI��O: Prepara e chama a fun��o para resolver a multiplica��o de duas matrizes com o m�todo convencional.
// ENTRADA: Um ponteiro para o arquivo contendo informa��es sobre as matrizes a serem multiplicadas (FILE* arquivo).
// SA�DA: Nenhuma.
// PRE-CONDI��O: O ponteiro para o arquivo deve ser v�lido e o formato do arquivo deve estar de acordo com a especifica��o.
// POS-CONDICAO: A multiplica��o das matrizes � realizada e o resultado � impresso ou armazenado conforme necess�rio.
void mult_comum(FILE* arquivo);

// DESCRI��O: Prepara e chama a fun��o para resolver a multiplica��o de duas matrizes com o algoritmo de Strassen.
// ENTRADA: Um ponteiro para o arquivo contendo informa��es sobre as matrizes a serem multiplicadas (FILE* arquivo).
// SA�DA: Nenhuma.
// PRE-CONDI��O: O ponteiro para o arquivo deve ser v�lido e o formato do arquivo deve estar de acordo com a especifica��o.
// POS-CONDICAO: A multiplica��o das matrizes � realizada utilizando o algoritmo de Strassen, e o resultado � impresso ou armazenado conforme necess�rio.
void mult_strassen(FILE*arquivo);

// DESCRI��O: Prepara e chama a fun��o para resolver o problema da mochila utilizando programa��o din�mica a partir de informa��es em um arquivo de texto.
// ENTRADA: Um ponteiro para o arquivo de texto contendo informa��es sobre o problema da mochila (FILE* txt).
// SA�DA: Nenhuma.
// PRE-CONDI��O: O ponteiro para o arquivo de texto deve ser v�lido e o formato do arquivo deve estar de acordo com a especifica��o.
// POS-CONDICAO: O problema da mochila � resolvido e a solu��o � impressa ou armazenada conforme necess�rio.
void knap(FILE* txt);

// DESCRI��O: Exibe um menu de op��es para o usu�rio.
// ENTRADA: Nenhuma.
// SA�DA: Nenhuma.
// PRE-CONDI��O: Nenhuma.
// POS-CONDICAO: O menu � exibido para o usu�rio.
void menu();

#endif
