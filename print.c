#include <stdio.h>
#include "print.h"

/* Imprime uma quantidade deseja de asteríscos na horizontal */
void printAsterisks(int number_of_asterisks)
{
    printf("\n");
    for (int i = 1; i <= number_of_asterisks; i++)
    {
        printf("*");
    }
    printf("\n");
}

/* Imprime tela de boas-vindas com o texto desejado */
void printWelcomeScreen()
{
    printf("\n");
    printAsterisks(41);
    printf("*\t                          \t*\n");
    printf("*\tBEM-VINDO AO JOGO DA VELHA\t*\n");
    printf("*\t                          \t*\n");
    printAsterisks(41);
    printf("\n");
}

/* Imprime o tabuleiro do jogo */
void printBoard(int rows, int columns, char board[rows][columns])
{
    printf("\n\t[0] [1] [2] \n\n"); /* imprime uma barra superior com as posições X */
    for (int i = 0; i < rows; i++)
    {
        printf("[%d]\t", i); /* imprime uma barra lateral com as posições Y*/
        for (int j = 0; j < columns; j++)
        {
            if (((i != 2) && (j != 2)) || ((i == 2) && (j < 2)))
            {
                printf(" %c |", board[i][j]); /* acrescenta a barra vertical do meio */
            }
            if (((j == 2) && (i < 2)) || ((i == 2) && (j == 2)))
            {
                printf(" %c ", board[i][j]);
            }
        }
        if (i < 2)
        {
            printf("\n\t-----------"); /* acrescenta a barra horizontal do meio */
        }
        printf("\n");
    }
    printf("\n");
}

/* Imprime o placar do jogo */
void printGameScore(int playerXWins, int playerOwins, int draws)
{
    printf("\n");
    printAsterisks(25);
    printf("*  JOGADOR X: %d pontos  *\n", playerXWins);
    printf("*  JOGADOR O: %d pontos  *\n", playerOwins);
    printf("*  EMPATES #: %d         *", draws);
    printAsterisks(25);
    printf("\n");
}

/* Imprime as regras estabelecidas */
void printRules()
{
    printAsterisks(25);
    printf("\n> lalallalalala\n");
    printf("> blablablablabla\n");
    printf("> lalallalalala\n");
    printf("> lalallalalala\n");
    printAsterisks(25);
}

/* Imprime uma mensagem e pausa a tela até que o usuário aperte alguma tecla */
void pause()

{
    printf("\n<PRESSIONE ENTER PARA CONTINUAR>\n");
    getchar();
    getchar();
}