#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* function declaration */
void gridLine();
void drawSudoku(int ** sudoku);
int generateRandomeNumer();
void shuffleForEachGroup(char* rowOrCol, int ** sudoku);
void shuffleTwoRows(int ** sudoku, int random, int group);
void shuffleTwoCols(int ** sudoku, int random, int group);
void shuffleGroups(char* rowOrCol, int ** sudoku);

void gridLine(){
    for (int i =0; i<25; i++){
        printf("-");
    }
    printf("\n");
}

/*Draw out the sudoku*/
void drawSudoku(int ** sudoku){
    gridLine();
    for (int i=0; i<9; i++){
        printf("| ");
        for (int j=0; j<9; j++){
            printf("%d ", sudoku[i][j]);
            if (((j+1)%3 ==0) && (j != 0)) printf("| ");
        }
        printf("\n");
        if (((i+1)%3 ==0) && (i != 0)) gridLine();        
    }
}

/* Grnerate random number from 0 to 2 */
int generateRandomeNumer(){
    return rand() % 3;
}


/* Swapping two rows or columns in the same group */
void shuffleForEachGroup(char* rowOrCol, int ** sudoku){
    for (int i=0; i<3; i++){
        int random = generateRandomeNumer();
        // no swap if zero is generate 
        if (random != 0){
            if (strcmp(rowOrCol, "row") == 0) 
                shuffleTwoRows(sudoku,random, i);
            
            else 
                shuffleTwoCols(sudoku,random, i);   
        }
    }
}

/* Swapping two groups */
void shuffleTwoRows(int ** sudoku, int random, int group){
    int temp;
    int row1 = 3*group, row2 = 3*group+random;
    
    for (int i=0; i<9; i++){
        temp = sudoku[row1][i];
        sudoku[row1][i] = sudoku[row2][i];
        sudoku[row2][i] = temp;
    }       
}

/* Swapping two columns */
void shuffleTwoCols(int ** sudoku, int random, int group){
    int temp;
    int col1 = 3*group, col2 = 3*group+random;
    
    for (int i=0; i<9; i++){
        temp = sudoku[i][col1];
        sudoku[i][col1] = sudoku[i][col2];
        sudoku[i][col2] = temp;
    } 
}

void shuffleGroups(char* rowOrCol, int ** sudoku){
    //pick two different groups to swap
    int group1 = generateRandomeNumer(),  group2=group1;
    while(group1 == group2) group2 = generateRandomeNumer();
    group1 *=3, group2 *= 3;
    
    int temp;
    for (int i=0; i<3; i++){
        for (int j=0; j<9; j++){
            if (strcmp(rowOrCol,"row") == 0){
                temp = sudoku[group1+i][j];
                sudoku[group1+i][j] = sudoku[group2+i][j];
                sudoku[group2+i][j] = temp;
            }
            else{
                temp = sudoku[j][group1+i];
                sudoku[j][group1+i] = sudoku[j][group2+i];
                sudoku[j][group2+i] = temp;
            }
        }
    }    
}

/* Main Program starts here*/
int main()
{
    srand(time(NULL));
    
    /* Inilitalize a 2d array for sudoku with 9x9 */
    const int row = 9, col = 9; 
    int i, j;
    int **sudoku;
    sudoku = malloc(row * sizeof *sudoku);
    for (i=0; i<row; i++) {
        sudoku[i] = malloc(col * sizeof *sudoku[i]);
    }
    
    
    
     /* Create the root of sudoku */
    for (int countGroup=0; countGroup<3; countGroup++){
        for (int countR=0; countR<3; countR++){
            int pos = countR*3 + countGroup;
            for (int num=1; num<10; num++){
                if (pos == 9) pos-=9;
                sudoku[countR+countGroup*3][pos] = num;
                pos++;
            }
        }
    }
    
    //print the good root of sudoku
    printf("Show the good root of a Sudoku\n");
    drawSudoku(sudoku);
    
    
    
    /* Shuffle with rows and columns */
    
    //Shuffle rows for each group (within the 3×3 borders)
    shuffleForEachGroup("row", sudoku);
    
    //Shuffle columns for each group (within the 3×3 borders)
    shuffleForEachGroup("col", sudoku);
    
    //Shuffle two groups of rows
    shuffleGroups("row", sudoku);
    
    // Shuffle two groups of rows
    shuffleGroups("col", sudoku);
    
    // Draw the result
    printf("\nAfter shuffling with rows and columns \n");
    drawSudoku(sudoku);
     
    
    
    /* deallocate the sudoku 2d array */
    for (i=0; i<row; i++)  free(sudoku[i]);
    free(sudoku);
    
    /* end of program*/    
   return 0;
}
