
/*
 * Sudoku Solver
 *
 * Solves a standard 9x9 Sudoku puzzle using recursive backtracking.
 *
 * Input:
 *   81 integers representing the Sudoku grid.
 *   Use 0 to represent an empty cell.
 *
 * Output:
 *   The solved Sudoku grid, or an error message if the puzzle is
 *   invalid or has no solution.
 */

#include <iostream>
using namespace std;

// Checks whether digit d can be placed at sudoku[row][col].
// The digit must not already appear in the same row, column,
// or 3x3 subgrid.
bool canbeput(int sudoku[][9], int row, int col, int d) {
    int br = 3 * (row / 3);
    int bc = 3 * (col / 3);

    for (int i = 0; i < 9; i++) {
        // Check the current row and column.
        if (sudoku[row][i] == d) return false;
        if (sudoku[i][col] == d) return false;

        // Check the corresponding 3x3 subgrid.
        if (sudoku[br + i / 3][bc + i % 3] == d) {
            return false;
        }
    }

    return true;
}

// Checks whether the initially provided clues conflict.
// Each non-empty cell is temporarily cleared so that it
// can be checked against the other clues.
bool validclues(int sudoku[][9]) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            int d = sudoku[r][c];

            // Skip empty cells.
            if (d == 0) continue;

            // Temporarily clear the current cell.
            sudoku[r][c] = 0;

            bool ok = canbeput(sudoku, r, c, d);

            // Restore the original clue.
            sudoku[r][c] = d;

            if (!ok) return false;
        }
    }

    return true;
}

// Solves the Sudoku recursively using backtracking.
// Cells are processed from left to right, top to bottom.
bool solved(int sudoku[][9], int row, int column) {
    // All rows have been filled successfully.
    if (row == 9) return true;

    // Move to the first column of the next row.
    if (column == 9) {
        return solved(sudoku, row + 1, 0);
    }

    // Existing clues cannot be changed.
    if (sudoku[row][column] != 0) {
        return solved(sudoku, row, column + 1);
    }

    // Try every possible digit in the empty cell.
    for (int k = 1; k <= 9; k++) {
        if (canbeput(sudoku, row, column, k)) {
            sudoku[row][column] = k;

            // Continue solving with this candidate.
            if (solved(sudoku, row, column + 1)) {
                return true;
            }

            // The candidate led to a dead end.
            // Undo the placement and try another digit.
            sudoku[row][column] = 0;
        }
    }

    // No candidate worked for this cell.
    return false;
}

int main() {
    int sudoku[9][9] = {};

    // Read the 81 values and validate their range.
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!(cin >> sudoku[i][j]) ||
                sudoku[i][j] < 0 ||
                sudoku[i][j] > 9) {
                cout << "Invalid input: expected 81 integers "
                        "from 0 to 9.\n";
                return 1;
            }
        }
    }

    // Reject puzzles with conflicting initial clues.
    if (!validclues(sudoku)) {
        cout << "Invalid puzzle: the given clues conflict "
                "with each other.\n";
        return 1;
    }

    // Solve and display the completed grid.
    if (solved(sudoku, 0, 0)) {
        cout << "*** Solved Sudoku ***\n";

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "No solution exists.\n";
        return 1;
    }

    return 0;
}
