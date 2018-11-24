//
// Created by Bruno on 2018-11-24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


/**
 * Criação de matrix com carateres aleatorios
 * @param randchar_array array definido com posições de colunas e linhas
 * @return
 */
char randomBoard(char randchar_array[ROW][COLUMN]) {
    int r = 0;
    int c = 0;
    char nextchar = 'A';
    printf("\n Random Board.\n\n");
    for (r = 0; r < ROW; r++) {
        for (c = 0; c < COLUMN; c++) {
            nextchar = 'A' + rand() % 26;
            randchar_array[r][c] = nextchar;
            printf(" %c", nextchar);
        }

        printf("\n");
    }

    return randchar_array[ROW][COLUMN];
}

void printMatrix(char **matrix, int col, int row) {
    int i, j;
    printf("\n File Board.\n\n");
    for (i = 0; i < col; i++) {
        for (j = 0; j < row; j++) {
            printf(" %c", matrix[i][j]);
        }
        printf("\n");
    }
}

char **readFromFile(int row, int col) {
    char **wordsearch = (char **) malloc(col * sizeof(char *));
    for (int i = 0; i < col; i++)
        wordsearch[i] = (char *) malloc((size_t) row++);

    FILE *f;
    if ((f = fopen(FILE_BOARD, "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    for (int i = 0; i < col; i++) {
        fgets(wordsearch[i], BUFFER, f);
        if (wordsearch[i][strlen(wordsearch[i])] == '\n') {
            wordsearch[i][strlen(wordsearch[i])] = '\0';
        }
    }
    fclose(f);
    return wordsearch;
}