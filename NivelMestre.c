#include <stdio.h>
#include <string.h> // Para usar strcspn

// Função para limpar o buffer de entrada
void limparBuffer() {
    while (getchar() != '\n');
}

// Função para exibir o menu de atributos e retornar a escolha do jogador
int escolherAtributo(int numAtributo) {
    int escolha;
    do {
        printf("\nEscolha o %dº atributo para comparação:\n", numAtributo);
        printf("1 - População (maior vence)\n");
        printf("2 - Área (maior vence)\n");
        printf("3 - PIB (maior vence)\n");
        printf("4 - Pontos Turísticos (maior vence)\n");
        printf("5 - Densidade Populacional (menor vence)\n");
        printf("6 - PIB per Capita (maior vence)\n");
        printf("7 - Super Poder (maior vence)\n");
        printf("Escolha (1-7): ");
        scanf("%d", &escolha);
        limparBuffer();
    } while(escolha < 1 || escolha > 7);
    
    return escolha;
}

// Função para cadastrar uma carta
void cadastrarCarta(char *estado, char codigo[], char cidade[], int *populacao, 
                   float *area, float *pib, int *pontosturisticos, 
                   float *densidade, float *pibPerCapita, float *superPoder, int numCarta) {
    printf("\nInsira as informações da Carta %d\n", numCarta);

    printf("Escolha a letra entre A a H para representar o estado:\n");
    scanf(" %c", estado);
    printf("Escolha um codigo entre A01 a A04:\n");
    scanf(" %3s", codigo);
    printf("Insira o nome da cidade:\n");
    limparBuffer();
    fgets(cidade, 50, stdin);
    cidade[strcspn(cidade, "\n")] = 0; // Remove o \n do final
    
    printf("Insira a quantidade de habitantes da cidade:\n");
    scanf("%d", populacao);
    printf("Insira a área territorial da cidade (km²):\n");
    scanf("%f", area);
    printf("Insira o valor do PIB da cidade (em milhões):\n");
    scanf("%f", pib);
    printf("Insira a quantidade de pontos turísticos da cidade:\n");
    scanf("%d", pontosturisticos);
    limparBuffer();
    
    // Cálculos derivados
    *densidade = (float)*populacao / *area;
    *pibPerCapita = (float)*pib / *populacao;
    *superPoder = *populacao + *area + *pib + *pontosturisticos + *pibPerCapita + (1 / *densidade);
}

// Função para exibir os dados de uma carta
void exibirCarta(char estado, char codigo[], char cidade[], int populacao, 
                float area, float pib, int pontosturisticos, float densidade, 
                float pibPerCapita, float superPoder, int numCarta) {
    printf("\n=== CARTA %d ===\n", numCarta);
    printf("Estado: %c\n", estado);
    printf("Código: %s\n", codigo);
    printf("Cidade: %s\n", cidade);
    printf("População: %d habitantes\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f milhões\n", pib);
    printf("Pontos Turísticos: %d\n", pontosturisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade);
    printf("PIB per capita: %.2f\n", pibPerCapita);
    printf("Super Poder: %.2f\n", superPoder);
}

// Função para comparar cartas por um atributo específico
void compararPorAtributo(int atributo, int *pontosCarta1, int *pontosCarta2,
                        int pop1, int pop2, float area1, float area2,
                        float pib1, float pib2, int pts1, int pts2,
                        float dens1, float dens2, float pibCap1, float pibCap2,
                        float sp1, float sp2) {
    
    char *nomesAtributos[] = {"", "População", "Área", "PIB", "Pontos Turísticos", 
                             "Densidade", "PIB per Capita", "Super Poder"};
    
    printf("\nComparando por %s: ", nomesAtributos[atributo]);
    
    // Operador ternário para determinar o vencedor
    int resultado = 
        (atributo == 1) ? (pop1 > pop2 ? 1 : (pop1 < pop2 ? 2 : 0)) :
        (atributo == 2) ? (area1 > area2 ? 1 : (area1 < area2 ? 2 : 0)) :
        (atributo == 3) ? (pib1 > pib2 ? 1 : (pib1 < pib2 ? 2 : 0)) :
        (atributo == 4) ? (pts1 > pts2 ? 1 : (pts1 < pts2 ? 2 : 0)) :
        (atributo == 5) ? (dens1 < dens2 ? 1 : (dens1 > dens2 ? 2 : 0)) :
        (atributo == 6) ? (pibCap1 > pibCap2 ? 1 : (pibCap1 < pibCap2 ? 2 : 0)) :
        (atributo == 7) ? (sp1 > sp2 ? 1 : (sp1 < sp2 ? 2 : 0)) : 0;
    
    if (resultado == 1) {
        printf("Carta 1 vence!\n");
        (*pontosCarta1)++;
    } else if (resultado == 2) {
        printf("Carta 2 vence!\n");
        (*pontosCarta2)++;
    } else {
        printf("Empate!\n");
    }
}

