#ifndef _INCLUDED_TIC_TAC_TOE_H /* effectively prevents multiple #includes */

/*
 * This header file describes the Board struct and all accessible
 * functions in the Tic Tac Toe library.
 */

#define MAXELEMENT 3

typedef struct
{
    int occupied;
    char symbol;
} Cell;

typedef struct
{
    Cell cells[3][3];
    int winner;
    int counter;
    int size;
    int currentPlayer;
} Board;
/* ASSIGNMENT
 * Add structure definitions for the library (Board and Cell)
 */

Cell initializeCell (char, int);
void getPosition (Board, int[2]);
Board updateBoard (int, int, Board);
int isWinningMove (int, int, Board);
void printBoard (Board);
/*
 * ASSIGNMENT
 *
 * Add extern prototypes for all functions in "tic_tac_toe_demo.c"
 */
  

#define _INCLUDED_TIC_TAC_TOE_H
#endif
