#include <bits/stdc++.h>
using namespace std;

int arr[15][15] = {
    0,
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;

    for (int i = 1; i < 15; i++)
        arr[0][i] = i;
    while (T--) {
        int k, n;
        cin >> k >> n;
        for (int y = 1; y <= k; y++) {
            for (int x = 1; x <= n; x++) {
                if (arr[y][x]) continue;
                for (int c = 1; c <= x; c++) {
                    arr[y][x] += arr[y - 1][c];
                }
            }
        }
        printf("%d\n", arr[k][n]);
    }
    return 0;
}