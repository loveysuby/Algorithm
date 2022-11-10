#include <bits/stdc++.h>
using namespace std;
#define MAX 1299709
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T, k, c;
    cin >> T;
    bool isPrime[MAX + 1];
    fill_n(isPrime + 2, MAX + 1, true);
    for (int i = 4; i <= MAX; i += 2)
        isPrime[i] = false;
    for (int i = 3; i <= sqrt(MAX); i += 2) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= MAX; j += i * 2)
            isPrime[j] = false;
    }
    while (T--) {
        cin >> k;
        if (isPrime[k] || k == 1)
            cout << 0 << '\n';
        else {
            c = 0;
            for (int i = k; !isPrime[i]; i++) c++;
            for (int i = k; !isPrime[i]; i--) c++;
            cout << c << '\n';
        }
    }
    return 0;
}