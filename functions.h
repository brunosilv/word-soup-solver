//
// Created by Bruno on 2018-11-24.
//

#ifndef SOPA_FUNCTIONS_H
#define SOPA_FUNCTIONS_H

#define ROW 10
#define COLUMN 10
#define FILE_BOARD "C:\\Users\\Bruno\\CLionProjects\\SOPA\\words.txt"
#define BUFFER 1000

char randomBoard(char randchar_array[ROW][COLUMN]);
char *read_file(char *filename);
void printMatrix(char **matrix, int col, int row);
char **readFromFile(int row, int col);
void initMat(int m[][COLUMN]);
void printMat(int matrix[ROW][COLUMN]);
void find_path(int matrix[ROW][COLUMN], int matrix_aux[ROW][COLUMN],int row, int col);
int check_consistency(int matrix[ROW][COLUMN], int matrix_aux[ROW][COLUMN],int row, int col);

#endif //SOPA_FUNCTIONS_H
