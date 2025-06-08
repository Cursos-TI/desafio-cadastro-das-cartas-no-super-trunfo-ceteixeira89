#include <stdio.h>

int main() {
    // Dados fixos das duas cartas (cadastrados diretamente no código)
    char nomePais1[] = "Brasil";
    unsigned long int populacao1 = 213000000;
    float area1 = 8515767.0;
    float pib1 = 1800.0; // em bilhões
    int pontosTuristicos1 = 25;
    float densidade1 = populacao1 / area1;

    char nomePais2[] = "Japao";
    unsigned long int populacao2 = 126000000;
    float area2 = 377975.0;
    float pib2 = 5000.0; // em bilhões
    int pontosTuristicos2 = 50;
    float densidade2 = populacao2 / area2;

    int opcao;

    // Menu interativo
    printf("=== Super Trunfo - Comparacao de Cartas ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("\n--- Resultado da Comparacao ---\n");

    switch (opcao) {
        case 1:
            printf("Comparando Populacao:\n");
            printf("%s: %lu habitantes\n", nomePais1, populacao1);
            printf("%s: %lu habitantes\n", nomePais2, populacao2);

            if (populacao1 > populacao2) {
                printf("Resultado: %s venceu!\n", nomePais1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: %s venceu!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2:
            printf("Comparando Area:\n");
            printf("%s: %.2f km²\n", nomePais1, area1);
            printf("%s: %.2f km²\n", nomePais2, area2);

            if (area1 > area2) {
                printf("Resultado: %s venceu!\n", nomePais1);
            } else if (area2 > area1) {
                printf("Resultado: %s venceu!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3:
            printf("Comparando PIB:\n");
            printf("%s: %.2f bilhões de reais\n", nomePais1, pib1);
            printf("%s: %.2f bilhões de reais\n", nomePais2, pib2);

            if (pib1 > pib2) {
                printf("Resultado: %s venceu!\n", nomePais1);
            } else if (pib2 > pib1) {
                printf("Resultado: %s venceu!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4:
            printf("Comparando Pontos Turisticos:\n");
            printf("%s: %d pontos\n", nomePais1, pontosTuristicos1);
            printf("%s: %d pontos\n", nomePais2, pontosTuristicos2);

            if (pontosTuristicos1 > pontosTuristicos2) {
                printf("Resultado: %s venceu!\n", nomePais1);
            } else if (pontosTuristicos2 > pontosTuristicos1) {
                printf("Resultado: %s venceu!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5:
            printf("Comparando Densidade Demografica (menor vence):\n");
            printf("%s: %.2f hab/km²\n", nomePais1, densidade1);
            printf("%s: %.2f hab/km²\n", nomePais2, densidade2);

            if (densidade1 < densidade2) {
                printf("Resultado: %s venceu!\n", nomePais1);
            } else if (densidade2 < densidade1) {
                printf("Resultado: %s venceu!\n", nomePais2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opcao invalida! Tente novamente com um numero de 1 a 5.\n");
    }

    return 0;
}
