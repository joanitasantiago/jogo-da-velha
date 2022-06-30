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
    int menu_option, max_moves = BOARD_ROWS * BOARD_COLUMNS, moves_counter = 0, player_x_wins = 0, player_o_wins = 0, draws = 0, score_controller = 0;

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