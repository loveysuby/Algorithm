#include <bits/stdc++.h>
using namespace std;
int c[1001][1001];
int comb(int x, int y) {
    if (x == y || y == 0) return 1;
    int& num = c[x][y];
    if (num) return num;
    return num = (comb(x - 1, y - 1) + comb(x - 1, y)) % 10007;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    cout << comb(N, K) % 10007;

    return 0;
}