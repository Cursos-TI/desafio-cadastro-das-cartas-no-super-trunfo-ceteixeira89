#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HABIL 7
#define ORIGEM 3  // Centro da matriz 7x7
#define NAVIO 3
#define AGUA 0
#define HABIL 5

// Inicializa o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;
}

// Posiciona navios fixos
void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Horizontal
    for (int i = 0; i < 3; i++)
        tabuleiro[2][1 + i] = NAVIO;

    // Vertical
    for (int i = 0; i < 3; i++)
        tabuleiro[5 + i][6] = NAVIO;

    // Diagonal ↘
    for (int i = 0; i < 3; i++)
        tabuleiro[i][i] = NAVIO;

    // Diagonal ↙
    for (int i = 0; i < 3; i++)
        tabuleiro[i][9 - i] = NAVIO;
}

// Gera matriz Cone (apontando para baixo)
void gerarMatrizCone(int cone[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            if (i >= ORIGEM && j >= ORIGEM - (i - ORIGEM) && j <= ORIGEM + (i - ORIGEM))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Gera matriz Cruz
void gerarMatrizCruz(int cruz[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            cruz[i][j] = (i == ORIGEM || j == ORIGEM) ? 1 : 0;
        }
    }
}

// Gera matriz Octaedro (losango)
void gerarMatrizOctaedro(int octaedro[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            octaedro[i][j] = (abs(i - ORIGEM) + abs(j - ORIGEM) <= 3) ? 1 : 0;
        }
    }
}

// Aplica a matriz da habilidade ao tabuleiro no ponto de origem
void aplicarHabilidade(int tabuleiro[TAM][TAM], int matriz[TAM_HABIL][TAM_HABIL], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            if (matriz[i][j] == 1) {
                int l = origemLinha + (i - ORIGEM);
                int c = origemColuna + (j - ORIGEM);
                if (l >= 0 && l < TAM && c >= 0 && c < TAM && tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABIL;
                }
            }
        }
    }
}

// Exibe o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nLegenda: 0 = Agua | 3 = Navio | 5 = Habilidade\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HABIL][TAM_HABIL];
    int cruz[TAM_HABIL][TAM_HABIL];
    int octaedro[TAM_HABIL][TAM_HABIL];

    // Etapa 1: Inicialização
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    // Etapa 2: Geração das matrizes de habilidade
    gerarMatrizCone(cone);
    gerarMatrizCruz(cruz);
    gerarMatrizOctaedro(octaedro);

    // Etapa 3: Aplicação das habilidades na ordem correta
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);  // Octaedro em (7,2)
    aplicarHabilidade(tabuleiro, cruz, 6, 6);      // Cruz em (6,6)
    aplicarHabilidade(tabuleiro, cone, 3, 4);      // Cone em (3,4)

    // Etapa 4: Exibir tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}