# SudokuGenerator

Using C programming language to generte simple sudoku puzzle 

[Click Here to view my program](https://github.com/wing9413/CProgramming-SudokuGenerator/blob/master/MyProject/generator.c)

## Getting Started

The main idea of Sudoku generator is to create a good root of a sudoku, and generate different versions of a complete Sudoku by swapping and shuffling rows and columns.

### Details of the Sudoku generator

1. Create the good root of Sudoku in order

![alt text](https://github.com/wing9413/CProgramming-SudokuGenerator/blob/master/Others/rootOfSudoku.jpg)

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
