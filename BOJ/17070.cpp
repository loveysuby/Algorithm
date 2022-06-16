#include <bits/stdc++.h>
using namespace std;
int N, res = 0;
int a[16][16];
const int dx[3] = {1, 0, 1};
const int dy[3] = {0, 1, 1};

bool isMovable(int x, int y, int nx, int ny) {
    for (int i = x; i <= nx; i++)
        for (int j = y; j <= ny; j++)
            // row col 뒤집어짐
            if (a[j][i]) return false;
    return true;
}

void bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(1, 0), 0));

    while (!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second;
        int look = q.front().second;
        q.pop();

        if (x == N - 1 and y == N - 1) {
            res++;
            continue;
        }
        // 1 a -> 0 1 c a // 2 b -> 0 2 c b// 0 c ->0 1 2 a b c

        for (int i = 0; i < 3; i++) {  // 012 abc lef dwn dig
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= N || ny >= N || (look == 1 && i == 0) || (look == 0 && i == 1))
                continue;
            if (isMovable(x, y, nx, ny)) {
                q.push(make_pair(make_pair(nx, ny), i));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(a, -1, sizeof(a));
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];
    bfs();
    cout << res;
    return 0;
}