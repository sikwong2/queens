#include "chess.h"
#include <unistd.h>
#include <inttypes.h>

int main(int argc, char **argv){
    int opt = 0;
    int n;

    while((opt = getopt(argc,argv, "n:")) != -1) {
        switch(opt) {
            case 'n': n = strtol(optarg, NULL, 10);
            break;
        }
    }

    //create board
    Board *board = board_create(5);
    /*placeQueen(board, 0 , 0);
    printBoard(board);*/
    solveQueens(board, 0);
    printf("An %dx%d board has %d solutions\n", n, n, solutions);

    return 0;
}
