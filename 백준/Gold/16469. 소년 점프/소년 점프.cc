#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y, id;
};

int N, M;
int stage[201][201], dist[201][201][4];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
queue<Point> q;

void solve()
{
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, id = q.front().id;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (stage[nx][ny] == 0 && dist[nx][ny][id] == -1)
            {
                q.push({nx, ny, id});
                dist[nx][ny][id] = dist[x][y][id] + 1;
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    memset(dist, -1, sizeof(dist));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%1d", &stage[i][j]);

    for (int i = 0; i < 3; i++)
    {
        int tmpX, tmpY;
        cin >> tmpX >> tmpY;
        q.push({tmpX - 1, tmpY - 1, i});
        dist[tmpX - 1][tmpY - 1][i] = 0;
    }

    solve();
    int res = 1e9, count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int maxDist = max(max(dist[i][j][0], dist[i][j][1]), dist[i][j][2]);
            int minDist = min(min(dist[i][j][0], dist[i][j][1]), dist[i][j][2]);
            if (minDist != -1)
            {
                if (res > maxDist)
                {
                    res = maxDist;
                    count = 1;
                }
                else if (res == maxDist)
                    count += 1;
            }
        }
    }
    if (count != 0)
        cout << res << '\n'
             << count << '\n';
    else
        cout << -1 << '\n';

    return 0;
}