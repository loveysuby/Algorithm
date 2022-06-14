#include <bits/stdc++.h>
using namespace std;
int sx, sy, ex, ey;
int board[10][9];
int dx[8][3] = {{-1, -2, -3}, {-1, -2, -3}, {0, -1, -2}, {0, -1, -2}, {0, 1, 2}, {0, 1, 2}, {1, 2, 3}, {1, 2, 3}};
int dy[8][3] = {{0, -1, -2}, {0, 1, 2}, {-1, -2, -3}, {1, 2, 3}, {-1, -2, -3}, {1, 2, 3}, {0, -1, -2}, {0, 1, 2}};

bool check(int routeNum, int &nx, int &ny) {
    int tmpx = nx, tmpy = ny;

    for (int moveCnt = 0; moveCnt < 3; moveCnt++) {
        tmpx = nx + dx[routeNum][moveCnt], tmpy = ny + dy[routeNum][moveCnt];

        //상의 최종 도착위치에 왕이 있어야 됨 -> 3칸을 움직여야 1번 이동 처리
        if (moveCnt < 2 && tmpx == ex && tmpy == ey) return false;
        if (tmpx < 0 || tmpx >= 10 || tmpy < 0 || tmpy >= 9) return false;
    }

    nx = tmpx, ny = tmpy;
    return true;
}

void mate() {
    queue<pair<int, int>> q;
    q.push(pair<int, int>(sx, sy));
    board[sx][sy] = 0;

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (x == ex && y == ey) {
            cout << board[x][y] << '\n';
            return;
        }

        for (int i = 0; i < 8; i++) {
            int tx = x, ty = y;
            if (check(i, tx, ty) && board[tx][ty] == -1) {
                q.push(make_pair(tx, ty));
                board[tx][ty] = board[x][y] + 1;
            }
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> sx >> sy >> ex >> ey;
    memset(board, -1, sizeof(board));
    mate();
    return 0;
}