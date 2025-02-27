#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CARTAS 2

// Estrutura que representa uma carta
typedef struct {
    char nome[30];
    int ataque;
    int defesa;
    int velocidade;
} Carta;

// Função para comparar cartas com base em um único atributo
void compararCartasUmAtributo(Carta cartas[], int atributo) {
    if (atributo == 1) { // Ataque
        if (cartas[0].ataque > cartas[1].ataque) {
            printf("%s vence com ataque %d!\n", cartas[0].nome, cartas[0].ataque);
        } else if (cartas[0].ataque < cartas[1].ataque) {
            printf("%s vence com ataque %d!\n", cartas[1].nome, cartas[1].ataque);
        } else {
            printf("Empate em ataque!\n");
        }
    } else if (atributo == 2) { // Defesa
        if (cartas[0].defesa > cartas[1].defesa) {
            printf("%s vence com defesa %d!\n", cartas[0].nome, cartas[0].defesa);
        } else if (cartas[0].defesa < cartas[1].defesa) {
            printf("%s vence com defesa %d!\n", cartas[1].nome, cartas[1].defesa);
        } else {
            printf("Empate em defesa!\n");
        }
    } else if (atributo == 3) { // Velocidade
        if (cartas[0].velocidade > cartas[1].velocidade) {
            printf("%s vence com velocidade %d!\n", cartas[0].nome, cartas[0].velocidade);
        } else if (cartas[0].velocidade < cartas[1].velocidade) {
            printf("%s vence com velocidade %d!\n", cartas[1].nome, cartas[1].velocidade);
        } else {
            printf("Empate em velocidade!\n");
        }
    } else {
        printf("Atributo inválido!\n");
    }
}

// Função para comparar cartas com múltiplos atributos
void compararCartasMultiAtributos(Carta cartas[]) {
    int atributo;
    printf("Escolha um atributo para comparação:\n");
    printf("1. Ataque\n2. Defesa\n3. Velocidade\n");
    scanf("%d", &atributo);
    
    if (atributo == 1) {
        if (cartas[0].ataque > cartas[1].ataque) {
            printf("%s vence com ataque %d!\n", cartas[0].nome, cartas[0].ataque);
        } else if (cartas[0].ataque < cartas[1].ataque) {
            printf("%s vence com ataque %d!\n", cartas[1].nome, cartas[1].ataque);
        } else {
            printf("Empate em ataque! Comparando defesa...\n");
            if (cartas[0].defesa > cartas[1].defesa) {
                printf("%s vence com defesa %d!\n", cartas[0].nome, cartas[0].defesa);
            } else if (cartas[0].defesa < cartas[1].defesa) {
                printf("%s vence com defesa %d!\n", cartas[1].nome, cartas[1].defesa);
            } else {
                printf("Empate total!\n");
            }
        }
    } else if (atributo == 2) {
        if (cartas[0].defesa > cartas[1].defesa) {
            printf("%s vence com defesa %d!\n", cartas[0].nome, cartas[0].defesa);
        } else if (cartas[0].defesa < cartas[1].defesa) {
            printf("%s vence com defesa %d!\n", cartas[1].nome, cartas[1].defesa);
        } else {
            printf("Empate em defesa! Comparando ataque...\n");
        }
    }
}