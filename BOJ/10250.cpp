#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int H, W, N;
        cin >> H >> W >> N;
        int X = N / H + 1, Y = N % H;
        if (!Y) {
            Y = H;
            X -= 1;
        }

        printf("%d%02d\n", Y, X);
    }

    return 0;
}