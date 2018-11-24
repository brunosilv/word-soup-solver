#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#define ROW 10
#define COLUMN 10
#define FILE_BOARD "C:\\Users\\Bruno\\CLionProjects\\SOPA\\words.txt"
#define BUFFER 1000

int main(void) {
    //variaveis
    char randchar_array[ROW][COLUMN];
    char  matrix[ROW][COLUMN];
    char **wordsearch = readFromFile(ROW,COLUMN);
    //randomBoard(randchar_array);
    printMatrix(wordsearch,ROW, COLUMN);

    return 0;

}
