#include <iostream>
#include <vector>
const int N = 9;
bool findEmptyLocation(const std::vector<std::vector<int>>& board, int& row, int& col) {
    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(const std::vector<std::vector<int>>& board, int row, int col, int num) {
    for (int i = 0; i < N; ++i) {
        if (board[row][i] == num || board[i][col] == num || board[row - row % 3 + i / 3][col - col % 3 + i % 3] == num) {
            return false;
        }
    }
    return true;
}

bool solveSudoku(std::vector<std::vector<int>>& board) {
    int row, col;
    if (!findEmptyLocation(board, row, col)) {
        return true;
    }
    for (int num = 1; num <= 9; ++num) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

void printBoard(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board)) {
        std::cout << "Sudoku Puzzle Solved:" << std::endl;
        printBoard(board);
    } else {
        std::cout << "No solution exists for the given Sudoku puzzle." << std::endl;
    }

    return 0;
}
