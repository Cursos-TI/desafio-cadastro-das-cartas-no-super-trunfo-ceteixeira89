#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

int main() {
    // ============================
    // 1. Inicialização do tabuleiro base com água (0) e navios (3)
    // ============================
    int tabuleiro_num[TAM][TAM];
    for (int linha = 0; linha < TAM; linha++) {
        for (int coluna = 0; coluna < TAM; coluna++) {
            tabuleiro_num[linha][coluna] = AGUA;
        }
    }

    // Navio 1: Horizontal — (linha 3, coluna 1)
    int linha_h1 = 3, coluna_h1 = 1;
    if (coluna_h1 + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro_num[linha_h1][coluna_h1 + i] = NAVIO;
        }
    }

    // Navio 2: Vertical — (linha 5, coluna 6)
    int linha_v1 = 5, coluna_v1 = 6;
    if (linha_v1 + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro_num[linha_v1 + i][coluna_v1] = NAVIO;
        }
    }

    // Navio 3: Diagonal ↘ — (linha 0, coluna 0)
    int linha_d1 = 0, coluna_d1 = 0;
    if (linha_d1 + TAM_NAVIO <= TAM && coluna_d1 + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro_num[linha_d1 + i][coluna_d1 + i] == AGUA) {
                tabuleiro_num[linha_d1 + i][coluna_d1 + i] = NAVIO;
            }
        }
    }

    // Navio 4: Diagonal ↙ — (linha 0, coluna 9)
    int linha_d2 = 0, coluna_d2 = 9;
    if (linha_d2 + TAM_NAVIO <= TAM && coluna_d2 - TAM_NAVIO + 1 >= 0) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro_num[linha_d2 + i][coluna_d2 - i] == AGUA) {
                tabuleiro_num[linha_d2 + i][coluna_d2 - i] = NAVIO;
            }
        }
    }

    // ============================
    // 2. Matriz de exibição com char (0, 3, C, Z, T)
    // ============================
    char tabuleiro_exib[TAM][TAM];
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro_num[i][j] == AGUA)
                tabuleiro_exib[i][j] = '0';
            else if (tabuleiro_num[i][j] == NAVIO)
                tabuleiro_exib[i][j] = '3';
        }
    }

    // ============================
    // 3. Habilidades Especiais (Cone, Cruz, Octaedro)
    // ============================

    // Cone: Posição inicial (linha 6, coluna 1)
    int base_l = 6, base_c = 1;
    char cone[3][5] = {
        {'0', '0', 'C', '0', '0'},
        {'0', 'C', 'C', 'C', '0'},
        {'C', 'C', 'C', 'C', 'C'}
    };
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            if (cone[i][j] != '0')
                tabuleiro_exib[base_l + i][base_c + j] = cone[i][j];

    // Cruz: Posição inicial (linha 1, coluna 4)
    base_l = 1;
    base_c = 4;
    char cruz[3][5] = {
        {'0', '0', 'Z', '0', '0'},
        {'Z', 'Z', 'Z', 'Z', 'Z'},
        {'0', '0', 'Z', '0', '0'}
    };
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            if (cruz[i][j] != '0')
                tabuleiro_exib[base_l + i][base_c + j] = cruz[i][j];

    // Octaedro: Posição inicial (linha 5, coluna 2)
    base_l = 5;
    base_c = 5;
    char octaedro[3][5] = {
        {'0', '0', 'T', '0', '0'},
        {'0', 'T', 'T', 'T', '0'},
        {'0', '0', 'T', '0', '0'}
    };
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 5; j++)
            if (octaedro[i][j] != '0')
                tabuleiro_exib[base_l + i][base_c + j] = octaedro[i][j];

    // ============================
    // 4. Impressão do tabuleiro final com legenda
    // ============================
    printf("\nTabuleiro Batalha Naval com Habilidades:\n");
    printf("Legenda: 0 = Agua, 3 = Navio, C = Cone, Z = Cruz, T = Octaedro\n\n");

    for (int linha = 0; linha < TAM; linha++) {
        for (int coluna = 0; coluna < TAM; coluna++) {
            printf("%c ", tabuleiro_exib[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}