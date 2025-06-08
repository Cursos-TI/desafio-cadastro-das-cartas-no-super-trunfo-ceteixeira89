#include <stdio.h>

// Exibir menu e retornar atributo escolhido
int escolherAtributo(int bloqueado) {
    int escolha = 0;

    printf("\nEscolha um atributo para comparar:\n");

    if (bloqueado != 1) printf("1 - Populacao\n");
    if (bloqueado != 2) printf("2 - Area\n");
    if (bloqueado != 3) printf("3 - PIB\n");
    if (bloqueado != 4) printf("4 - Pontos Turisticos\n");
    if (bloqueado != 5) printf("5 - Densidade Demografica\n");

    printf("Opcao: ");
    scanf("%d", &escolha);

    // Verifica se repetiu o atributo
    if (escolha == bloqueado || escolha < 1 || escolha > 5) {
        printf("Opcao invalida ou repetida. Tente novamente.\n");
        return escolherAtributo(bloqueado); // Chamada recursiva até escolha válida
    }

    return escolha;
}

// Função que retorna o valor numérico de um atributo
float obterValorAtributo(int atributo, unsigned long pop, float area, float pib, int pontos, float densidade) {
    switch (atributo) {
        case 1: return (float)pop;
        case 2: return area;
        case 3: return pib;
        case 4: return (float)pontos;
        case 5: return densidade;
        default: return 0;
    }
}

// Função que imprime o nome de um atributo
void exibirNomeAtributo(int atributo) {
    switch (atributo) {
        case 1: printf("Populacao"); break;
        case 2: printf("Area"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Pontos Turisticos"); break;
        case 5: printf("Densidade Demografica"); break;
    }
}

int main() {
    // Dados das cartas
    char nomePais1[] = "Brasil";
    unsigned long int pop1 = 213000000;
    float area1 = 8515767.0;
    float pib1 = 1800.0;
    int pontos1 = 25;
    float densidade1 = pop1 / area1;

    char nomePais2[] = "Japao";
    unsigned long int pop2 = 126000000;
    float area2 = 377975.0;
    float pib2 = 5000.0;
    int pontos2 = 50;
    float densidade2 = pop2 / area2;

    // Escolha de dois atributos
    int atributo1 = escolherAtributo(0);
    int atributo2 = escolherAtributo(atributo1);

    // Obter valores para os dois atributos de cada carta
    float valor1A = obterValorAtributo(atributo1, pop1, area1, pib1, pontos1, densidade1);
    float valor1B = obterValorAtributo(atributo2, pop1, area1, pib1, pontos1, densidade1);

    float valor2A = obterValorAtributo(atributo1, pop2, area2, pib2, pontos2, densidade2);
    float valor2B = obterValorAtributo(atributo2, pop2, area2, pib2, pontos2, densidade2);

    float soma1 = valor1A + valor1B;
    float soma2 = valor2A + valor2B;

    // Exibição dos resultados
    printf("\n--- Comparacao Final ---\n");

    // Atributo 1
    printf("\nAtributo 1: ");
    exibirNomeAtributo(atributo1);
    printf("\n%s: %.2f", nomePais1, valor1A);
    printf("\n%s: %.2f\n", nomePais2, valor2A);

    // Regra especial para densidade
    if (atributo1 == 5) {
        printf("Vencedor: %s\n", (valor1A < valor2A) ? nomePais1 : (valor2A < valor1A) ? nomePais2 : "Empate!");
    } else {
        printf("Vencedor: %s\n", (valor1A > valor2A) ? nomePais1 : (valor2A > valor1A) ? nomePais2 : "Empate!");
    }

    // Atributo 2
    printf("\nAtributo 2: ");
    exibirNomeAtributo(atributo2);
    printf("\n%s: %.2f", nomePais1, valor1B);
    printf("\n%s: %.2f\n", nomePais2, valor2B);

    if (atributo2 == 5) {
        printf("Vencedor: %s\n", (valor1B < valor2B) ? nomePais1 : (valor2B < valor1B) ? nomePais2 : "Empate!");
    } else {
        printf("Vencedor: %s\n", (valor1B > valor2B) ? nomePais1 : (valor2B > valor1B) ? nomePais2 : "Empate!");
    }

    // Soma final
    printf("\n--- Resultado da Rodada ---\n");
    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", nomePais1, soma1);
    printf("%s: %.2f\n", nomePais2, soma2);

    // Resultado final
    printf("Resultado: %s\n", (soma1 > soma2) ? nomePais1 : (soma2 > soma1) ? nomePais2 : "Empate!");

    return 0;
}
