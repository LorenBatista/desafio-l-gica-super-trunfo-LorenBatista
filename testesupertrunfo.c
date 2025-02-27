#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIDADES 10

// Estrutura que representa uma carta de cidade
typedef struct {
    char nome[30];
    char estado[30];
    int codigo;
    int populacao;
    float area;
    float pib_per_capita;
    int pontos_turisticos;
} Carta;

// Função para cadastrar cartas
void cadastrarCartas(Carta *cidades, int *num_cidades) {
    if (*num_cidades >= MAX_CIDADES) {
        printf("Limite de cidades atingido!\n");
        return;
    }
    
    printf("Cadastro da Cidade:\n");
    printf("Nome: ");
    scanf("%s", cidades[*num_cidades].nome);
    printf("Estado: ");
    scanf("%s", cidades[*num_cidades].estado);
    printf("Código da carta: ");
    scanf("%d", &cidades[*num_cidades].codigo);
    printf("População: ");
    scanf("%d", &cidades[*num_cidades].populacao);
    printf("Área Territorial (km²): ");
    scanf("%f", &cidades[*num_cidades].area);
    printf("PIB per capita: ");
    scanf("%f", &cidades[*num_cidades].pib_per_capita);
    printf("Pontos Turísticos: ");
    scanf("%d", &cidades[*num_cidades].pontos_turisticos);
    
    (*num_cidades)++;
    printf("Cidade cadastrada com sucesso!\n");
}

// Função para comparar cartas
void compararCartas(Carta *cidades, int num_cidades) {
    if (num_cidades < 2) {
        printf("É necessário cadastrar pelo menos duas cidades para comparação.\n");
        return;
    }

    int escolha1, escolha2, atributo;
    printf("Escolha a primeira cidade (0 a %d): ", num_cidades - 1);
    scanf("%d", &escolha1);
    printf("Escolha a segunda cidade (0 a %d): ", num_cidades - 1);
    scanf("%d", &escolha2);

    printf("Escolha o atributo para comparação:\n");
    printf("1. População\n2. Área\n3. PIB per capita\n4. Pontos Turísticos\n");
    scanf("%d", &atributo);

    switch (atributo) {
        case 1: // População
            printf("Comparando %s e %s pela população:\n", cidades[escolha1].nome, cidades[escolha2].nome);
            if (cidades[escolha1].populacao > cidades[escolha2].populacao) {
                printf("%s vence com %d pessoas!\n", cidades[escolha1].nome, cidades[escolha1].populacao);
            } else if (cidades[escolha1].populacao < cidades[escolha2].populacao) {
                printf("%s vence com %d pessoas!\n", cidades[escolha2].nome, cidades[escolha2].populacao);
            } else {
                printf("Empate em população!\n");
            }
            break;
        case 2: // Área
            printf("Comparando %s e %s pela área:\n", cidades[escolha1].nome, cidades[escolha2].nome);
            if (cidades[escolha1].area > cidades[escolha2].area) {
                printf("%s vence com %.2f km²!\n", cidades[escolha1].nome, cidades[escolha1].area);
            } else if (cidades[escolha1].area < cidades[escolha2].area) {
                printf("%s vence com %.2f km²!\n", cidades[escolha2].nome, cidades[escolha2].area);
            }
    }
}
           