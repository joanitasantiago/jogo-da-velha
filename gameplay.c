#include <stdio.h>
#include "gameplay.h"
#include "print.h"

/* jogada do player X */
void player1Move(char board[BOARD_ROWS][BOARD_COLUMNS])
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
}

/* jogada do player O */
void player2Move(char board[BOARD_ROWS][BOARD_COLUMNS])
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
int checkWin(int controller, char board[BOARD_ROWS][BOARD_COLUMNS])
{
    controller = 0; // no win, keep with the loop in the main function
    for (int i = 0; i < 3; i++)
    {
        if (((board[i][0] == 'X') && (board[i][1] == 'X') && (board[i][2] == 'X')) || ((board[0][i] == 'X') && (board[1][i] == 'X') && (board[2][i] == 'X')))
        {
            controller = 1; // Player X win
        }
        if (((board[i][0] == 'O') && (board[i][1] == 'O') && (board[i][2] == 'O')) || ((board[0][i] == 'O') && (board[1][i] == 'O') && (board[2][i] == 'O')))
        {
            controller = 2; // Player O win
        }
    }
    if (((board[0][0] == 'X') && (board[1][1] == 'X') && (board[2][2] == 'X')) || ((board[2][0] == 'X') && (board[1][1] == 'X') && (board[0][2] == 'X')))
    {
        controller = 1; // Player X win
    }
    if (((board[0][0] == 'O') && (board[1][1] == 'O') && (board[2][2] == 'O')) || ((board[2][0] == 'O') && (board[1][1] == 'O') && (board[0][2] == 'O')))
    {
        controller = 2; // Player O win
    }
    return controller;
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