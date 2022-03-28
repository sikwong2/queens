#include "chess.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

uint32_t solutions = 0;

Board *board_create(uint32_t size){
    Board *board = (Board *)malloc(sizeof(Board));
    board->size = size;

    board->grid = (char **)calloc(size, sizeof(char *));
    for(uint32_t n = 0; n < size; n += 1){
        board->grid[n] = (char *)calloc(size, sizeof(char));
    }

    return board;
}

void board_delete(Board *board){
    for (uint32_t n = 0; n < board->size; n += 1){
        free(board->grid[n]);
        board->grid[n] = NULL;
    }

    free(board->grid);
    board->grid = NULL;
    free(board);
    board = NULL;
}

uint32_t board_size(Board *board){
    return board->size;
}

bool isValid(Board *board, uint32_t r, uint32_t c){
    return board->grid[r][c] == 0;
}

void placeQueen(Board *board, uint32_t r, uint32_t c){
    if(isValid(board, r, c)){
        //set queen
        board->grid[r][c] = 'Q';

        //setting attacked squares
        for(uint32_t n = 1; n < board->size; n += 1){
            //vertical attack
            if(r + n < board->size){
                board->grid[r + n][c] -= 1;
            }
            
            //right diagonal
            if(r + n < board->size && c + n < board->size){
                board->grid[r + n][c + n] -= 1;
            }

            //left diagonal
            if(r + n < board->size && c - n + board->size >= board->size){
                board->grid[r + n][c - n] -= 1;
            }
        }
    }
}

void removeQueen(Board *board, uint32_t r, uint32_t c){
    if(board->grid[r][c] == 'Q'){
        board->grid[r][c] = 0;

        //removing attacked squares
        for(uint32_t n = 1; n < board->size; n += 1){
            //vertical attack
            if(r + n < board->size){
                board->grid[r + n][c] += 1;
            }
            
            //right diagonal
            if(r + n < board->size && c + n < board->size){
                board->grid[r + n][c + n] += 1;
            }

            //left diagonal
            if(r + n < board->size && c - n + board->size >= board->size){
                board->grid[r + n][c - n] += 1;
            }       
        }
    }
}

void solveQueens(Board *board, uint32_t r){
    if(r == board->size){
        printBoard(board);
        solutions += 1;
        return;
    }
    for(uint32_t c = 0; c < board->size; c += 1){
        if(isValid(board, r, c)){
            placeQueen(board, r, c);
            solveQueens(board, r + 1);
            removeQueen(board, r, c);
        }    
    }
}

void printBoard(Board *board){
    for(uint32_t r = 0; r < board->size; r += 1){
        for(uint32_t c = 0; c < board->size; c += 1){
            if(board->grid[r][c] == 'Q'){
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
