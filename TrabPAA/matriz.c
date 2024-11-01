#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

Matriz criarMatriz(int ordem) {
    Matriz novaMatriz;
    novaMatriz.ordem = ordem;
    novaMatriz.matriz = (int **)malloc(ordem * sizeof(int *));
    for (int i = 0; i < ordem; i++) {
        novaMatriz.matriz[i] = (int *)malloc(ordem * sizeof(int));
    }

    return novaMatriz;
}


void liberarMatriz(Matriz *m) {
    for (int i = 0; i < m->ordem; i++) {
        free(m->matriz[i]);
    }
    free(m->matriz);
}


void completaMatriz(Matriz *m) {
    for (int i = 0; i < m->ordem; i++) {
        for (int j = 0; j < m->ordem; j++) {
            m->matriz[i][j] = rand() % 10;
        }
    }
}

void printMatriz(Matriz *m) {
    for (int i = 0; i < m->ordem; i++) {
        for (int j = 0; j < m->ordem; j++) {
            printf("%d ", m->matriz[i][j]);
            if (j == m->ordem - 1) {
                printf("\n");
            }
        }
    }
}
Matriz multiplicacaoPadrao(Matriz *a, Matriz *b) {
    Matriz resultado = criarMatriz(a->ordem);

    for (int i = 0; i < a->ordem; i++) {
        for (int j = 0; j < a->ordem; j++) {
            for (int k = 0; k < a->ordem; k++) {
                resultado.matriz[i][j] += a->matriz[i][k] * b->matriz[k][j];
            }
        }
    }

    return resultado;
}

Matriz subMatriz(Matriz *matriz, int inicioLinhas, int fimLinhas, int inicioColunas, int fimColunas) {
    int novaOrdem = fimLinhas - inicioLinhas;
    Matriz resultado = criarMatriz(novaOrdem);

    for (int i = 0; i < novaOrdem; i++) {
        for (int j = 0; j < novaOrdem; j++) {
            resultado.matriz[i][j] = matriz->matriz[inicioLinhas + i][inicioColunas + j];
        }
    }

    return resultado;
}

Matriz soma(Matriz *a, Matriz *b) {
    Matriz resultado = criarMatriz(a->ordem);

    for (int i = 0; i < a->ordem; i++) {
        for (int j = 0; j < a->ordem; j++) {
            resultado.matriz[i][j] = a->matriz[i][j] + b->matriz[i][j];
        }
    }

    return resultado;
}

Matriz subtracao(Matriz *a, Matriz *b) {
    Matriz resultado = criarMatriz(a->ordem);

    for (int i = 0; i < a->ordem; i++) {
        for (int j = 0; j < a->ordem; j++) {
            resultado.matriz[i][j] = a->matriz[i][j] - b->matriz[i][j];
        }
    }

    return resultado;
}

Matriz juntarSubmatrizes(Matriz *c11, Matriz *c12, Matriz *c21, Matriz *c22) {
    int novaOrdem = c11->ordem * 2;

    // Criar matriz resultante
    Matriz resultado = criarMatriz(novaOrdem);

    // Preencher a matriz resultante com as submatrizes
    for (int i = 0; i < c11->ordem; i++) {
        for (int j = 0; j < c11->ordem; j++) {
            resultado.matriz[i][j] = c11->matriz[i][j];
            resultado.matriz[i][j + c11->ordem] = c12->matriz[i][j];
            resultado.matriz[i + c11->ordem][j] = c21->matriz[i][j];
            resultado.matriz[i + c11->ordem][j + c11->ordem] = c22->matriz[i][j];
        }
    }

    return resultado;
}
Matriz multiplicaStrassen(Matriz *a, Matriz *b) {
    if (a->ordem <= 2) {
        return multiplicacaoPadrao(a, b);
    }

    int novaOrdem = a->ordem / 2;

    // Dividir as matrizes em submatrizes
    Matriz a11 = subMatriz(a, 0, novaOrdem, 0, novaOrdem);
    Matriz a12 = subMatriz(a, 0, novaOrdem, novaOrdem, a->ordem);
    Matriz a21 = subMatriz(a, novaOrdem, a->ordem, 0, novaOrdem);
    Matriz a22 = subMatriz(a, novaOrdem, a->ordem, novaOrdem, a->ordem);

    Matriz b11 = subMatriz(b, 0, novaOrdem, 0, novaOrdem);
    Matriz b12 = subMatriz(b, 0, novaOrdem, novaOrdem, b->ordem);
    Matriz b21 = subMatriz(b, novaOrdem, b->ordem, 0, novaOrdem);
    Matriz b22 = subMatriz(b, novaOrdem, b->ordem, novaOrdem, b->ordem);

 //   printf("chegou aqui\n");
    // Calcular produtos intermediários
    Matriz p1 = soma(&a11, &a22);
    Matriz p2 = soma(&a21, &a22);
    Matriz p3 = a11;
    Matriz p4 = a22;
    Matriz p5 = soma(&a11, &a12);
    Matriz p6 = subtracao(&a21, &a11);
    Matriz p7 = subtracao(&a12, &a22);

Matriz auxp1 = soma(&b11, &b22);
Matriz auxp2 = subtracao(&b12, &b22);
Matriz auxp3 = subtracao(&b21, &b11);
Matriz auxp4 = soma(&b11, &b12);
Matriz auxp5 = soma(&b21, &b22);

p1 = multiplicaStrassen(&p1, &auxp1);
p2 = multiplicaStrassen(&p2, &b11);
p3 = multiplicaStrassen(&p3, &auxp2);
p4 = multiplicaStrassen(&p4, &auxp3);
p5 = multiplicaStrassen(&p5, &b22);
p6 = multiplicaStrassen(&p6, &auxp4);
p7 = multiplicaStrassen(&p7, &auxp5);
//printf("chegou aqui2\n");
// Calcular matrizes resultantes
Matriz c11 = soma(&p1, &p4);
c11 = subtracao(&c11, &p5);
c11 = soma(&c11, &p7);

Matriz c12 = soma(&p3, &p5);
Matriz c21 = soma(&p2, &p4);
Matriz auxc1 = soma(&p1, &p3);
Matriz auxc2 = soma(&auxc1, &p6);
Matriz c22 = subtracao(&auxc2, &p2);


  // Criar matriz resultante
Matriz resultado = criarMatriz(a->ordem);
resultado = juntarSubmatrizes(&c11,&c12,&c21,&c22);

//printf("aqui ja é erro de lógica\n");
    return resultado;
}


