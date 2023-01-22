#include <bits/stdc++.h>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    std::freopen("./input.txt", "r", stdin);
    std::freopen("./output.txt", "w", stdout);
#endif
}

class Maze {
private:
    int n;
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    int rowUtil[4] = {-1, 1, 0, 0};
    int colUtil[4] = {0, 0, -1, 1};

public:

    explicit Maze(int n) :
            n(n),
            grid(vector<vector<int>>(n, vector<int>(n))),
            visited(vector<vector<bool>>(n, vector<bool>(n, false))) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid.at(i).at(j);
            }
        }
    }

    [[nodiscard]] int valueAt(int row, int col) const {
        return grid.at(row).at(col);
    }

    [[nodiscard]] int isVisited(int row, int col) const {
        return visited.at(row).at(col);
    }

    void printPath() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << isVisited(i, j) << ' ';
            }
        }
        cout << endl;
    }

    [[nodiscard]] bool isValid(int row, int col) const {
        return (row >= 0) && (col >= 0) && (row < n) && (col < n);
    }

    void exploreAllPaths(int row, int col) {
        if (row == n - 1 && col == n - 1) {
            visited.at(row).at(col) = true;
            printPath();
            return;
        }

        if (!isValid(row, col) || isVisited(row, col)) {
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (valueAt(row, col) != 0) {
                visited.at(row).at(col) = true;
                exploreAllPaths(row + rowUtil[i], col + colUtil[i]);
                visited.at(row).at(col) = false;
            }
        }
    }
};

int main() {
    initIO();

    int n; cin >> n;
    Maze maze(n);

    maze.exploreAllPaths(0, 0);

    return 0;
}