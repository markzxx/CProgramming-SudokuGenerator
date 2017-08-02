# SudokuGenerator

Using C programming language to generte simple sudoku puzzle 

[Click Here to view my code](https://github.com/wing9413/CProgramming-SudokuGenerator/blob/master/MyProject/generator.c)

## Getting Started

The main idea of Sudoku generator is to create a good root of a sudoku, and generate different versions of a complete Sudoku by swapping and shuffling rows and columns.

### Details of the Sudoku generator

<br />

#### 1. Details of the Sudoku generator
##### 1. Create the good root of Sudoku in order <br />

```C
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
```

![alt text](https://github.com/wing9413/CProgramming-SudokuGenerator/blob/master/Others/rootOfSudoku.jpg)

<br />
##### 2. Shuffle rows and columns for each group: Randomly pick two rows or columns in same group and swap them.

```C
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

/* Swapping two rows */
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
     /* Main Program */
    //Shuffle rows for each group (within the 3×3 borders)
    shuffleForEachGroup("row", sudoku);
    
    //Shuffle columns for each group (within the 3×3 borders)
    shuffleForEachGroup("col", sudoku);
```    
    
![alt text](https://github.com/wing9413/CProgramming-SudokuGenerator/blob/master/Others/2rowEachGroup.jpg)

![alt text](https://github.com/wing9413/CProgramming-SudokuGenerator/blob/master/Others/2colEachGroup.jpg)
