#include <stdio.h>

int main()
{

    char estado, estado2;
    char codigo[4], codigo2[4];
    char cidade[50], cidade2[50];
    int populacao, populacao2;
    float area, area2;
    float pib, pib2;
    int pontosturisticos, pontosturisticos2;

    printf("Insira as informações da Carta 01\n");

    printf("Escolha a letra entre A a H para representar o estado:\n");
    scanf(" %c", &estado);
    printf("Escolha um codigo entre A01 a A04:\n");
    scanf(" %3s", codigo);
    printf("Insina o nome da cidade:\n");
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

    printf("Insira as informações da Carta 02\n");
    
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

    printf("Dados da Carta 01\n");

    printf("Estado: %c\n", estado);
    printf("Codigo: %s\n", codigo);
    printf("Cidade: %s", cidade);

    printf("População: %d\n", populacao);
    printf("Área: %.2f\n", area);
    printf("PIB: %.2f\n", pib);
    printf("Pontos Turísticos: %d\n", pontosturisticos);

    printf("Dados da Carta 02\n");

    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Cidade: %s", cidade2);

    printf("População: %d\n", populacao2);
    printf("Área: %.2f\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosturisticos2);

    return 0;
}
