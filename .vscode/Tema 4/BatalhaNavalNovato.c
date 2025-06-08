#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // ============================
    // 1. Declaração do tabuleiro
    // ============================
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = AGUA;
        }
    }

    // =============================
    // 2. Representação dos navios
    // =============================
    int navio_horizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navio_vertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // =============================
    // 3. Coordenadas iniciais (fixas no código)
    // =============================
    int linha_h = 2;   // linha do navio horizontal
    int coluna_h = 1;  // coluna inicial

    int linha_v = 5;   // linha inicial do navio vertical
    int coluna_v = 6;  // coluna do navio vertical

    // =============================
    // 4. Validação de limites
    // =============================
    if (coluna_h + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linha_v + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // =============================
        // 5. Validação de sobreposição (simplificada)
        // =============================
        int sobreposicao = 0;

        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_h][coluna_h + i] != AGUA ||
                tabuleiro[linha_v + i][coluna_v] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        // =============================
        // 6. Posiciona os navios no tabuleiro
        // =============================
        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i]; // horizontal
                tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];   // vertical
            }
        } else {
            printf("Erro: sobreposicao de navios detectada!\n");
            return 1;
        }

    } else {
        printf("Erro: coordenadas invalidas! Navio fora dos limites do tabuleiro.\n");
        return 1;
    }

    // =============================
    // 7. Impressão do tabuleiro
    // =============================
    printf("\nTabuleiro Batalha Naval (0 = Agua, 3 = Navio):\n\n");

    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}