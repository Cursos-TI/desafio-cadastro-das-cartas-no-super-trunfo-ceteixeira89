#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

int main() {
    // ============================
    // 1. Declaração e inicialização do tabuleiro 10x10
    // ============================
    int tabuleiro[TAM][TAM];
    for (int linha = 0; linha < TAM; linha++) {
        for (int coluna = 0; coluna < TAM; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // ============================
    // 2. Coordenadas iniciais e validação de 4 navios
    // ============================

    // Navio 1: Horizontal — começa em (linha 3, coluna 1)
    int linha_h1 = 3, coluna_h1 = 1;
    if (coluna_h1 + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha_h1][coluna_h1 + i] = NAVIO;
        }
    }

    // Navio 2: Vertical — começa em (linha 5, coluna 6)
    int linha_v1 = 5, coluna_v1 = 6;
    if (linha_v1 + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha_v1 + i][coluna_v1] = NAVIO;
        }
    }

    // Navio 3: Diagonal ↘ — começa em (linha 0, coluna 0)
    int linha_d1 = 0, coluna_d1 = 0;
    if (linha_d1 + TAM_NAVIO <= TAM && coluna_d1 + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_d1 + i][coluna_d1 + i] == AGUA) {
                tabuleiro[linha_d1 + i][coluna_d1 + i] = NAVIO;
            }
        }
    }

    // Navio 4: Diagonal ↙ — começa em (linha 0, coluna 9)
    int linha_d2 = 0, coluna_d2 = 9;
    if (linha_d2 + TAM_NAVIO <= TAM && coluna_d2 - TAM_NAVIO + 1 >= 0) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha_d2 + i][coluna_d2 - i] == AGUA) {
                tabuleiro[linha_d2 + i][coluna_d2 - i] = NAVIO;
            }
        }
    }

    // ============================
    // 3. Impressão do tabuleiro no console
    // ============================
    printf("\nTabuleiro Batalha Naval (0 = Agua, 3 = Navio):\n\n");

    for (int linha = 0; linha < TAM; linha++) {
        for (int coluna = 0; coluna < TAM; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}