#include <iostream>
#include <array>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
}

constexpr int DIRECTIONS = 4;
constexpr int GRID_SIZE = 9;
constexpr int PATH_SIZE = 48;

const array<int, DIRECTIONS> row_utils = {-1, 0, 1, 0};
const array<int, DIRECTIONS> col_utils = {0, 1, 0, -1};

int direction_to_integer(char direction) {
    switch (direction) {
        case 'U': return 0;
        case 'R': return 1;
        case 'D': return 2;
        case 'L': return 3;
        default : return 4;
    }
}

int explore_paths(int row, int col, array<array<bool, GRID_SIZE>, GRID_SIZE>& visited, const array<int, PATH_SIZE>& path, int index) {
    if (visited[row + 1][col] && visited[row - 1][col] && !visited[row][col + 1] && !visited[row][col - 1]) return 0;
    if (visited[row][col + 1] && visited[row][col - 1] && !visited[row + 1][col] && !visited[row - 1][col]) return 0;
    if (row == 7 && col == 1) {
        return (int)(index == PATH_SIZE);
    }
    if (index == PATH_SIZE) return 0;

    visited[row][col] = true;

    int direction = path[index];
    int possible_paths = 0;

    if (direction < 4) {
        int next_row = row + row_utils[direction];
        int next_col = col + col_utils[direction];
        if (!visited[next_row][next_col]) possible_paths += explore_paths(next_row, next_col, visited, path, index + 1);
    }

    for (int dir = 0; dir < DIRECTIONS && direction == DIRECTIONS; dir++) {
        int next_row = row + row_utils[dir];
        int next_col = col + col_utils[dir];
        if (visited[next_row][next_col]) continue;
        possible_paths += explore_paths(next_row, next_col, visited, path, index + 1);
    }

    visited[row][col] = false;

    return possible_paths;
}

int main() {
    initIO();

    string string_path;
    getline(cin, string_path);

    array<int, PATH_SIZE> processed_path{};
    int index = 0;
    for (const char direction: string_path) {
        processed_path[index] = direction_to_integer(direction);
        index++;
    }

    array<array<bool, GRID_SIZE>, GRID_SIZE> visited{};
    for (array<bool, GRID_SIZE> row: visited) {
        row.fill(false);
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        visited[i][0] = true;
        visited[i][8] = true;
        visited[0][i] = true;
        visited[8][i] = true;
    }

    int total_paths = explore_paths(1, 1, visited, processed_path, 0);
    cout << total_paths << '\n';

    return 0;
}
