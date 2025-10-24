#include <stdio.h>   // Biblioteca padrão de entrada e saída (printf, scanf)
#include <string.h>  // Biblioteca para manipulação de strings (fgets, strcspn)

int main() {
    // ========================
    // DECLARAÇÃO DAS VARIÁVEIS
    // ========================
    
    // Dados de identificação das cartas
    char estado1[3], estado2[3];   // Guarda a sigla do estado (2 letras + '\0')
    char codigo1[10], codigo2[10]; // Código de identificação da carta
    char nome1[50], nome2[50];     // Nome do país (ou cidade, dependendo do jogo)

    // Atributos numéricos de cada carta
    unsigned long int populacao1, populacao2; // População dos países
    float area1, area2;                       // Área em km²
    float pib1, pib2;                         // PIB em bilhões
    int pontos1, pontos2;                     // Número de pontos turísticos

    // Atributos calculados
    float densidade1, densidade2;             // População / área

    // Variáveis de controle do menu
    int opcao;                                // Guarda a opção escolhida pelo jogador
    char continuar;                           // Permite repetir o jogo

    // ========================
    // ENTRADA DE DADOS - CARTA 1
    // ========================
    printf("=== Cadastro da Carta 1 ===\n");

    // Coleta da sigla do estado (2 caracteres)
    printf("Estado (UF): ");
    scanf("%2s", estado1);

    // Código da carta (pode ser qualquer identificação)
    printf("Código da Carta: ");
    scanf("%s", codigo1);

    // Nome do país ou cidade
    printf("Nome do País: ");
    getchar(); // limpa o ENTER deixado pelo scanf anterior
    fgets(nome1, sizeof(nome1), stdin); // lê o nome com espaços
    nome1[strcspn(nome1, "\n")] = '\0'; // remove o '\n' do final da string

    // Coleta dos atributos numéricos
    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos1);

    // ========================
    // ENTRADA DE DADOS - CARTA 2
    // ========================
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado (UF): ");
    scanf("%2s", estado2);

    printf("Código da Carta: ");
    scanf("%s", codigo2);

    printf("Nome do País: ");
    getchar(); // limpa o ENTER do buffer
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
    // CÁLCULOS
    // ========================

    // Calcula a densidade populacional (habitantes por km²)
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    // ========================
    // MENU INTERATIVO
    // ========================
    do {
        // Exibe o menu para o jogador escolher o atributo de comparação
        printf("\n===== MENU DE COMPARAÇÃO =====\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos Turísticos\n");
        printf("5. Densidade Demográfica (vence o menor)\n");
        printf("Escolha o atributo para comparar: ");
        scanf("%d", &opcao);

        printf("\n===== RESULTADO =====\n");

        // ========================
        // SWITCH PARA ESCOLHER O ATRIBUTO
        // ========================
        switch (opcao) {
            // Caso 1: Comparação por População
            case 1:
                printf("Atributo: População\n");
                printf("%s: %lu habitantes\n", nome1, populacao1);
                printf("%s: %lu habitantes\n", nome2, populacao2);

                // Estrutura de decisão aninhada para verificar o vencedor
                if (populacao1 > populacao2)
                    printf("🏆 %s venceu!\n", nome1);
                else if (populacao1 < populacao2)
                    printf("🏆 %s venceu!\n", nome2);
                else
                    printf("🤝 Empate!\n");
                break;

            // Caso 2: Comparação por Área
            case 2:
                printf("Atributo: Área\n");
                printf("%s: %.2f km²\n", nome1, area1);
                printf("%s: %.2f km²\n", nome2, area2);

                if (area1 > area2)
                    printf("🏆 %s venceu!\n", nome1);
                else if (area1 < area2)
                    printf("🏆 %s venceu!\n", nome2);
                else
                    printf("🤝 Empate!\n");
                break;

            // Caso 3: Comparação por PIB
            case 3:
                printf("Atributo: PIB\n");
                printf("%s: %.2f bilhões\n", nome1, pib1);
                printf("%s: %.2f bilhões\n", nome2, pib2);

                if (pib1 > pib2)
                    printf("🏆 %s venceu!\n", nome1);
                else if (pib1 < pib2)
                    printf("🏆 %s venceu!\n", nome2);
                else
                    printf("🤝 Empate!\n");
                break;

            // Caso 4: Comparação por Pontos Turísticos
            case 4:
                printf("Atributo: Pontos Turísticos\n");
                printf("%s: %d pontos\n", nome1, pontos1);
                printf("%s: %d pontos\n", nome2, pontos2);

                if (pontos1 > pontos2)
                    printf("🏆 %s venceu!\n", nome1);
                else if (pontos1 < pontos2)
                    printf("🏆 %s venceu!\n", nome2);
                else
                    printf("🤝 Empate!\n");
                break;

            // Caso 5: Comparação por Densidade Demográfica (regra invertida)
            case 5:
                printf("Atributo: Densidade Demográfica (vence o menor)\n");
                printf("%s: %.2f hab/km²\n", nome1, densidade1);
                printf("%s: %.2f hab/km²\n", nome2, densidade2);

                // Aqui a regra é invertida: vence o menor valor
                if (densidade1 < densidade2)
                    printf("🏆 %s venceu!\n", nome1);
                else if (densidade1 > densidade2)
                    printf("🏆 %s venceu!\n", nome2);
                else
                    printf("🤝 Empate!\n");
                break;

            // Caso padrão: opção inválida
            default:
                printf("⚠️ Opção inválida! Escolha um número de 1 a 5.\n");
                break;
        }

        // Pergunta se o jogador deseja realizar outra comparação
        printf("\nDeseja comparar outro atributo? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S'); // repete enquanto o jogador responder 's'

    // ========================
    // ENCERRAMENTO DO PROGRAMA
    // ========================
    printf("\nEncerrando o jogo. Obrigado por jogar Super Trunfo!\n");
    return 0; // Encerra o programa com sucesso
}
