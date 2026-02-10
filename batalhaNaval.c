#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_NAVIO 3
#define TAM_HAB 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

int main() {

    int tabuleiro[TAM][TAM] = {0};

    /* ===============================
       COORDENADAS DOS NAVIOS
       =============================== */
    int linha_h = 6, coluna_h = 1;      // Horizontal →
    int linha_v = 1, coluna_v = 6;      // Vertical ↓
    int linha_d1 = 0, coluna_d1 = 0;    // Diagonal ↘
    int linha_d2 = 0, coluna_d2 = 9;    // Diagonal ↙

    /* ===============================
       INSERÇÃO DOS NAVIOS
       =============================== */
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linha_h][coluna_h + i] = NAVIO;

    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linha_v + i][coluna_v] = NAVIO;

    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linha_d1 + i][coluna_d1 + i] = NAVIO;

    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linha_d2 + i][coluna_d2 - i] = NAVIO;

    /* ==================================================
       MATRIZES DE HABILIDADE (5x5)
       ================================================== */

    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};

    int centro = TAM_HAB / 2;

    /* ===============================
       HABILIDADE CONE (apontando para baixo)
       =============================== */
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= centro - i && j <= centro + i) {
                cone[i][j] = 1;
            }
        }
    }

    /* ===============================
       HABILIDADE CRUZ
       =============================== */
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            }
        }
    }

    /* ===============================
       HABILIDADE OCTAEDRO (losango)
       =============================== */
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                octaedro[i][j] = 1;
            }
        }
    }

    /* ==================================================
       POSIÇÃO DAS HABILIDADES NO TABULEIRO
       ================================================== */

    int origem_cone_l = 4, origem_cone_c = 2;
    int origem_cruz_l = 7, origem_cruz_c = 7;
    int origem_octa_l = 3, origem_octa_c = 6;

    /* ===============================
       SOBREPOSIÇÃO DO CONE
       =============================== */
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int l = origem_cone_l + i - centro;
            int c = origem_cone_c + j - centro;

            if (l >= 0 && l < TAM && c >= 0 && c < TAM) {
                if (cone[i][j] == 1 && tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }
        }
    }

    /* ===============================
       SOBREPOSIÇÃO DA CRUZ
       =============================== */
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int l = origem_cruz_l + i - centro;
            int c = origem_cruz_c + j - centro;

            if (l >= 0 && l < TAM && c >= 0 && c < TAM) {
                if (cruz[i][j] == 1 && tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }
        }
    }

    /* ===============================
       SOBREPOSIÇÃO DO OCTAEDRO
       =============================== */
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int l = origem_octa_l + i - centro;
            int c = origem_octa_c + j - centro;

            if (l >= 0 && l < TAM && c >= 0 && c < TAM) {
                if (octaedro[i][j] == 1 && tabuleiro[l][c] == AGUA) {
                    tabuleiro[l][c] = HABILIDADE;
                }
            }
        }
    }

    /* ===============================
       EXIBIÇÃO FINAL DO TABULEIRO
       =============================== */
    printf("\nTABULEIRO COM HABILIDADES\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
