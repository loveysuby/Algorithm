#include <bits/stdc++.h>
using namespace std;

void bfs(int N, int K) {
    int vis[100001];
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    vis[N] = 1;

    memset(vis, -1, sizeof(vis));
    vector<int> rec;
    rec.push_back(K);

    while (!q.empty()) {
        int curr = q.front().first;
        int time = q.front().second;

        q.pop();

        if (curr == K) {
            cout << time << '\n';
            break;
        }
        //순간이동 하는 경우부터 먼저 큐에 넣어주어 최소 시간이 나오는 기대값 반영
        if (curr * 2 < 100001 && vis[curr * 2] == -1) {
            vis[curr * 2] = curr;  // vis(이동할 노드) = 현재 노드(과거 노드) -> 역추적
            q.push({curr * 2, time + 1});
        }

        if (curr - 1 >= 0 && vis[curr - 1] == -1) {
            vis[curr - 1] = curr;
            q.push({curr - 1, time + 1});
        }
        if (curr + 1 < 100001 && vis[curr + 1] == -1) {
            vis[curr + 1] = curr;
            q.push({curr + 1, time + 1});
        }
    }
    while (K != N) {
        rec.push_back(vis[K]);
        K = vis[K];
    }
    for (int i = rec.size() - 1; i >= 0; i--)
        cout << rec[i] << ' ';
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
