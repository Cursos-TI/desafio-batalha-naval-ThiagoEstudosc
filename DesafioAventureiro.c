#include <stdio.h>

#define TAMANHO 10 //Dimensão do tabuleiro
#define NAVIO 3 //Tamanho do navio

int main() {

    //Função para inicializar o tabuleiro com água (0)
    int inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0; //Representa 0 como água
        }
    }
}

    //Função para validar se uma posição é válida para o navio
    int validarPosicao(int tabuleiro[TAMANHO][TAMANHO], int x, int y, int tamanho, int direcaoX, int direcaoY) {
    for (int i = 0; i < tamanho; i++) {
        int novoX = x + i * direcaoX;
        int novoY = y + i * direcaoY;

        if (novoX < 0 || novoX >= TAMANHO || novoY < 0 || novoY >= TAMANHO || tabuleiro[novoX][novoY] != 0) {
        }
    }
    return 1; //Posição válida
}

    //Função para posicionar um navio no tabuleiro
    int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int x, int y, int tamanho, int direcaoX, int direcaoY) {
    if (!validarPosicao(tabuleiro, x, y, tamanho, direcaoX, direcaoY)) {
        printf("Posição inválida para o navio.\n");
    }

    for (int i = 0; i < tamanho; i++) {
        tabuleiro[x + i * direcaoX][y + i * direcaoY] = NAVIO; // Marca a posição com 3
    }
}

    //Função para exibir o tabuleiro no console com linhas e colunas rotuladas
    int exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("   "); //Espaço inicial para alinhar as colunas
    for (int j = 1; j <= TAMANHO; j++) {
        printf("%2d ", j); // Exibe os números das colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%c  ", 'A' + i); //Exibe a letra da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    //Posiciona dois navios horizontais ou verticais
    posicionarNavio(tabuleiro, 2, 4, NAVIO, 0, 1); //Horizontal
    posicionarNavio(tabuleiro, 7, 8, NAVIO, 1, 0); //Vertical

    // Posiciona dois navios diagonais
    posicionarNavio(tabuleiro, 1, 1, NAVIO, 1, 1);  //Diagonal crescente
    posicionarNavio(tabuleiro, 8, 2, NAVIO, -1, 1); //Diagonal decrescente

    //Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}