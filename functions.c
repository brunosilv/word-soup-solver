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
    //*(wordsearch + i) =
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
/**
 * Verifca se o caminho é permitido
 * @param matrix
 * @param matrix_aux
 * @param row
 * @param col
 * @return
 */
int check_consistency(int matrix[ROW][COLUMN], int matrix_aux[ROW][COLUMN],int row, int col)
{
    if(row>=0 && row< ROW && col>=0 && col<COLUMN)
    {
        if(matrix[ROW][COLUMN] == 1 && matrix_aux[ROW][COLUMN] == 0)
            return 1;
    }
    return 0;
}


/**
 * encontra o caminho
 * @param matrix
 * @param matrix_aux
 * @param row
 * @param col
 */
void find_path(int matrix[ROW][COLUMN], int matrix_aux[ROW][COLUMN],int row, int col)
{
    matrix_aux[row][col] = 1;

    if(col == COLUMN - 1)
    {
        printMat(matrix_aux);
        return ;
    }

    if(check_consistency(matrix, matrix_aux, row-1, col)==1)
    {

        find_path(matrix, matrix_aux, row-1, col);

        matrix_aux[row-1][col] = 0;

    }
    if(check_consistency(matrix, matrix_aux, row, col+1) == 1)
    {

        find_path(matrix, matrix_aux, row, col+1);

        matrix_aux[row][col+1] = 0;

    }

    if(check_consistency(matrix, matrix_aux, row+1, col) == 1)
    {

        find_path(matrix, matrix_aux, row+1, col);

        matrix_aux[row+1][col] = 0;

    }
    if(check_consistency(matrix, matrix_aux, row, col-1) == 1)
    {

        find_path(matrix, matrix_aux, row, col-1);

        matrix_aux[row][col-1] = 0;

    }
}