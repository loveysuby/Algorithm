#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<vector<int>> map;
vector<vector<int>> dp;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int dfs(int x, int y) {
  if (x == M - 1 && y == N - 1) return 1;
  if (dp[x][y] != -1) return dp[x][y];

  dp[x][y] = 0;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
    if (map[nx][ny] < map[x][y]) dp[x][y] += dfs(nx, ny);
  }
  return dp[x][y];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> M >> N;
  map.assign(M, vector<int>(N));
  dp.assign(M, vector<int>(N, -1));
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++) cin >> map[i][j];

  cout << dfs(0, 0);
}