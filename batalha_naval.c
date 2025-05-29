#include <stdio.h>
int main(){

char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};
int tabuleiro[10][10];

printf(" ---- Batalha Naval ----\n\n");

// Preenchimento do tabuleiro com zeros
for (int i  = 0; i < 10; i++){
    for (int j = 0; j < 10; j++) {
            tabuleiro [i][j] = 0;
    }
}
// Navio na horizontal linha 3 e 8
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[5][6] = 3;
    tabuleiro[5][7] = 3;

// Navio na diagonal
    tabuleiro[3][0] = 3;
    tabuleiro[4][1] = 3;
    tabuleiro[5][2] = 3;
    tabuleiro[7][7] = 3;
    tabuleiro[8][6] = 3;
    tabuleiro[9][5] = 3;

// Imprimindo o cabeçalho horizontal
    printf("   ");
    for (int i = 0; i < 10; i++){
        printf("%c ", linha[i]);
    }
    printf("\n");

// Imprime linhas numeradas e o conteúdo do tabuleiro
    for (int i = 0; i < 10; i++){
        printf("%2d ",i + 1);

        for(int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
       
    }
        printf("-----------------------\n");
    return 0;
}