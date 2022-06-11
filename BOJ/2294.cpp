#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, c[101], r[10001];
    cin >> N >> K;
    for (int i = 1; i <= K; i++)
        r[i] = 99999;

    for (int i = 1; i <= N; i++) {
        cin >> c[i];
        for (int j = c[i]; j <= K; j++)
            r[j] = min(r[j], r[j - c[i]] + 1);
    }
    if (r[K] == 99999)
        cout << -1 << '\n';
    else
        cout << r[K] << '\n';
    return 0;
}