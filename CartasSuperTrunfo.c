#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades
// utilizando scanf para entrada de dados e printf para exibir as informações.

int main() {
    // Carta 1
    char estado1[3], codigo1[4], nome1[50];
    int populacao1, pontos_turisticos1;
    float area1, pib1;

    // Carta 2
    char estado2[3], codigo2[4], nome2[50];
    int populacao2, pontos_turisticos2;
    float area2, pib2;

    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o estado (ex: SP): ");
    scanf("%2s", estado1);
    printf("Digite o código da carta: ");
    scanf("%3s", codigo1);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nome1);
    printf("Digite a população: ");
    scanf("%d", &populacao1);
    printf("Digite a área: ");
    scanf("%f", &area1);
    printf("Digite o PIB: ");
    scanf("%f", &pib1);
    printf("Digite os pontos turísticos: ");
    scanf("%d", &pontos_turisticos1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Digite o estado (ex: RJ): ");
    scanf("%2s", estado2);
    printf("Digite o código da carta: ");
    scanf("%3s", codigo2);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nome2);
    printf("Digite a população: ");
    scanf("%d", &populacao2);
    printf("Digite a área: ");
    scanf("%f", &area2);
    printf("Digite o PIB: ");
    scanf("%f", &pib2);
    printf("Digite os pontos turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Exibição das duas cartas
    printf("\n=== Carta 1 ===\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", nome1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", pib1);
    printf("Pontos turísticos: %d\n", pontos_turisticos1);

    printf("\n=== Carta 2 ===\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", nome2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões\n", pib2);
    printf("Pontos turísticos: %d\n", pontos_turisticos2);

    return 0;
}
