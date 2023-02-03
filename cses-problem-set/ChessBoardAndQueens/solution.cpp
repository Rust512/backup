#include <bits/stdc++.h>


using namespace std;


void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
}

class ChessBoard {
private:
    vector<string> board;
public:
    explicit ChessBoard(): board(vector<string>(8)) {
        for (string& row: board) {
            cin >> row;
        }
    }

    bool isInvalid(int row, int col) {
        return board.at(row).at(col) == 'Q';
    }

    bool inRange(int row, int col) {
        return (row >= 0) && (row < 8) && (col >= 0) && (col < 8);
    }

    bool canPlaceHere(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (isInvalid(i, col)) {
                return false;
            }
        }

        int i = row, j = col;
        while (inRange(i, j)) {
            if (isInvalid(i--, j++)) {
                return false;
            }
        }

        i = row, j = col;
        while (inRange(i, j)) {
            if (isInvalid(i--, j--)) {
                return false;
            }
        }

        return true;
    }

    void countValidConfigurations(int row, int &count) {
        if (row == 8) {
            count++;
            return;
        }

        for (int col = 0; col < 8; col++) {
            if (canPlaceHere(row, col) && board.at(row).at(col) != '*') {
                board.at(row).at(col) = 'Q';
                countValidConfigurations(row + 1, count);
                board.at(row).at(col) = '.';
            }
        }
    }

    int countValidConfigurations() {
        int count = 0;
        countValidConfigurations(0, count);
        return count;
    }
};

void solve() {
    ChessBoard board;
    cout << board.countValidConfigurations() << endl;
}


int main () {
    initIO();
    // int t; cin >> t;
    // while (t--) {
    solve();
    // }
    return 0;
}