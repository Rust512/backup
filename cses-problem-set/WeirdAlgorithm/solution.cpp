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
 
void solve() {
    ll n; cin >> n;
    while (n != 1L) {
        printf("%lld ", n);
        if (n % 2L == 0) {
            n /= 2L;
        } else {
            n *= 3L;
            n++;
        }
    }
    printf("1\n");
}
 
int main() {
    initIO();
    solve();
    return 0;
}