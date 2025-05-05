#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE    10
#define MINES   12

int main(){
    char field[SIZE][SIZE];
    srand(time(NULL));
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            field[i][j] = '0'; 
        }
    }
    int rows = 0;
    int cols = 0;
    int cnt = 0;
    while(cnt < MINES){
        rows = rand()%10;
        cols = rand()%10;
        if(field[rows][cols] != '*' && 
        (field[rows][cols+1] != '*' && field[rows][cols-1] != '*') && 
        (field[rows+1][cols] != '*' && field[rows-1][cols] != '*') && 
        (field[rows+1][cols-1] != '*' && field[rows+1][cols+1] != '*') && 
        (field[rows-1][cols-1] != '*' && field[rows-1][cols+1] != '*')){
            field[rows][cols] = '*';
            cnt++;
        }
    }
    
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            printf("%c ", field[i][j]);
            if(j == 9){ printf("\n"); }
        }
    }

    return 0;
}
