#include <stdio.h>
#include <stdlib.h>
#include "mochila.h"
// Função para encontrar o máximo entre dois inteiros
int max(int a, int b) {
    if (a > b) {
    return a;
} else {
    return b;
}
}

// Função que implementa o Problema da Mochila Binária
void knapsack(int W, int wt[], int val[], int n, int mochila[]) {
    int i, w;
    int** K = (int**)malloc((n + 1) * sizeof(int*));
    for (i = 0; i <= n; i++) {
        K[i] = (int*)malloc((W + 1) * sizeof(int));
    }

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else
                K[i][w] = K[i - 1][w];
        }
    }

    int j = W;
    for (i = n; i > 0 && j > 0; i--) {
        if (K[i][j] != K[i - 1][j]) {
            mochila[i - 1] = 1;
            j = j - wt[i - 1];
        }
    }

    for (i = 0; i <= n; i++) {
        free(K[i]);
    }
    free(K);

}
