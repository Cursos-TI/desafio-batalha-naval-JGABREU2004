#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

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

int main() {

    char coluna[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[10][10];

    // iniciando o tabuleiro com 0 (água) e 3 (návio)

    printf("  ## Tabuleiro Batalha Naval ##\n");
    printf("\n");

    for (int i = 0; i < 10; i++) { // linhas
        for (int j = 0; j < 10; j++) // colunas
        { tabuleiro[i][j] = 0;}        
    }
    for (int i = 5; i < 5 + 3; i++) { // colocação do navio vertical
        if (tabuleiro [i][6] == 0) {   
            tabuleiro[i][6] = 3;
        } else { printf("Posição já ocupada\n");
        }
    }   
    for (int j = 3; j < 3 + 3; j++) { // colocação do navio na horizontal
        if (tabuleiro [3][j] == 0) {
            tabuleiro[3][j] = 3;
        } else { printf("Posição já ocupada\n");
        }
    }   
    for (int i = 0; i < 3 ; i++) { // colocação do navio na diagonal
        if (tabuleiro[3 + i][i] == 0) {
            tabuleiro[3 + i][i] = 3;
        } else { printf("Posição já ocupada\n");
        }
    }
    for (int i = 0; i < 3 ; i++) { // colocação do navio na diagonal
        if (tabuleiro[i][5 - i] == 0) {
            tabuleiro[i][5 - i] = 3;
        } else { printf("Posição já ocupada\n");
        }
    }
    // forma do cone, usando o numero 1
    // definir a base da linha, coluna e a altura do cone

    int baseLinha = 9;
    int baseColuna = 2;
    int alturaCone = 3;

    for (int i = 0; i < alturaCone; i++) {
        int linha = baseLinha - i;
        int inicio = baseColuna - i;
        int fim = baseColuna + 1;

        if (linha < 0) break;
        if (inicio < 0) inicio = 0;
        if (fim > 9) fim = 9;

        for (int j = inicio; j < fim; j++) {
            if (tabuleiro[linha][j] == 0) {
                tabuleiro [linha][j] = 1; // numero para forma do cone
            }
        }
    }

    // cabeçalho
    printf("   "); // espaço no canto superior
    
    for (int j = 0; j < 10; j++) {
        printf(" %c ", coluna[j]); // impressão coluna
    }   printf("\n");
    
    // impressão do tabuleiro
    for (int i = 0; i < 10; i++) { 
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        } printf ("\n");
    } 
    return 0; // fim do código
}