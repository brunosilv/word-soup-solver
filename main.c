#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COLUMN 20

char randomBoard ( char [ROW] [COLUMN]) ;


int main( void )
{

    //declaracao de array de carateres
    char randchar_array [ROW] [COLUMN];
    //Chamada da funcao randomBoard
    printf( "\n Random Board.\n\n" ) ;
    randomBoard (randchar_array);

    return 0 ;

}
/**
 * Funcao que gerar matrix aleatoria de caraters usando a funcao nativa do random
 * @param randchar_array
 * @return
 */
char randomBoard (char randchar_array[ROW] [COLUMN])

{
    int r = 0 ;
    int c = 0 ;
    char nextchar = 'A';

    for (r = 0; r < ROW ; r++)
    {
        for (c = 0; c < COLUMN ; c++)
        {
            nextchar = 'A' + rand() % 26;
            randchar_array [r] [c] = nextchar;
            printf(" %c", nextchar);
        }

        printf("\n");
    }

    return (randchar_array [ROW] [COLUMN]);
}