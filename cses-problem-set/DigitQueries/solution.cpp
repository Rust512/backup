#include <bits/stdc++.h>
 
#define ll long long
 
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

ll powerOfTen(unsigned int y) {
    ll result = 1, ten = 10;
    while (y != 0) {
        if (y & 1) {
            result *= ten;
        }

        ten *= ten;
        y >>= 1;
    }

    return result;
}

ll endIndex(int digits) {
    return (1LL * digits * powerOfTen(digits)) - ((powerOfTen(digits) - 1LL) / 9LL);
}

int numberOfDigits(ll index) {
    int start = 1, end = 17;
    int mid, result;

    while (start <= end) {
        mid = (end + start) / 2;
        ll ending = endIndex(mid);
        // cout << start << ' ' << end << ' ' << ending << ' ' << index << endl;
        if (ending == index) {
            return mid;
        } else if (ending < index) {
            start = mid + 1;
        } else {
            result = mid;
            end = mid - 1;
        }
    }

    return result;
}

// start index for number with digits 'd' = d * (10 ^ d) - ((10 ^ d - 1) / 9);
// the maximum number of digits = 16.
void solve() {
    
    int q; cin >> q;
    while (q--) {
        ll k; cin >> k;
        int digits = numberOfDigits(k);
        ll start = endIndex(digits - 1) + 1;

        ll theNumber = powerOfTen(digits - 1) + ((k - start) / digits);
        int rem = (k - start) % digits;
        while (--digits != rem) {
            theNumber /= 10LL;
        }

        cout << theNumber % 10 << endl;
    }
}
 
int main() {
    initIO();
    solve();
    return 0;
}