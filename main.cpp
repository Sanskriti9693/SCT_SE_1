#include <iostream>
using namespace std;

const int N = 9;

// Function to print Sudoku grid
void printGrid(int grid[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if placing number is safe
bool isSafe(int grid[N][N], int row, int col, int num) {

    // Check row
    for(int x = 0; x < N; x++) {
        if(grid[row][x] == num)
            return false;
    }

    // Check column
    for(int x = 0; x < N; x++) {
        if(grid[x][col] == num)
            return false;
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(grid[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

// Backtracking function
bool solveSudoku(int grid[N][N]) {

    int row, col;
    bool emptyFound = false;

    // Find empty cell
    for(row = 0; row < N; row++) {
        for(col = 0; col < N; col++) {
            if(grid[row][col] == 0) {
                emptyFound = true;
                break;
            }
        }
        if(emptyFound)
            break;
    }

    // No empty cell means solved
    if(!emptyFound)
        return true;

    // Try numbers 1 to 9
    for(int num = 1; num <= 9; num++) {

        if(isSafe(grid, row, col, num)) {

            grid[row][col] = num;

            // Recursive call
            if(solveSudoku(grid))
                return true;

            // Backtrack
            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {

    int grid[N][N] = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };

    if(solveSudoku(grid)) {
        cout << "Solved Sudoku:\n";
        printGrid(grid);
    }
    else {
        cout << "No solution exists";
    }

    return 0;
}