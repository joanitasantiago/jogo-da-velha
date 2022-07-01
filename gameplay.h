#ifndef GAMEPLAY_H
#define GAMEPLAY_H

/* ESTRUTURAS, CONSTANTES, FUNÇÕES E PROCEDIMENTOS QUE ENVOLVEM A JOGABILIDADE */

/* Define o tamanho das linhas e colunas do tabuleiro */
#define BOARD_ROWS 3
#define BOARD_COLUMNS 3

/* jogada do player X */
void player1Move(int *moves_counter, char board[BOARD_ROWS][BOARD_COLUMNS]);

/* jogada do player O */
void player2Move(int *moves_counter, char board[BOARD_ROWS][BOARD_COLUMNS]);

/* checa se a jogada foi válida */
int checkValidMove(int row, int column, char board[BOARD_ROWS][BOARD_COLUMNS]);

/* checa se houve vitória em alguma linha, coluna ou diagonal */
void checkWin(int *player1score, int *player2score, int *loop_control, int moves_counter, char board[BOARD_ROWS][BOARD_COLUMNS]);

/* checa se houve empate */
void checkDraw(int moves_counter, int *loop_control, int *draws);

/* Inicializa a matriz com espaços*/
void fillBoardWithSpace(char board[BOARD_ROWS][BOARD_COLUMNS]);

#endif