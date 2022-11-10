#include <bits/stdc++.h>
using namespace std;
#define MAX 123456 * 2

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    bool isPrime[MAX + 1];
    fill_n(isPrime + 2, MAX + 1, true);
    for (int i = 4; i <= MAX; i += 2)
        isPrime[i] = false;
    for (int i = 3; i <= sqrt(MAX); i += 2) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= MAX; j += i * 2)
            isPrime[j] = false;
    }
    int N;
    while (1) {
        cin >> N;
        if (N == 0) break;
        int R = 0;
        for (int i = N + 1; i <= N * 2; i++)
            if (isPrime[i]) R++;
        cout << R << '\n';
    }

    return 0;
}