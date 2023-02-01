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

void towerOfHanoi(int n, int source, int auxillary, int destination) {
    if (n == 0) {
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxillary);
    cout << source << ' ' << destination << '\n';
    towerOfHanoi(n - 1, auxillary, source, destination);
}

int powerOfTwo(int n) {
    int res = 1, two = 2;
    while (n != 0) {
        if (n & 1) {
            res *= two;
        }
        two *= two;
        n >>= 1;
    }

    return res;
}

void solve() {
    int n; cin >> n;
    cout << powerOfTwo(n) - 1 << endl;
    towerOfHanoi(n, 1, 2, 3);
}


int main () {
    initIO();
    // int t; cin >> t;
    // while (t--) {
    solve();
    // }
    return 0;
}