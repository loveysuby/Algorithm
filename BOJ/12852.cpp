#include <bits/stdc++.h>
using namespace std;
int N;
int r[1000001], T[1000001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 2; i <= N; i++) {
        r[i] = r[i - 1] + 1;
        T[i] = i - 1;
        if (i % 2 == 0 && r[i] > r[i / 2] + 1) {
            r[i] = r[i / 2] + 1;
            T[i] = i / 2;
        }
        if (i % 3 == 0 && r[i] > r[i / 3] + 1) {
            r[i] = r[i / 3] + 1;
            T[i] = i / 3;
        }
    }
    cout << r[N] << '\n';
    while (1) {
        cout << N << ' ';
        if (N == 1) break;
        N = T[N];
    }
    return 0;
}