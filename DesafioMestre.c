#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10 //Dimensão do tabuleiro
#define NAVIO 3 //Tamanho do navio
#define AREA_GEOMETRICA 5 //Tamanho da aréa para as formas geometricas(Cone, Cruz e octaedro)

int main() {

    //Função para inicializar o tabuleiro com água (0)
    int inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
        for (int x = 0; x < TAMANHO; x++) {
            for (int y = 0; y < TAMANHO; y++) {
                tabuleiro[x][y] = 0; //Representa 0 como água
            }
        }
    }
    
    //Função para validar se uma posição é válida para o navio
    int validarPosicao(int tabuleiro[TAMANHO][TAMANHO], int x, int y, int tamanho, int direcaoX, int direcaoY) {
        for (int z = 0; z < tamanho; z++) {
            int novoX = x + z * direcaoX;
            int novoY = y + z * direcaoY;

            if (novoX < 0 || novoX >= TAMANHO || novoY < 0 || novoY >= TAMANHO || tabuleiro[novoX][novoY] != 0) {
            }
        }
    }

    //Função para posicionar um navio no tabuleiro
    int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int x, int y, int tamanho, int direcaoX, int direcaoY) {
        if (!validarPosicao(tabuleiro, x, y, tamanho, direcaoX, direcaoY)) {
        printf("Posição inválida para o navio.\n");
    }
    for (int z = 0; z < tamanho; z++) {
        tabuleiro[x + z * direcaoX][y + z * direcaoY] = NAVIO; //Marca a posição com 3
        }
    }

    //Parte das funções do Cone , Cruz e Octaedro
    //Cone
    int exibirmatrizc(int matriz[3][5]){
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 5; y++) {
                printf("%2d ", matriz[x][y]);
            }
            printf("\n");
        }
        printf("\n");
    }

    //Cruz e Octaedro
    int exibirMatriz(int matriz[5][5]) {
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                printf("%2d ", matriz[x][y]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    //Função para Construir o Cone
    int criarCone(int Construcao[3][5]) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 5; y++) {
                Construcao[x][y] = (y >= 2 - x && y <= 2 + x) ? 1 : 0;
            }
        }
    }
    
    //Função para Construir a Cruz
    int criarCruz(int Construcao[5][5]) {
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                Construcao[x][y] = (x == 2 || y == 2) ? 1 : 0;
            }
        }
    }
    
    //Função para Construir o Octaedro
    int criarOctaedro(int Construcao[5][5]) {
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                Construcao[x][y] = (abs(2 - y) + abs(2 - x) <= 2) ? 1 : 0;
            }
        }
    }
    
    //Função para aplicar a Construcao no tabuleiro
    int aplicarConstrucao(int tabuleiro[TAMANHO][TAMANHO], int Construcao[5][5], int origemX, int origemY) {
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                int x = origemX + x - 2;
                int y = origemY + y - 2;
                if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO && Construcao[x][y] == 1) {
                    tabuleiro[x][y] = AREA_GEOMETRICA; //Marca como área afetada
                }
            }
        }
    }

    //Função para exibir o tabuleiro no console com linhas e colunas rotuladas
    int exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
        printf("   "); //Espaço inicial para alinhar as colunas
    for (int y = 1; y <= TAMANHO; y++) {
        printf("%2d ", y); // Exibe os números das colunas
    }
    printf("\n");

    for (int x = 0; x < TAMANHO; x++) {
        printf("%c  ", 'A' + x); //Exibe a letra da linha
        for (int y = 0; y < TAMANHO; y++) {
            printf("%2d ", tabuleiro[x][y]);
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

    //Partes da função das formas geometricas
    //Matriz 3 por 5 para o cone
    int matriz [3][5];

    //Matrizes 5 por 5 para a cruz e octaedro
    int Matriz[5][5];

    //Criar e exibir a matriz do Cone
    printf("Matriz do Cone: \n");
    criarCone(matriz);
    exibirmatrizc(matriz);

    //Criar e exibir a matriz da Cruz
    printf("Matriz da Cruz: \n");
    criarCruz(Matriz);
    exibirMatriz(Matriz);

    //Criar e exibir a matriz do Octaedro
    printf("Matriz do Octaedro: \n");
    criarOctaedro(Matriz);
    exibirMatriz(Matriz);

    //Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}