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

int rowUtil[4] = {-1, 0, 1, 0};//U, R, D, L
int colUtil[4] = {0, 1, 0, -1};

class Grid {
private:
    vector<vector<bool>> visited;
    vector<int> path;

public:
    explicit Grid() : visited(vector<vector<bool>>(9, vector<bool>(9, false))),
                      path(vector<int>(48, 0)){
        string pathString;
        cin >> pathString;

        for (int i = 0; i < 9; i++) {
            visited.at(i).at(0) = true;
            visited.at(i).at(8) = true;
            visited.at(0).at(i) = true;
            visited.at(8).at(i) = true;
        }

        for (int i = 0; i < 48; i++) {
            switch(pathString[i]) {
                case 'U': path.at(i) = 0; break;
                case 'R': path.at(i) = 1; break;
                case 'D': path.at(i) = 2; break;
                case 'L': path.at(i) = 3; break;
                default : path.at(i) = 4; break;
            }
        }
    }

    bool isBlocked(int row, int col) {
        return visited.at(row).at(col);
    }

    int tryPath(int row, int col, int index) {
        if (isBlocked(row, col)) {
            return 0;
        }
        //pruning
        if (isBlocked(row + 1, col) && isBlocked(row - 1, col) &&
                (!isBlocked(row, col + 1) && !isBlocked(row, col - 1))) return 0;
        
        //pruning
        if (isBlocked(row, col + 1) && isBlocked(row, col - 1) && 
                (!isBlocked(row + 1, col) && !isBlocked(row - 1, col))) return 0;

        //if end is reached
        if (row == 7 && col == 1) {
            //if path end is reached
            if (index == 48) {
                return 1;
                cout << "end" << endl;
            }

            return 0;
        }

        cout << row << ' ' << col << endl;

        visited.at(row).at(col) = true;
        if (path[index] != 4) {
            return tryPath(row + rowUtil[path[index]], col + colUtil[path[index]], index + 1);
        }

        int result = 0;
        for (int dir = 0; dir < 4; dir++) {
            result += tryPath(row + rowUtil[dir], col + colUtil[dir], index + 1);
        }
        visited.at(row).at(col) = false;

        return result;
    }

    void printVisited() {
        for (int i = 0; i < 9; i++) {

        }
    }
};


void solve() {
    Grid grid;
    cout << grid.tryPath(1, 1, 0) << endl;
}


int main () {
    initIO();
    // int t; cin >> t;
    // while (t--) {
    solve();
    // }
    return 0;
}