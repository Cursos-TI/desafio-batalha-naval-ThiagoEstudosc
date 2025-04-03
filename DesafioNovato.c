#include <stdio.h>

int main() {

    //Declarando uma matriz bidimensional 10x10 com preenchimento 0 como água
    int Tabuleiro[10][10] = {0};

    //Definindo o tamanho dos navios
    int tamanhodoNavio = 3;

    //Coordenadas iniciais dos navios
    int HorizontalX = 2, HorizontalY = 4;
    int VerticalX = 7, VerticalY = 8;

    //Posicionando o navio na horizontal
    for (int x = 0; x < tamanhodoNavio; x++) {
        Tabuleiro[HorizontalX][HorizontalY + x] = 3;
    }

    //Posicionando o navio na vertical
    for (int y = 0; y < tamanhodoNavio; y++) {
        Tabuleiro[VerticalX + y][VerticalY] = 3; //Incrementa a linha
    }

    //Exibindo o tabuleiro no terminal com letras como linhas e números como colunas
    printf("   "); //Espaço inicial para alinhar com os números das colunas
    for (int i = 1; i < 11; i++) {
        printf("%d ", i); //Exibindo os números das colunas (0-9)
    }
    printf("\n");

    for (int x = 0; x < 10; x++) {
        printf("%c  ", 'A' + x); //Exibindo as letras das linhas (A-J)
        for (int y = 0; y < 10; y++) {
            printf("%d ", Tabuleiro[x][y]); //Exibindo os valores do tabuleiro
        }
        printf("\n");
    }

    return 0;
}