#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {

    int tabuleiro[TAM][TAM] = {0};

    /* ===============================
       Coordenadas iniciais dos navios
       =============================== */
    // Horizontal →
    int linha_h = 6, coluna_h = 1;

    // Vertical ↓  (mudou a coluna!)
    int linha_v = 1, coluna_v = 6;

    // Diagonal principal ↘
    int linha_d1 = 0, coluna_d1 = 0;

    // Diagonal secundária ↙
    int linha_d2 = 0, coluna_d2 = 9;


    /* ===============================
       NAVIO HORIZONTAL
       =============================== */
    if (coluna_h + TAM_NAVIO > TAM) {
        printf("Erro: navio horizontal fora do tabuleiro\n");
        return 1;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_h][coluna_h + i] != AGUA) {
            printf("Erro: sobreposicao no navio horizontal\n");
            return 1;
        }
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = NAVIO;
    }

    /* ===============================
       NAVIO VERTICAL
       =============================== */
    if (linha_v + TAM_NAVIO > TAM) {
        printf("Erro: navio vertical fora do tabuleiro\n");
        return 1;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_v + i][coluna_v] != AGUA) {
            printf("Erro: sobreposicao no navio vertical\n");
            return 1;
        }
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = NAVIO;
    }

    /* ===============================
       NAVIO DIAGONAL PRINCIPAL ↘
       =============================== */
    if (linha_d1 + TAM_NAVIO > TAM || coluna_d1 + TAM_NAVIO > TAM) {
        printf("Erro: navio diagonal principal fora do tabuleiro\n");
        return 1;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_d1 + i][coluna_d1 + i] != AGUA) {
            printf("Erro: sobreposicao no navio diagonal principal\n");
            return 1;
        }
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_d1 + i][coluna_d1 + i] = NAVIO;
    }

    /* ===============================
       NAVIO DIAGONAL SECUNDÁRIA ↙
       =============================== */
    if (linha_d2 + TAM_NAVIO > TAM || coluna_d2 - (TAM_NAVIO - 1) < 0) {
        printf("Erro: navio diagonal secundaria fora do tabuleiro\n");
        return 1;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha_d2 + i][coluna_d2 - i] != AGUA) {
            printf("Erro: sobreposicao no navio diagonal secundaria\n");
            return 1;
        }
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_d2 + i][coluna_d2 - i] = NAVIO;
    }

    /* ===============================
       EXIBIÇÃO DO TABULEIRO
       =============================== */
    printf("\nTABULEIRO BATALHA NAVAL\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
