#include <bits/stdc++.h>
using namespace std;
// Define
#define INF -1000000007
#define SIZE 8
// Global elements
int dp[2][1001][8];
int board[2][3];
// Function

// Driver
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt[8] = {0, 1, 1, 2, 1, 2, 2, 3};
    int temp[8];
    int N, M, result = 0;
    cin >> N >> M;

    for (int i = 0; i <= M; i++) {
        for (int j = 0; j < 8; j++)
            dp[0][i][j] = dp[1][i][j] = INF;
    }
    dp[0][0][0] = 0;
    for (int i = 1, prev = 0, curr = 1; i <= N; i++, swap(prev, curr)) {
        for (int j = 0; j < 3; j++)
            cin >> board[curr][j];

        for (int j = 0; j <= M; j++)
            for (int k = 0; k < SIZE; k++)
                dp[curr][j][0] = max(dp[curr][j][0], dp[prev][j][k]);

        if (i > 1) {
            temp[1] = board[curr][0] + board[prev][0];
            temp[2] = board[curr][1] + board[prev][1];
            temp[4] = board[curr][2] + board[prev][2];
            temp[3] = temp[1] + temp[2];
            temp[5] = temp[1] + temp[4];
            temp[6] = temp[2] + temp[4];
            temp[7] = temp[3] + temp[4];
        }
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (i > 1 && dp[prev][j][k] != INF && j < M) {
                    for (int p = 1; p < SIZE; p++) {
                        int j_temp = j + cnt[p];
                        int addPtr = dp[prev][j][k] + temp[p];
                        if (M < j_temp || (k & p)) continue;
                        dp[curr][j_temp][p] = max(dp[curr][j_temp][p], addPtr);
                    }
                }
                dp[prev][j][k] = INF;
            }
        }

        for (int j = 0; j < M; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (dp[curr][j][k] == INF) continue;
                if (!(k & 3))
                    dp[curr][j + 1][k + 3] = max(dp[curr][j + 1][k + 3],
                                                 dp[curr][j][k] + board[curr][0] + board[curr][1]);
                if (!(k & 6)) {
                    dp[curr][j + 1][k + 6] = max(dp[curr][j + 1][k + 6],
                                                 dp[curr][j][k] + board[curr][1] + board[curr][2]);
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
        result = max(result, dp[N % 2][M][i]);

    cout << result;

    return 0;
}