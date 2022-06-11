#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pii v[101];
    int r[101][100001];
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> v[i].first >> v[i].second;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            r[i][j] = r[i - 1][j];
            if (v[i].first <= j)
                r[i][j] = max(v[i].second + r[i - 1][j - v[i].first],
                              r[i][j]);
        }
    }
    cout << r[N][K];

    return 0;
}