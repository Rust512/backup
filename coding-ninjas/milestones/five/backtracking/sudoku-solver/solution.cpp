#include <bits/stdc++.h>

#define N 9

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    std::freopen("./input.txt", "r", stdin);
    std::freopen("./output.txt", "w", stdout);
#endif
}

class SudokuGrid {
private:
    vector<vector<int>> grid;
public:
    explicit SudokuGrid():
            grid(vector<vector<int>>(N, vector<int>(N))) {
        for (int i = 0; i < N; i++) {
            string row; cin >> row;
            for (int j = 0; j < row.length(); j++) {
                grid.at(i).at(j) = row.at(j) - '0';
            }
        }
    }

    bool findEmptyLocation(int& row, int& col) const {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid.at(i).at(j) == 0) {
                    row = i;
                    col = j;
                    return true;
                }
            }
        }

        return false;
    }

    bool isSafeInRow(int row, int num) {
        for (int i = 0; i < N; i++) {
            if (grid.at(row).at(i) == num) {
                return false;
            }
        }
        return true;
    }

    bool isSafeInCol(int col, int num) {
        for (int i = 0; i < N; i++) {
            if (grid.at(i).at(col) == num) {
                return false;
            }
        }
        return true;
    }

    bool isSafeInBox(int row, int col, int num) {
        int boxStartRow = 3 * (row / 3);
        int boxStartCol = 3 * (col / 3);

        for (int i = boxStartRow; i < boxStartRow + 3; i++) {
            for (int j = boxStartCol; j < boxStartCol + 3; j++) {
                if (grid.at(i).at(j) == num) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isSafe(int row, int col, int num) {
        return isSafeInRow(row, num) &&
                isSafeInCol(col, num) &&
                isSafeInBox(row, col, num);
    }

    bool solveSudoku() {
        int row, col;
        if (!findEmptyLocation(row, col)) {
            return true;
        }

        for (int num = 1; num < 10; num++) {
            if (isSafe(row, col, num)) {
                grid.at(row).at(col) = num;
                if (solveSudoku()) {
                    return true;
                }
                grid.at(row).at(col) = 0;
            }
        }

        return false;
    }

    void printSolution() const {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << grid.at(i).at(j);
            }
            cout << endl;
        }
    }
};

int main() {
    initIO();

    auto sudoku = SudokuGrid();

    bool isSolved = sudoku.solveSudoku();

    cout << (isSolved ? "true" : "false") << endl;

	return 0;
}
