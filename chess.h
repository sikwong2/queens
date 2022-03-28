#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>

extern uint32_t solutions;
typedef struct Board{
    char **grid;
    uint32_t size;
} Board;

Board *board_create(uint32_t size);

void board_delete(Board *board);

uint32_t board_size(Board *board);

bool isValid(Board *board, uint32_t r, uint32_t c);

void placeQueen(Board *board, uint32_t r, uint32_t c);

void removeQueen(Board *board, uint32_t r, uint32_t c);

void solveQueens(Board *board, uint32_t r);

void printBoard(Board *board);
