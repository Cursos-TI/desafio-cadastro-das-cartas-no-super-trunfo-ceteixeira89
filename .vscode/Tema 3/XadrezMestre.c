#include <stdio.h>

// ==============================================
// Funções Recursivas para Torre, Bispo e Rainha
// ==============================================

// Movimento da Torre (direita) com recursão
void moverTorre(int casas, int atual) {
    
    if (atual > casas) return;
    
    printf("Direita (%d)\n", atual);
    moverTorre(casas, atual + 1);
}

// Movimento da Rainha (esquerda) com recursão
void moverRainha(int casas, int atual) {
    
    if (atual > casas) return;
    
    printf("Esquerda (%d)\n", atual);
    moverRainha(casas, atual + 1);
}

// Movimento do Bispo com recursão + loops aninhados
void moverBispo(int casas, int atual) {
    
    if (atual > casas) return;

    // Loop externo simula passo vertical (Cima)
    for (int v = atual; v <= atual; v++) {
        // Loop interno simula passo horizontal (Direita)
        
        for (int h = 1; h <= 1; h++) {
            printf("Cima Direita (%d)\n", atual);
        }
    }

    moverBispo(casas, atual + 1);
}

// =====================================================
// Movimento do Cavalo (2 casas para cima, 1 para direita)
// =====================================================
void moverCavalo() {
    
    int movimentos = 1; // apenas um movimento em "L"
    int upMax = 2;      // 2 casas para cima
    int rightMax = 1;   // 1 casa para a direita

    printf("\nMovimento do Cavalo:\n");

    for (int i = 1; i <= movimentos; i++) {
        int up = 0, right = 0;

        // Loop vertical (para cima)
        for (int v = 1; v <= upMax; v++) {
            if (v > upMax) break;
            
            printf("Cima (%d)\n", v);
            up++;
        }

        // Loop horizontal (para direita)
        for (int h = 1; h <= rightMax + 1; h++) {
            
            if (h != 1) continue; // garante que só imprima uma vez
            
            printf("Direita (%d)\n", h);
            right++;
        }
    }
}

// ==============================================
// Função Principal: Chama todos os movimentos
// ==============================================
int main() {
    // ====================
    // Movimentação da Torre
    // ====================
    // Recursiva: 5 casas para a direita
    
    printf("Movimento da Torre:\n");
    moverTorre(5, 1);

    // ====================
    // Movimentação do Bispo
    // ====================
    // Recursiva + Loops Aninhados: 5 casas na diagonal (Cima Direita)
    
    printf("\nMovimento do Bispo:\n");
    moverBispo(5, 1);

    // ====================
    // Movimentação da Rainha
    // ====================
    // Recursiva: 8 casas para a esquerda
    
    printf("\nMovimento da Rainha:\n");
    moverRainha(8, 1);

    // ====================
    // Movimentação do Cavalo
    // ====================
    // Loops aninhados com múltiplas variáveis e controle de fluxo
    
    moverCavalo();

    return 0;
}