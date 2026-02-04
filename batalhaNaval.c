#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TAM 10
#define TAM_NAVIO 3

int main() {
    // Nível Novato - Posicionamento dos Navios
    int tabuleiro[TAM][TAM] = {0};

    // Vetores que representam os navios
    int navio_horizontal[TAM_NAVIO] = {3, 3, 3};
    int navio_vertical[TAM_NAVIO]   = {3, 3, 3};

    // Coordenadas iniciais
    int linha_h = 3, coluna_h = 3; // horizontal
    int linha_v = 5, coluna_v = 8; // vertical

    //  Validação do navio horizontal 
    if (coluna_h + TAM_NAVIO > TAM) {
        printf("Erro: navio horizontal fora do tabuleiro\n");
        return 1;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_h][coluna_h + i] != 0) {
            printf("Erro: sobreposicao no navio horizontal\n");
            return 1;
        }
    }

    // Inserção do navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
    }

    //  Validação do navio vertical 
    if (linha_v + TAM_NAVIO > TAM) {
        printf("Erro: navio vertical fora do tabuleiro\n");
        return 1;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_v + i][coluna_v] != 0) {
            printf("Erro: sobreposicao no navio vertical\n");
            return 1;
        }
    }

    // Inserção do navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

    // Exibição do tabuleiro 
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%3d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
