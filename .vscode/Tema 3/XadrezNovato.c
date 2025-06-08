#include <stdio.h>

int main() {
    // ====================
    // Movimentação da Torre
    // ====================
    // Estrutura usada: for
    // Direção: 5 casas para a direita
    int casasTorre = 5;

    printf("Movimento da Torre:\n");

    for (int i = 1; i <= casasTorre; i++) {
        printf("Direita (%d)\n", i);
    }

    // ====================
    // Movimentação do Bispo
    // ====================
    // Estrutura usada: while
    // Direção: 5 casas na diagonal para cima e direita
    int casasBispo = 5;
    int i = 1;

    printf("\nMovimento do Bispo:\n");

    while (i <= casasBispo) {
        printf("Cima Direita (%d)\n", i);
        i++;
    }

    // ====================
    // Movimentação da Rainha
    // ====================
    // Estrutura usada: do-while
    // Direção: 8 casas para a esquerda
    int casasRainha = 8;
    int j = 1;

    printf("\nMovimento da Rainha:\n");

    do {
        printf("Esquerda (%d)\n", j);
        j++;
    } while (j <= casasRainha);

    return 0;
}