#include <bits/stdc++.h>
using namespace std;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

bool vis[100001];
int route, mintime;

void bfs(int N, int K) {
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    vis[N] = true;
    while (!q.empty()) {
        int curr = q.front().first;
        int time = q.front().second;
        q.pop();
        vis[curr] = true;

        //두 번째 방법부터
        if (route && curr == K && mintime == time)
            route++;
        //처음 K 도착
        if (!route && curr == K) {
            route++;
            mintime = time;  //최소 시간 기록
        }
        //큐에 넣을때 방문했다고 처리하면 그 다음 분기에서 1+1때문에 1*2가 카운트 안 됨 -> 2번 위치일 때(pop된 상태)에서 시간 기록

        if (curr - 1 >= 0 && !vis[curr - 1])
            q.push({curr - 1, time + 1});

        if (curr + 1 < 100001 && !vis[curr + 1])
            q.push({curr + 1, time + 1});

        if (curr * 2 < 100001 && !vis[curr * 2])
            q.push({curr * 2, time + 1});
    }
}
int main() {
    fastio;
    int N, K;
    cin >> N >> K;
    bfs(N, K);
    cout << mintime << '\n'
         << route << '\n';
}