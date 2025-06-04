#include <stdio.h>
#include <stdlib.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define TAM_CONE 3

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];
    int cone[TAM_CONE][TAM_HABILIDADE];

    int i, j;

    int origemLinha, origemColuna;
    int centro = TAM_HABILIDADE / 2;

    //  tabuleiro com água (0)
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // === Posiciona os navios (valor 4)
    for (j = 1; j <= 3; j++) {
        tabuleiro[2][j] = 4;  // navio horizontal
    }

    for (i = 0; i < 3; i++) {
        tabuleiro[i][i] = 4;  // diagonal 
    }

    for (i = 0; i < 3; i++) {
        tabuleiro[i][9 - i] = 4;  // diagonal 
    }

    //  Cone 
    for (i = 0; i < TAM_CONE; i++) {
    for (j = 0; j < TAM_HABILIDADE; j++) {
        if (j >= centro - i && j <= centro + i)
            cone[i][j] = 1;
        else
            cone[i][j] = 0;

        }
    }

    origemLinha = 7;
    origemColuna = 7;

    for (i = 0; i < TAM_CONE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = origemLinha + (i - centro);
            int colunaTab = origemColuna + (j - centro);
            if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO && colunaTab >= 0 && colunaTab < TAM_TABULEIRO) {
                if (cone[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == 0)
                    tabuleiro[linhaTab][colunaTab] = 5;
            }
        }
    }

    // Cruz 
    for (i = 0; i < TAM_HABILIDADE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {
            if (i == centro || j == centro)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }

    origemLinha = 2;
    origemColuna = 5;

    for (i = 0; i < TAM_HABILIDADE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = origemLinha + (i - centro);
            int colunaTab = origemColuna + (j - centro);
            if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO && colunaTab >= 0 && colunaTab < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == 0)
                    tabuleiro[linhaTab][colunaTab] = 5;
            }
        }
    }

    //  Octaedro 
    for (i = 0; i < TAM_HABILIDADE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }

    origemLinha = 5;
    origemColuna = 2;

    for (i = 0; i < TAM_HABILIDADE; i++) {
        for (j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = origemLinha + (i - centro);
            int colunaTab = origemColuna + (j - centro);
            if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO && colunaTab >= 0 && colunaTab < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colunaTab] == 0)
                    tabuleiro[linhaTab][colunaTab] = 5;
            }
        }
    }

    // EXIBE O TABULEIRO
    printf("    ");
    for (j = 0; j < TAM_TABULEIRO; j++) {
        printf("%c ", 'A' + j);  // Letras de A a J
    }
    printf("\n");

    for (i = 0; i < TAM_TABULEIRO; i++) {
        if (i + 1 < 10)
            printf(" %d  ", i + 1);  // Números 1 a 9 com alinhamento
        else
            printf("%d  ", i + 1);   // Número 10

        for (j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) printf("0 ");
            else if (tabuleiro[i][j] == 4) printf("3 ");
            else if (tabuleiro[i][j] == 5) printf("* ");
        }
        printf("\n");
    }

    return 0;
}
