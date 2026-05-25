#include <stdio.h>

int board[20][20];
int N;
int solutionCount = 0;

/* Function to print the board */
void printBoard() {
    int i, j;

    printf("\nSolution %d:\n", ++solutionCount);

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

/* Function to check if position is safe */
int isSafe(int row, int col) {
    int i, j;

    /* Check same column */
    for(i = 0; i < row; i++) {
        if(board[i][col] == 1)
            return 0;
    }

    /* Check upper-left diagonal */
    for(i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1)
            return 0;
    }

    /* Check upper-right diagonal */
    for(i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if(board[i][j] == 1)
            return 0;
    }

    return 1;
}

/* Backtracking function */
void solveNQueens(int row) {
    int col;

    /* All queens placed */
    if(row == N) {
        printBoard();
        return;
    }

    for(col = 0; col < N; col++) {

        if(isSafe(row, col)) {

            board[row][col] = 1;   // Place queen

            solveNQueens(row + 1);

            board[row][col] = 0;   // Backtrack
        }
    }
}

int main() {

    int i, j;

    printf("Enter value of N: ");
    scanf("%d", &N);

    /* Initialize board with 0 */
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    solveNQueens(0);

    printf("\nTotal Solutions = %d\n", solutionCount);

    return 0;
}
