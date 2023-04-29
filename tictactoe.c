/*
Author: Gregory Dott 29-04-2023
Basic tictactoe game for command line
*/

#include <stdio.h>
#include <stdbool.h>

#define clear() printf("\033[H\033[J")



void drawBoard(int board[9]);
bool checkForWin(int board[9]);
int nextMove(int playerToMove, int board[9]);
bool isValidInput(int input, int board[9]);

int main(void)
{
	int board[9] = {0};
    int playerToMove = 1;

    clear();

    while (!checkForWin(board)) {
        printf("Player 1: X, Player 2: O\n");
        drawBoard(board);
        playerToMove = nextMove(playerToMove, board);
        clear();
    }
	
    printf("Player %i has won!\n", playerToMove == 1 ? 2: 1);
    drawBoard(board);

	return 0;
}

void drawBoard(int board[9])
{
    printf("\n");
    for(int i = 0; i < 9; i++) {
        printf(" %c ", board[i] == 0 ? i + '0' : (board[i] == 1 ? 'X' : 'O'));
        if ((i + 1) % 3 == 0)
            printf("\n");
    }
    printf("\n");
}

bool checkForWin(int board[9])
{
    for(int i = 0; i < 3; i++) {
        if(board[3*i] != 0 && board[3*i] == board[3*i+1] && board[3*i] == board[3*i+2]) {
            return true;
        }
        if(board[i] != 0 && board[i] == board[i+3] && board[i] == board[i+6]) {
            return true;
        }
    }

    if(board[0] != 0 && board[0] == board[4] && board[0] == board[8]) {
        return true;
    }
    if(board[2] != 0 && board[2] == board[4] && board[2] == board[6]) {
        drawBoard(board);
        return true;
    }
    return false;
}

int nextMove(int playerToMove, int board[9])
{
    int input = -1;

    while(!isValidInput(input, board)) {
        printf("Player %i to move: ", playerToMove);
        scanf("%i", &input);
        printf("\n");
    }
    board[input] = playerToMove;
    return playerToMove == 1 ? 2 : 1;
}


bool isValidInput(int input, int board[9])
{
    if (input < 9 && input >= 0) {
        if (board[input] != 0) 
            return false;
        else
            return true;
    } else
        return false;
}
