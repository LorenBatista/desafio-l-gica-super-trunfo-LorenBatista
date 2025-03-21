#include <stdio.h>
#include <string.h> // Para usar strcspn

// Função para limpar o buffer de entrada
void limparBuffer() {
    while (getchar() != '\n');
}

// Função para exibir o menu de atributos e retornar a escolha do jogador
int escolherAtributo(int atributoEscolhido) {
    int escolha;
    printf("\nEscolha o %dº atributo para comparação:\n", atributoEscolhido);
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("7 - Super Poder\n");
    printf("Escolha: ");
    scanf("%d", &escolha);
    return escolha;
}

int main(){
//variáveis das cartas
    char estado, estado2; // char para caracteres, [] para vetores de caracteres.
    char codigo[4], codigo2[4]; 
    char cidade[50], cidade2[50];
    int populacao, populacao2; // int para números inteiros.
    float area, area2; // float para números reais.
    float pib, pib2;
    int pontosturisticos, pontosturisticos2;
    float densidade, densidade2;
    float pibPerCapita, pibPerCapita2;
    float superPoder, superPoder2;

    // Informações da primeira carta
    printf("\nInsira as informações da Carta 01\n");

    printf("Escolha a letra entre A a H para representar o estado:\n");
    scanf(" %c", &estado);
    printf("Escolha um codigo entre A01 a A04:\n");
    scanf(" %3s", codigo);
    printf("Insira o nome da cidade:\n");
    getchar(); // limpar o buffer1
    fgets(cidade, sizeof(cidade), stdin);
    printf("Insira a quantidade de habitantes da cidade:\n");
    scanf(" %d", &populacao);
    printf("Insira a área territorial da cidade:\n");
    scanf(" %f", &area);
    printf("Insira o valor do PIB da cidade:\n");
    scanf(" %f", &pib);
    printf("Insira a quantidade de pontos turísticos da cidade:\n");
    scanf(" %d", &pontosturisticos);

    // Informações da segunda carta
    printf("\nInsira as informações da Carta 02\n");
    
    printf("Escolha a letra entre A a H para representar o estado:\n");
    scanf(" %c", &estado2);
    printf("Escolha um codigo entre A01 a A04:\n");
    scanf(" %3s", codigo2);
    printf("Insina o nome da cidade:\n");
    getchar(); // limpar o buffer1
    fgets(cidade2, sizeof(cidade2), stdin);
    printf("Insira a quantidade de habitantes da cidade:\n");
    scanf(" %d", &populacao2);
    printf("Insira a área territorial da cidade:\n");
    scanf(" %f", &area2);
    printf("Insira o valor do PIB da cidade:\n");
    scanf(" %f", &pib2);
    printf("Insira a quantidade de pontos turísticos da cidade:\n");
    scanf(" %d", &pontosturisticos2);

    // Cálculos para a primeira carta
    densidade = (float)populacao / area;
    pibPerCapita = (float)pib / populacao;
    superPoder = populacao + area + pib + pontosturisticos + pibPerCapita + (1 / densidade);

    // Cálculos para a segunda carta
    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (float)pib2 / populacao2;
    superPoder2 = populacao2 + area2 + pib2 + pontosturisticos2 + pibPerCapita2 + (1 / densidade2);

    printf("\nDados da Carta 01\n");

    printf("Estado: %c\n", estado);
    printf("Codigo: %s\n", codigo);
    printf("Cidade: %s", cidade);
    printf("População: %d\n", populacao);
    printf("Área: %.2f\n", area);
    printf("PIB: %.2f\n", pib);
    printf("Pontos Turísticos: %d\n", pontosturisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade);
    printf("PIB per capita: %.2f reais/habitante\n", pibPerCapita);
    printf("Super Poder: %.2f\n", superPoder);

    printf("\nDados da Carta 02\n");

    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Cidade: %s", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosturisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: %.2f reais/habitante\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // Escolha dos dois atributos
    int atributo1, atributo2;
    atributo1 = escolherAtributo(1);

    // Garantir que o segundo atributo seja diferente do primeiro
    do {
        atributo2 = escolherAtributo(2);
        if (atributo2 == atributo1) {
            printf("Você já escolheu esse atributo. Escolha outro.\n");
        }
    } while (atributo2 == atributo1);

    // Comparação dos atributos
    int pontosCarta1 = 0, pontosCarta2 = 0;

    // Comparação do primeiro atributo
    switch (atributo1) {
        case 1:
            if (populacao > populacao2) pontosCarta1++;
            else if (populacao < populacao2) pontosCarta2++;
            break;
        case 2:
            if (area > area2) pontosCarta1++;
            else if (area < area2) pontosCarta2++;
            break;
        case 3:
            if (pib > pib2) pontosCarta1++;
            else if (pib < pib2) pontosCarta2++;
            break;
        case 4:
            if (pontosturisticos > pontosturisticos2) pontosCarta1++;
            else if (pontosturisticos < pontosturisticos2) pontosCarta2++;
            break;
        case 5:
            if (densidade < densidade2) pontosCarta1++;
            else if (densidade > densidade2) pontosCarta2++;
            break;
        case 6:
            if (pibPerCapita > pibPerCapita2) pontosCarta1++;
            else if (pibPerCapita < pibPerCapita2) pontosCarta2++;
            break;
        case 7:
            if (superPoder > superPoder2) pontosCarta1++;
            else if (superPoder < superPoder2) pontosCarta2++;
            break;
        default:
            printf("Atributo inválido!\n");
            return 1;
    }

    // Comparação do segundo atributo
    switch (atributo2) {
        case 1:
            if (populacao > populacao2) pontosCarta1++;
            else if (populacao < populacao2) pontosCarta2++;
            break;
        case 2:
            if (area > area2) pontosCarta1++;
            else if (area < area2) pontosCarta2++;
            break;
        case 3:
            if (pib > pib2) pontosCarta1++;
            else if (pib < pib2) pontosCarta2++;
            break;
        case 4:
            if (pontosturisticos > pontosturisticos2) pontosCarta1++;
            else if (pontosturisticos < pontosturisticos2) pontosCarta2++;
            break;
        case 5:
            if (densidade < densidade2) pontosCarta1++;
            else if (densidade > densidade2) pontosCarta2++;
            break;
        case 6:
            if (pibPerCapita > pibPerCapita2) pontosCarta1++;
            else if (pibPerCapita < pibPerCapita2) pontosCarta2++;
            break;
        case 7:
            if (superPoder > superPoder2) pontosCarta1++;
            else if (superPoder < superPoder2) pontosCarta2++;
            break;
        default:
            printf("Atributo inválido!\n");
            return 1;
    }

    // Exibição do resultado
    printf("\nResultado da Comparação:\n");
    printf("Carta 1: %d pontos\n", pontosCarta1);
    printf("Carta 2: %d pontos\n", pontosCarta2);

    if (pontosCarta1 > pontosCarta2) {
        printf("Carta 1 venceu!\n");
    } else if (pontosCarta1 < pontosCarta2) {
        printf("Carta 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}
