#include <bits/stdc++.h>

#define ll long long

using namespace std;


void initIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
}

int customBinarySearch(const vector<ll>& arr, ll key) {
    int result = -1, start = 0, end = arr.size(), mid;

    while (start <= end) {
        mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            result = mid;
            end = mid - 1;
        }
    }

    return result;
}

ll powerOfTen(int digits) {
    ll res = 1LL, ten = 10LL;
    while (digits != 0) {
        if (digits & 1) {
            res *= ten;
        }
        ten *= ten;
        digits >>= 1;
    }
    return res;
}

void solve() {
    vector<ll> aux(16, 0LL);
    aux[0] = 9LL;
    for (int i = 1; i < 16; i++) {
        aux[i] = (aux[i - 1] * 10LL * (i + 1)) / ((i) * 1LL);
    }

    for (int i = 1; i < 16; i++) {
        aux[i] += aux[i - 1];
    }

    int q; cin >> q;
    while (q--) {
        ll k; cin >> k;
        int pos = customBinarySearch(aux, k), digits = pos + 1;
        if (pos == 0) {
            cout << k << endl;
            continue;
        }

        ll start = aux[pos - 1] + 1LL;
        ll num =  powerOfTen(pos) + ((k - start) / digits);

        int digitFromLeft = (k - start) % digits;

        ll divisor = powerOfTen(pos - digitFromLeft);
        cout << (num / divisor) % 10LL << endl;
    }
}


int main () {
    initIO();
    // int t; cin >> t;
    // while (t--) {
    solve();
    // }
    return 0;
}