// Função principal
int main() {
    // Variáveis das cartas
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[50], cidade2[50];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontosturisticos1, pontosturisticos2;
    float densidade1, densidade2;
    float pibPerCapita1, pibPerCapita2;
    float superPoder1, superPoder2;
    
    int opcao;
    do {
        printf("\n=== SUPER TRUNFO PAÍSES - NÍVEL MESTRE ===\n");
        printf("1 - Cadastrar cartas\n");
        printf("2 - Exibir cartas\n");
        printf("3 - Comparar cartas\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1: // Cadastro de cartas
                cadastrarCarta(&estado1, codigo1, cidade1, &populacao1, &area1, &pib1,
                              &pontosturisticos1, &densidade1, &pibPerCapita1, &superPoder1, 1);
                cadastrarCarta(&estado2, codigo2, cidade2, &populacao2, &area2, &pib2,
                              &pontosturisticos2, &densidade2, &pibPerCapita2, &superPoder2, 2);
                break;
                
            case 2: // Exibição de cartas
                exibirCarta(estado1, codigo1, cidade1, populacao1, area1, pib1,
                           pontosturisticos1, densidade1, pibPerCapita1, superPoder1, 1);
                exibirCarta(estado2, codigo2, cidade2, populacao2, area2, pib2,
                           pontosturisticos2, densidade2, pibPerCapita2, superPoder2, 2);
                break;
                
            case 3: // Comparação de cartas
                if (populacao1 == 0 || populacao2 == 0) {
                    printf("\nCadastre ambas as cartas primeiro!\n");
                    break;
                }
                
                int atributo1 = escolherAtributo(1);
                int atributo2;
                do {
                    atributo2 = escolherAtributo(2);
                    if (atributo2 == atributo1) {
                        printf("Você já escolheu esse atributo. Escolha outro.\n");
                    }
                } while (atributo2 == atributo1);
                
                int pontosCarta1 = 0, pontosCarta2 = 0;
                
                // Comparação pelo primeiro atributo
                compararPorAtributo(atributo1, &pontosCarta1, &pontosCarta2,
                                   populacao1, populacao2, area1, area2, pib1, pib2,
                                   pontosturisticos1, pontosturisticos2, densidade1, densidade2,
                                   pibPerCapita1, pibPerCapita2, superPoder1, superPoder2);
                
                // Comparação pelo segundo atributo
                compararPorAtributo(atributo2, &pontosCarta1, &pontosCarta2,
                                   populacao1, populacao2, area1, area2, pib1, pib2,
                                   pontosturisticos1, pontosturisticos2, densidade1, densidade2,
                                   pibPerCapita1, pibPerCapita2, superPoder1, superPoder2);
                
                // Exibir resultado final
                printf("\n=== RESULTADO FINAL ===\n");
                printf("Carta 1: %d pontos\n", pontosCarta1);
                printf("Carta 2: %d pontos\n", pontosCarta2);
                
                if (pontosCarta1 > pontosCarta2) {
                    printf("\nCarta 1 é a vencedora!\n");
                } else if (pontosCarta1 < pontosCarta2) {
                    printf("\nCarta 2 é a vencedora!\n");
                } else {
                    printf("\nEmpate! As cartas são igualmente poderosas!\n");
                }
                break;
                
            case 4:
                printf("Saindo do jogo...\n");
                break;
                
            default:
                printf("Opção inválida!\n");
        }
        
    } while(opcao != 4);

    return 0;
}