#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#include "tic_tac_toe.h"


void printBoard(Board board)
{
    for (int row = 0; row < board.size; row++)
    {
        printf("| ");
        for (int column = 0; column < board.size; column++)
        {
            printf("%c | ", board.cells[row][column].symbol);
        }
        printf("\n");
    }
    printf("\n");
}
   
Cell initializeCell(char sym, int isOccupied)
{
    Cell init;
    init.occupied = isOccupied;
    init.symbol = sym;
    return init;
}

void getPosition(Board board, int pos[2])
{
    int r, c;
    do
    {
    printf("Enter the row and column: ");
    scanf("%d%d", &r, &c);
    } while (board.cells[r][c].occupied == 1 || r > board.size-1 || c > board.size-1 || r < 0 || c < 0);
    pos[0] = r;
    pos[1] = c;
}

Board updateBoard(int r, int c, Board board)
{

    board.cells[r][c].occupied = 1;
    if (board.currentPlayer == 0)
    {
        board.cells[r][c].symbol = 'O';
    }
    else
    {
        board.cells[r][c].symbol = 'X';
    }
    board.counter++;
    return board;
}


int isWinningMove(int r, int c, Board board)
{

    int possibleWin = 0;
    char playerSymbol;
    if (board.currentPlayer == 0)
        playerSymbol = 'O';
    else
        playerSymbol = 'X';
   
    for (int column = 0; column < board.size; column++)
    {
        if (board.cells[r][column].symbol == playerSymbol)
            possibleWin = 1;
        else
        {
            possibleWin = 0;
            break;
        }
    }
    if (possibleWin == 1)
    {
        return possibleWin;
    }
   
    for (int row = 0; row < board.size; row++)
    {
        if (board.cells[row][c].symbol == playerSymbol)
            possibleWin = 1;
        else
        {
            possibleWin = 0;
            break;
        }
    }
    if (possibleWin == 1)
    {
        return possibleWin;
    }


    if (c == r)
    {
        for (int row = 0; row < board.size; row++)
        {
            if (board.cells[row][row].symbol == playerSymbol)
                possibleWin = 1;
            else
            {
                possibleWin = 0;
                break;
            }
        }
        if (possibleWin == 1)
        {
            return possibleWin;
        }
    }

    if (c == board.size - 1 - r && c != r)
    {
        if (board.cells[r][c].symbol == playerSymbol && board.cells[c][r].symbol == playerSymbol && board.cells[1][1].symbol == playerSymbol)
            possibleWin = 1;
        else
        {
            possibleWin = 0;
        }
        if (possibleWin == 1)
        {
            return possibleWin;
        }
    }

    return 0;
}
