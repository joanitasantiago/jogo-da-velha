#include <stdio.h>
#include "gameplay.h"
#include "print.h"

/* jogada do player X */
void player1Move(int *moves_counter, char board[BOARD_ROWS][BOARD_COLUMNS])
{
    int new_row, new_column, position, validation;
    printf("JOGADOR X: Informe a [LINHA] e a [COLUNA] que deseja fazer sua jogada >>\t");
    scanf(" %d %d", &new_row, &new_column);
    validation = checkValidMove(new_row, new_column, board);
    while (validation != 1)
    {
        switch (validation)
        {
        case 2:
            printf("Posicao invalida. Tente novamente!\t>> ");
            scanf(" %d %d", &new_row, &new_column);
            validation = checkValidMove(new_row, new_column, board);
            break;
        case 3:
            printf("Essa posicao ja esta ocupada!\t>> ");
            scanf(" %d %d", &new_row, &new_column);
            validation = checkValidMove(new_row, new_column, board);
            break;
        }
    }
    board[new_row][new_column] = 'X';
    *moves_counter = *moves_counter + 1;
}

/* jogada do player O */
void player2Move(int *moves_counter, char board[BOARD_ROWS][BOARD_COLUMNS])
{
    int new_row, new_column, validation;
    printf("JOGADOR O: Informe a [LINHA] e a [COLUNA] que deseja fazer sua jogada >>\t");
    scanf(" %d %d", &new_row, &new_column);
    validation = checkValidMove(new_row, new_column, board);
    while (validation != 1)
    {
        switch (validation)
        {
        case 2:
            printf("Posicao invalida. Tente novamente!\t>> ");
            scanf(" %d %d", &new_row, &new_column);
            validation = checkValidMove(new_row, new_column, board);
            break;
        case 3:
            printf("Essa posicao ja esta ocupada!\t>> ");
            scanf(" %d %d", &new_row, &new_column);
            validation = checkValidMove(new_row, new_column, board);
            break;
        }
    }
    board[new_row][new_column] = 'O';
    *moves_counter = *moves_counter + 1;
}

/* checa se a jogada foi válida */
int checkValidMove(int row, int column, char board[BOARD_ROWS][BOARD_COLUMNS])
{
    int check;

    check = 1; // valid

    if ((row < 0) || (row > 2) || (column < 0) || (column > 2))
    {
        check = 2; // invalid position
    }
    if (board[row][column] != ' ')
    {
        check = 3; // position already in use
    }
    return check;
}

/* checa se houve vitória em alguma linha, coluna ou diagonal */
void checkWin(int *player1score, int *player2score, int *loop_control, int moves_counter, char board[BOARD_ROWS][BOARD_COLUMNS])
{
    if (moves_counter > 4) /* só verifica se tiver o mínimo de 4 jogadas */
    {
        for (int i = 0; i < 3; i++) /*checa se houve vitória por linha ou coluna*/
        {
            if (((board[i][0] == 'X') && (board[i][1] == 'X') && (board[i][2] == 'X')) || ((board[0][i] == 'X') && (board[1][i] == 'X') && (board[2][i] == 'X')))
            {
                printf("Vitoria do player X!");
                *player1score = *player1score + 1;
                *loop_control = 1;
            }
            if (((board[i][0] == 'O') && (board[i][1] == 'O') && (board[i][2] == 'O')) || ((board[0][i] == 'O') && (board[1][i] == 'O') && (board[2][i] == 'O')))
            {
                printf("Vitoria do player O!");
                *player2score = *player2score + 1;
                *loop_control = 1;
            }
        }
        /* checa se houve vitória nas diagonais */
        if (((board[0][0] == 'X') && (board[1][1] == 'X') && (board[2][2] == 'X')) || ((board[2][0] == 'X') && (board[1][1] == 'X') && (board[0][2] == 'X')))
        {
            printf("Vitoria do player X!");
            *player1score = *player1score + 1;
            *loop_control = 1;
        }
        if (((board[0][0] == 'O') && (board[1][1] == 'O') && (board[2][2] == 'O')) || ((board[2][0] == 'O') && (board[1][1] == 'O') && (board[0][2] == 'O')))
        {
            printf("Vitoria do player O!");
            *player2score = *player2score + 1;
            *loop_control = 1;
        }
    }
}

/* checa se houve empate */
void checkDraw(int moves_counter, int *loop_control, int *draws)
{
    if (moves_counter == (BOARD_ROWS * BOARD_COLUMNS))
    {
        printf("\nDEU VELHA!");
        *draws = *draws + 1;
        *loop_control = 1;
    }
}

/* Inicializa a matriz com espaços*/
void fillBoardWithSpace(char board[BOARD_ROWS][BOARD_COLUMNS])
{
    for (int i = 0; i < BOARD_ROWS; i++)
    {
        for (int j = 0; j < BOARD_COLUMNS; j++)
        {
            board[i][j] = ' ';
        }
    }
}