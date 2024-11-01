#ifndef ARQ_H
#define ARQ_H

// DESCRIÇÃO: Prepara e chama a função para resolver a multiplicação de duas matrizes com o método convencional.
// ENTRADA: Um ponteiro para o arquivo contendo informações sobre as matrizes a serem multiplicadas (FILE* arquivo).
// SAÍDA: Nenhuma.
// PRE-CONDIÇÃO: O ponteiro para o arquivo deve ser válido e o formato do arquivo deve estar de acordo com a especificação.
// POS-CONDICAO: A multiplicação das matrizes é realizada e o resultado é impresso ou armazenado conforme necessário.
void mult_comum(FILE* arquivo);

// DESCRIÇÃO: Prepara e chama a função para resolver a multiplicação de duas matrizes com o algoritmo de Strassen.
// ENTRADA: Um ponteiro para o arquivo contendo informações sobre as matrizes a serem multiplicadas (FILE* arquivo).
// SAÍDA: Nenhuma.
// PRE-CONDIÇÃO: O ponteiro para o arquivo deve ser válido e o formato do arquivo deve estar de acordo com a especificação.
// POS-CONDICAO: A multiplicação das matrizes é realizada utilizando o algoritmo de Strassen, e o resultado é impresso ou armazenado conforme necessário.
void mult_strassen(FILE*arquivo);

// DESCRIÇÃO: Prepara e chama a função para resolver o problema da mochila utilizando programação dinâmica a partir de informações em um arquivo de texto.
// ENTRADA: Um ponteiro para o arquivo de texto contendo informações sobre o problema da mochila (FILE* txt).
// SAÍDA: Nenhuma.
// PRE-CONDIÇÃO: O ponteiro para o arquivo de texto deve ser válido e o formato do arquivo deve estar de acordo com a especificação.
// POS-CONDICAO: O problema da mochila é resolvido e a solução é impressa ou armazenada conforme necessário.
void knap(FILE* txt);

// DESCRIÇÃO: Exibe um menu de opções para o usuário.
// ENTRADA: Nenhuma.
// SAÍDA: Nenhuma.
// PRE-CONDIÇÃO: Nenhuma.
// POS-CONDICAO: O menu é exibido para o usuário.
void menu();

#endif
