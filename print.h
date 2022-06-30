#ifndef PRINT_H
#define PRINT_H

#include "gameplay.h"

/* PROCEDIMENTOS QUE ENVOLVEM SAÍDA DE DADOS DA TELA DO USUÁRIO */

/* Imprime uma quantidade deseja de asteríscos na horizontal */
void printAsterisks(int number_of_asterisks);

/* Imprime tela de boas-vindas com o texto desejado */
void printWelcomeScreen();

/* Imprime o tabuleiro do jogo */
void printBoard(char board[BOARD_ROWS][BOARD_COLUMNS]);

/* Imprime o placar do jogo */
void printGameScore(int playerXWins, int playerOwins, int draws);

/* Imprime as regras estabelecidas */
void printRules();

/* Imprime uma mensagem e pausa a tela até que o usuário aperte alguma tecla */
void pause();

#endif

