#include <bits/stdc++.h>
#define MAX 501
using namespace std;

int mc[MAX][MAX], cost[MAX], psum[MAX];

int dp(int K) {
    for (int dist = 1; dist < K; dist++) {
        for (int x = 1; x + dist <= K; x++) {
            int y = x + dist;
            mc[x][y] = numeric_limits<int>::max();
            for (int pos = x; pos < y; pos++) {
                mc[x][y] = min(mc[x][y],
                               mc[x][pos] + mc[pos + 1][y] + psum[y] - psum[x - 1]);
            }
        }
    }
    return mc[1][K];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int L;
    cin >> L;
    for (int tl = 0, K; tl < L; tl++) {
        cin >> K;
        for (int i = 1; i <= K; i++) {
            cin >> cost[i];
            psum[i] = psum[i - 1] + cost[i];
        }
        cout << dp(K) << '\n';
    }

    return 0;
}