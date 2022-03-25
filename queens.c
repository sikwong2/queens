#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct Board{
    char **grid;
    uint32_t size;
} Board;

Board *board_create(uint32_t size){
    Board *board = (Board *)malloc(sizeof(Board));
    board->size = size;

    board->grid = (char **)calloc(size, sizeof(char *));
    for(uint32_t n = 0; n < size; n += 1){
        board->grid[n] = (char *)calloc(size, sizeof(char));
    }

    return board;
}
void placeQueen(Board *board, uint32_t r, uint32_t c){
    //set queen
    board->grid[r][c] = 'Q';

    //setting attacked squares
    for(uint32_t n = 0; n < board->size; n += 1){
        //vertical attack
        if(r + n < board->size){
            board->grid[r + n][c] = '.';
        }

        //right diagonal
        if(r + n < board->size && c + n < board->size){
            board->grid[r + n][c + n] = '.';
        }

        //left diagonal
        if(r + n < board->size && c - n > 0){
            board->grid[r + n][c - n] = '.';
        }
        
    }
}

void removeQueen(Board *board, uint32_t r, uint32_t c){
    if(board->grid[r][c] == 'Q'){
        board->grid[r][c] = '0';

        //removing attacked squares
        for(uint32_t n = 0; n < board->size; n += 1){
            //vertical attack
            if(r + n < board->size){
                board->grid[r + n][c] = '0';
            }

            //right diagonal
            if(r + n < board->size && c + n < board->size){
                board->grid[r + n][c + n] = '0';
            }

            //left diagonal
            if(r + n < board->size && c - n > 0){
                board->grid[r + n][c - n] = '0';
            }       
        }
    }
}

void printBoard(Board *board){
    for(uint32_t r = 0; r < board->size; r += 1){
        for(uint32_t c = 0; c < board->size; c += 1){
            printf("%c", board->grid[r][c]);
        }
        printf("\n");
    }
}

int main(void){
    Board *chess = board_create(8);

    placeQueen(chess, 0, 1);

    printBoard(chess);
    return 0;
}