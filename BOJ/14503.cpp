#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, d;
int board[51][51];
int res = 0;
int ny[4] = { 0, -1, 0, 1 }, nx[4] = { -1, 0, 1, 0 };

int main()
{
    cin >> N >> M;
    cin >> y >> x >> d;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    bool isClean = true;
    while (isClean)
    {
        if (!board[y][x])
            res++;
        board[y][x] = 2;
        for (int i = 0; i < 5; i++)
        {
            // backstep == left * 2 -> 왼쪽으로 방향 바꾼 상태로 넘어오므로, 한번 더 돌림
            if (i == 4)
            {
                int dy = y + ny[(d + 3) % 4];
                int dx = x + nx[(d + 3) % 4];
                if (board[dy][dx] != 1)
                {
                    y = dy;
                    x = dx;
                }
                else
                    isClean = false;
                break;
            }

            int dy = y + ny[d];
            int dx = x + nx[d];

            d = (d + 3) % 4;

            if (!board[dy][dx])
            {
                y = dy;
                x = dx;
                break;
            }
        }
    }
    cout << res << '\n';
    return 0;
}