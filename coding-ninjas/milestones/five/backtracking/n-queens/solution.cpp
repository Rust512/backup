#include <iostream>
#include <string>
#include <vector>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    std::freopen("./input.txt", "r", stdin);
    std::freopen("./output.txt", "w", stdout);
#endif
}

class ChessBoard {
public:
    int n;
    vector<string> board;

    explicit ChessBoard(int n) : n(n), board(vector<string>(n)) {
        for (string &s: board) {
            s = string(n, '.');
        }
    }

    [[nodiscard]] bool isValidIndex(int row, int col) const {
        return (row >= 0) && (col >= 0) && (row < n) && (col < n);
    }

    bool placingQueenIsPossible(int row, int col) {
        for (int i = 0; i < n; i++) {
            if (board.at(i).at(col) == 'Q') {
                return false;
            }
        }

        int i = row;
        int j = col;

        while (isValidIndex(i, j)) {
            if (board.at(i--).at(j--) == 'Q') {
                return false;
            }
        }

        i = row;
        j = col;

        while (isValidIndex(i, j)) {
            if (board.at(i--).at(j++) == 'Q') {
                return false;
            }
        }

        return true;
    }

    void printBoard() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (board.at(i).at(j) == 'Q') << ' ';
            }
        }
        cout << endl;
    }

    void placeQueens(int row) {
        if (row == n) {
            this->printBoard();
            return;
        }

        for (int col = 0; col < n; col++) {
            if (this->placingQueenIsPossible(row, col)) {
                board.at(row).at(col) = 'Q';
                this->placeQueens(row + 1);
                board.at(row).at(col) = '.';
            }
        }
    }
};

int main() {
    initIO();
    int n;
    cin >> n;

    auto chessBoard = ChessBoard(n);

    chessBoard.placeQueens(0);

    return 0;
}