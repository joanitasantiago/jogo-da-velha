#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>
#include <time.h>

// CONSTANTS
#define BOARD_ROWS 3
#define BOARD_COLUMNS 3

// FUNCTIONS DECLARATIONS
void printAsterisks(int number_of_asterisks);
void printWelcomeScreen();
void printBoard(char board[BOARD_ROWS][BOARD_COLUMNS]);
void printGameScore(int playerXWins, int playerOwins, int draws);
void printRules();
void pause();
void fillBoardWithSpace(char board[BOARD_ROWS][BOARD_COLUMNS]);
void player1Move(char board[BOARD_ROWS][BOARD_COLUMNS]);
void player2Move(char board[BOARD_ROWS][BOARD_COLUMNS]);
int checkValidMove(int row, int column, char board[BOARD_ROWS][BOARD_COLUMNS]);
int checkWin(int controller, char board[BOARD_ROWS][BOARD_COLUMNS]);

int main(int argc, char const *argv[])
{
    // * * * Variables * * *
    char game_board[BOARD_ROWS][BOARD_COLUMNS];
    int menu_option, max_moves = BOARD_ROWS * BOARD_COLUMNS, moves_counter = 0, player_x_wins = 0, player_o_wins = 0, draws = 0, score_controller = 0;

    // * * * Language * * *
    setlocale(LC_ALL, "");

    // * * * Game * * *
    printWelcomeScreen();
    do
    {
        fillBoardWithSpace(game_board);
        printf("1.Jogar\n2.Regras\n3.Zerar Placar\n0. Sair\n>>");
        scanf(" %d", &menu_option);
        switch (menu_option)
        {
        case 1:
            printf("\n>>> Vamos comecar:\n\n");
            printBoard(game_board);
            do
            {
                player1Move(game_board);
                system("cls");
                printBoard(game_board);
                moves_counter++;
                if (moves_counter > 4) // só pode ter uma vitória com no mínimo quatro jogadas
                {
                    score_controller = checkWin(score_controller, game_board);
                    if (score_controller == 1)
                    {
                        printf("Vitória do player X!");
                        player_x_wins++;
                        break;
                    }
                    if (score_controller == 2)
                    {
                        printf("Vitória do player O!");
                        player_x_wins++;
                        break;
                    }
                    if (moves_counter == 9)
                    {
                        break;
                    }
                }
                player2Move(game_board);
                system("cls");
                printBoard(game_board);
                moves_counter++;
                if (moves_counter > 4) // só pode ter uma vitória com no mínimo quatro jogadas
                {
                    score_controller = checkWin(score_controller, game_board);
                    if (score_controller == 1)
                    {
                        printf("Vitória do player X!");
                        player_x_wins++;
                        break;
                    }
                    if (score_controller == 2)
                    {
                        printf("Vitória do player O!");
                        player_x_wins++;
                        break;
                    }
                }
            } while (1); //loop infinito
            if ((moves_counter == max_moves) && (score_controller == 0))
            {
                printf("\nDEU VELHA!");
                draws++;
            }
            printGameScore(player_x_wins, player_o_wins, draws);
            moves_counter = 0;
            score_controller = 0;
            menu_option = 10; // pra sair do switch case e voltar ao menu principal
            break;
        case 2:
            printRules();
            menu_option = 10;
            break;
        case 3:
            player_x_wins = 0;
            player_o_wins = 0;
            draws = 0;
            printf("O placar foi resetado!");
            printGameScore(player_x_wins, player_o_wins, draws);
            menu_option = 10;
            break;
        case 0:
            printf(">>>> Programa encerrado <<<<");
            break;
        default:
            while ((menu_option < 0) || (menu_option > 4))
            {
                printf("Opcao invalida, tente novamente!\n\n>>");
                scanf(" %d", &menu_option);
            }
            break;
        }
    } while (menu_option != 0);
    return 0;
}

void printAsterisks(int number_of_asterisks)
{
    printf("\n");
    for (int i = 1; i <= number_of_asterisks; i++)
    {
        printf("*");
    }
    printf("\n");
}

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

void printBoard(char board[BOARD_ROWS][BOARD_COLUMNS])
{
    printf("\n\t[0] [1] [2] \n\n"); // top bar
    for (int i = 0; i < BOARD_ROWS; i++)
    {
        printf("[%d]\t", i); // side bar
        for (int j = 0; j < BOARD_COLUMNS; j++)
        {
            if (((i != 2) && (j != 2)) || ((i == 2) && (j < 2)))
            {
                printf(" %c |", board[i][j]);
            }
            if (((j == 2) && (i < 2)) || ((i == 2) && (j == 2)))
            {
                printf(" %c ", board[i][j]);
            }
        }
        if (i < 2)
        {
            printf("\n\t-----------");
        }
        printf("\n");
    }
    printf("\n");
}

void printGameScore(int playerXWins, int playerOwins, int draws)
{
    printf("\n");
    printAsterisks(20);
    printf("-> JOGADOR X: %d pontos\n", playerXWins);
    printf("-> JOGADOR O: %d pontos\n", playerOwins);
    printf("-> EMPATES: %d", draws);
    printAsterisks(20);
    printf("\n");
}

void printRules()
{
    printAsterisks(25);
    printf("\n> lalallalalala\n");
    printf("> blablablablabla\n");
    printf("> lalallalalala\n");
    printf("> lalallalalala\n");
    printAsterisks(25);
}

void pause()

{
    printf("\n<PRESSIONE ENTER PARA CONTINUAR>\n");
    getchar();
    getchar();
}

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
