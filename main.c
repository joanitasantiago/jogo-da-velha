#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>
#include <time.h>
#include "print.h"
#include "gameplay.h"

int main(int argc, char const *argv[])
{
    // * * * Variables * * *
    char game_board[BOARD_ROWS][BOARD_COLUMNS];
    int menu_option, loop_control = 0, moves_counter = 0, player_x_wins = 0, player_o_wins = 0, draws = 0;

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
            system("cls");
            printBoard(BOARD_ROWS, BOARD_COLUMNS, game_board);
            do
            {
                player1Move(&moves_counter, game_board);
                system("cls");
                printBoard(BOARD_ROWS, BOARD_COLUMNS, game_board);
                checkWin(&player_x_wins, &player_o_wins, &loop_control, moves_counter, game_board);
                checkDraw(moves_counter, &loop_control, &draws);
                if (loop_control == 1)
                {
                    break;
                }
                player2Move(&moves_counter, game_board);
                system("cls");
                printBoard(BOARD_ROWS, BOARD_COLUMNS, game_board);
                checkWin(&player_x_wins, &player_o_wins, &loop_control, moves_counter, game_board);
                checkDraw(moves_counter, &loop_control, &draws);
            } while (loop_control == 0); /* continua o loop até uma mudança no placar */
            printGameScore(player_x_wins, player_o_wins, draws);
            loop_control = 0;
            moves_counter = 0;
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