#ifndef GAMEPLAY_H
#define GAMEPLAY_H

/* ESTRUTURAS, CONSTANTES, FUNÇÕES E PROCEDIMENTOS QUE ENVOLVEM A JOGABILIDADE */

/* Define o tamanho das linhas e colunas do tabuleiro */
#define BOARD_ROWS 3
#define BOARD_COLUMNS 3

/* jogada do player X */
void player1Move(char board[BOARD_ROWS][BOARD_COLUMNS]);

/* jogada do player O */
void player2Move(char board[BOARD_ROWS][BOARD_COLUMNS]);

/* checa se a jogada foi válida */
int checkValidMove(int row, int column, char board[BOARD_ROWS][BOARD_COLUMNS]);

/* checa se houve vitória em alguma linha, coluna ou diagonal */
int checkWin(int controller, char board[BOARD_ROWS][BOARD_COLUMNS]);

/* Inicializa a matriz com espaços*/
void fillBoardWithSpace(char board[BOARD_ROWS][BOARD_COLUMNS]);

#endif