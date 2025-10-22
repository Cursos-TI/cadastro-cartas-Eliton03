#include <stdio.h>
#include <string.h> // Para strcspn

int main() {
    // ========================
    // Declaração das variáveis
    // ========================
    char estado1[3], estado2[3];     // UF com 2 letras + '\0'
    char codigo1[10], codigo2[10];
    char nome1[50], nome2[50];
    
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontos1, pontos2;

    // Variáveis calculadas
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;
    float superPoder1, superPoder2;

    // Contadores de vitórias
    int vitorias1 = 0, vitorias2 = 0;

    // ========================
    // Entrada de dados - Carta 1
    // ========================
    printf("=== Cadastro da Carta 1 ===\n");
    
    printf("Estado (UF, ex: SP): ");
    scanf("%2s", estado1); // lê UF de 2 letras

    printf("Código da Carta: ");
    scanf("%s", codigo1);

    printf("Nome da Cidade: ");
    getchar(); // limpa o ENTER que ficou no buffer
    fgets(nome1, sizeof(nome1), stdin);
    nome1[strcspn(nome1, "\n")] = '\0'; // remove ENTER do final

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos1);

    // ========================
    // Entrada de dados - Carta 2
    // ========================
    printf("\n=== Cadastro da Carta 2 ===\n");
    
    printf("Estado (UF, ex: RJ): ");
    scanf("%2s", estado2);

    printf("Código da Carta: ");
    scanf("%s", codigo2);

    printf("Nome da Cidade: ");
    getchar(); // limpa o ENTER
    fgets(nome2, sizeof(nome2), stdin);
    nome2[strcspn(nome2, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos2);

    // ========================
    // Cálculos
    // ========================
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    superPoder1 = (float)populacao1 + area1 + pib1 + pontos1 + pibPerCapita1 + (1.0 / densidade1);
    superPoder2 = (float)populacao2 + area2 + pib2 + pontos2 + pibPerCapita2 + (1.0 / densidade2);

    // ========================
    // Exibição das Cartas
    // ========================
    printf("\n===== CARTA 1 =====\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", nome1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", pib1);
    printf("Pontos Turísticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\n===== CARTA 2 =====\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", nome2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões\n", pib2);
    printf("Pontos Turísticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // ========================
    // Comparações (com if/else)
    // ========================
    printf("\n===== RESULTADO DA BATALHA =====\n");

    if (populacao1 > populacao2) {
        printf("População: Carta 1 venceu!\n");
        vitorias1++;
    } else if (populacao1 < populacao2) {
        printf("População: Carta 2 venceu!\n");
        vitorias2++;
    } else {
        printf("População: Empate!\n");
    }

    if (area1 > area2) {
        printf("Área: Carta 1 venceu!\n");
        vitorias1++;
    } else if (area1 < area2) {
        printf("Área: Carta 2 venceu!\n");
        vitorias2++;
    } else {
        printf("Área: Empate!\n");
    }

    if (pib1 > pib2) {
        printf("PIB: Carta 1 venceu!\n");
        vitorias1++;
    } else if (pib1 < pib2) {
        printf("PIB: Carta 2 venceu!\n");
        vitorias2++;
    } else {
        printf("PIB: Empate!\n");
    }

    if (pontos1 > pontos2) {
        printf("Pontos Turísticos: Carta 1 venceu!\n");
        vitorias1++;
    } else if (pontos1 < pontos2) {
        printf("Pontos Turísticos: Carta 2 venceu!\n");
        vitorias2++;
    } else {
        printf("Pontos Turísticos: Empate!\n");
    }

    if (densidade1 < densidade2) {
        printf("Densidade Populacional: Carta 1 venceu!\n");
        vitorias1++;
    } else if (densidade1 > densidade2) {
        printf("Densidade Populacional: Carta 2 venceu!\n");
        vitorias2++;
    } else {
        printf("Densidade Populacional: Empate!\n");
    }

    if (pibPerCapita1 > pibPerCapita2) {
        printf("PIB per Capita: Carta 1 venceu!\n");
        vitorias1++;
    } else if (pibPerCapita1 < pibPerCapita2) {
        printf("PIB per Capita: Carta 2 venceu!\n");
        vitorias2++;
    } else {
        printf("PIB per Capita: Empate!\n");
    }

    if (superPoder1 > superPoder2) {
        printf("Super Poder: Carta 1 venceu!\n");
        vitorias1++;
    } else if (superPoder1 < superPoder2) {
        printf("Super Poder: Carta 2 venceu!\n");
        vitorias2++;
    } else {
        printf("Super Poder: Empate!\n");
    }

    // ========================
    // Resultado Final
    // ========================
    printf("\n===== RESULTADO FINAL =====\n");
    printf("Vitórias da Carta 1: %d\n", vitorias1);
    printf("Vitórias da Carta 2: %d\n", vitorias2);

    if (vitorias1 > vitorias2) {
        printf("🏆 Carta 1 é a grande vencedora!\n");
    } else if (vitorias1 < vitorias2) {
        printf("🏆 Carta 2 é a grande vencedora!\n");
    } else {
        printf("🤝 Empate geral!\n");
    }

    return 0;
}
