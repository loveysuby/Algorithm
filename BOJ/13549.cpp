#include <bits/stdc++.h>
using namespace std;

bool vis[200002];

void bfs(int N, int K) {
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    vis[N] = 1;

    while (!q.empty()) {
        int curr = q.front().first;
        int time = q.front().second;

        q.pop();
        vis[curr] = 1;

        if (curr == K) {
            cout << time << '\n';
            return;
        }
        //순간이동 하는 경우부터 먼저 큐에 넣어주어 최소 시간이 나오는 기대값 반영
        if (curr * 2 < 200002 && !vis[curr * 2]) {
            vis[curr * 2] = 1;
            q.push({curr * 2, time + 1});
        }

        if (curr - 1 >= 0 && !vis[curr - 1]) {
            vis[curr - 1] = 1;
            q.push({curr - 1, time + 1});
        }
        if (curr + 1 < 100001 && !vis[curr + 1]) {
            vis[curr + 1] = 1;
            q.push({curr + 1, time + 1});
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    bfs(N, K);
    return 0;
}
