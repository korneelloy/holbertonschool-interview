#!/usr/bin/python3
"""
placing N non-attacking queens on an NxN chessboard.
"""

import sys


def is_safe(solution, row, col):
    """
    Check if a queen can be placed at (row, col) without attacks.
    """
    for r in range(row):
        c = solution[r]
        if c == col or abs(c - col) == abs(r - row):
            return False
    return True


def solve(solution, row, size):
    """
    Recursively place queens row by row and print every solution found.
    """
    if row == size:
        print([[r, solution[r]] for r in range(size)])
        return
    for col in range(size):
        if is_safe(solution, row, col):
            solution[row] = col
            solve(solution, row + 1, size)


def main():
    """Parse arguments and start solving the N queens problem."""
    if ((len(sys.argv) != 2)):
        print("Usage: nqueens N")
        exit(1)
    try:
        size = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        exit(1)
    if (size < 4):
        print("N must be at least 4")
        exit(1)

    solve([None] * size, 0, size)


if __name__ == "__main__":
    main()
