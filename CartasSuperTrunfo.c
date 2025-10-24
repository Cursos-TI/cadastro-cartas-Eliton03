#include <stdio.h>
#include <string.h>

// ========================
// FUNÇÃO DE COMPARAÇÃO
// ========================
int comparar(float valor1, float valor2, int menorVence) {
    if (menorVence) {
        if (valor1 < valor2) return 1;
        else if (valor1 > valor2) return 2;
        else return 0;
    } else {
        if (valor1 > valor2) return 1;
        else if (valor1 < valor2) return 2;
        else return 0;
    }
}

int main() {
    // ========================
    // DECLARAÇÃO DAS VARIÁVEIS
    // ========================
    char estado1[3], estado2[3];     // UF do país/cidade
    char codigo1[10], codigo2[10];   // Código da carta
    char nome1[50], nome2[50];       // Nome do país/cidade

    unsigned long populacao1, populacao2; // População
    float area1, area2, pib1, pib2;       // Área e PIB
    int pontos1, pontos2;                 // Pontos turísticos
    float densidade1, densidade2;         // Densidade demográfica

    int atributo1, atributo2; // Atributos escolhidos pelo jogador
    float valor1A, valor2A, valor1B, valor2B;
    int menorVence;
    
    // ========================
    // ENTRADA DAS CARTAS
    // ========================

    // --- Carta 1 ---
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (UF): "); scanf("%2s", estado1);
    printf("Código da Carta: "); scanf("%s", codigo1);
    printf("Nome do País: ");
    getchar(); // limpa buffer
    fgets(nome1, sizeof(nome1), stdin);
    nome1[strcspn(nome1, "\n")] = '\0';
    printf("População: "); scanf("%lu", &populacao1);
    printf("Área (km²): "); scanf("%f", &area1);
    printf("PIB (em bilhões): "); scanf("%f", &pib1);
    printf("Pontos Turísticos: "); scanf("%d", &pontos1);

    // --- Carta 2 ---
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (UF): "); scanf("%2s", estado2);
    printf("Código da Carta: "); scanf("%s", codigo2);
    printf("Nome do País: ");
    getchar();
    fgets(nome2, sizeof(nome2), stdin);
    nome2[strcspn(nome2, "\n")] = '\0';
    printf("População: "); scanf("%lu", &populacao2);
    printf("Área (km²): "); scanf("%f", &area2);
    printf("PIB (em bilhões): "); scanf("%f", &pib2);
    printf("Pontos Turísticos: "); scanf("%d", &pontos2);

    // ========================
    // CÁLCULO DE DENSIDADE
    // ========================
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    // ========================
    // ESCOLHA DOS ATRIBUTOS
    // ========================
    printf("\n===== ESCOLHA DO PRIMEIRO ATRIBUTO =====\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica (menor vence)\n");
    printf("Escolha o primeiro atributo: "); scanf("%d", &atributo1);

    printf("\n===== ESCOLHA DO SEGUNDO ATRIBUTO =====\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica (menor vence)\n");
    printf("Escolha o segundo atributo (diferente do primeiro): "); scanf("%d", &atributo2);
    while (atributo2 == atributo1) {
        printf("Opção inválida! Escolha um atributo diferente do primeiro: ");
        scanf("%d", &atributo2);
    }

    // ========================
    // COMPARAÇÃO DO PRIMEIRO ATRIBUTO
    // ========================
    switch (atributo1) {
        case 1: valor1A = populacao1; valor2A = populacao2; menorVence = 0; break;
        case 2: valor1A = area1; valor2A = area2; menorVence = 0; break;
        case 3: valor1A = pib1; valor2A = pib2; menorVence = 0; break;
        case 4: valor1A = pontos1; valor2A = pontos2; menorVence = 0; break;
        case 5: valor1A = densidade1; valor2A = densidade2; menorVence = 1; break;
    }

    int vencedor1 = comparar(valor1A, valor2A, menorVence);

    // ========================
    // COMPARAÇÃO DO SEGUNDO ATRIBUTO
    // ========================
    switch (atributo2) {
        case 1: valor1B = populacao1; valor2B = populacao2; menorVence = 0; break;
        case 2: valor1B = area1; valor2B = area2; menorVence = 0; break;
        case 3: valor1B = pib1; valor2B = pib2; menorVence = 0; break;
        case 4: valor1B = pontos1; valor2B = pontos2; menorVence = 0; break;
        case 5: valor1B = densidade1; valor2B = densidade2; menorVence = 1; break;
    }

    int vencedor2 = comparar(valor1B, valor2B, menorVence);

    // ========================
    // EXIBIÇÃO DO RESULTADO
    // ========================
    printf("\n===== RESULTADO DAS CARTAS =====\n");
    printf("Carta 1: %s (%s) - Código: %s\n", nome1, estado1, codigo1);
    printf("Carta 2: %s (%s) - Código: %s\n\n", nome2, estado2, codigo2);

    printf("Atributos selecionados:\n");
    printf("1º: %.2f vs %.2f\n", valor1A, valor2A);
    printf("2º: %.2f vs %.2f\n\n", valor1B, valor2B);

    // Soma dos atributos para determinar vencedor final
    float soma1 = valor1A + valor1B;
    float soma2 = valor2A + valor2B;

    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", nome1, soma1);
    printf("%s: %.2f\n\n", nome2, soma2);

    if (soma1 > soma2) printf("🏆 %s venceu a rodada!\n", nome1);
    else if (soma1 < soma2) printf("🏆 %s venceu a rodada!\n", nome2);
    else printf("🤝 Empate!\n");

    return 0;
}
