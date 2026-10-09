
# Sudoku Solver in C++

A command-line Sudoku solver implemented in C++ using
recursive backtracking.

## Features

- Solves standard 9x9 Sudoku puzzles.
- Validates the initial clues for row, column, and subgrid conflicts.
- Uses backtracking to explore possible solutions.
- Reports invalid puzzles and puzzles with no solution.
- Accepts input from standard input.

## Algorithm

The solver uses recursive backtracking:

1. Find the next empty cell.
2. Try digits from 1 to 9.
3. Check whether a digit is valid in its row, column, and 3x3 subgrid.
4. If valid, place the digit and recursively solve the remaining grid.
5. If the choice leads to a dead end, undo it and try another digit.
6. Stop when the grid is complete or no solution exists.

## Requirements

- A C++ compiler supporting C++17 or later.
- A terminal or command-line environment.

## Compile

On macOS or Linux:

```bash
clang++ -std=c++17 -Wall -Wextra -pedantic solver.cpp -o solver
```

Alternatively, use `g++` if it is available.

## Run

Provide the 81 Sudoku values through standard input.
Use `0` for empty cells.

```bash
./solver < sample_input.txt
```

## Example Input

The repository includes `sample_input.txt` with a sample
Sudoku puzzle.

## Complexity

Let N be the number of empty cells.

- Time complexity: Exponential in the worst case, because
  the solver may explore many candidate combinations.
- Auxiliary space: O(N) recursion depth, excluding the
  fixed-size Sudoku grid.

Actual performance depends on the puzzle and the order
in which candidate digits are explored.

## Limitations

- Supports standard 9x9 Sudoku only.
- Does not use advanced heuristics such as the
  minimum-remaining-values strategy.
- Stops after finding the first solution.

## License

This project is available under the MIT License.
Add a LICENSE file before distributing the project under
that license.
