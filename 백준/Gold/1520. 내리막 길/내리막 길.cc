#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<vector<int>> map;
vector<vector<int>> dp;

int dfs(int x, int y) {
  if (x == M - 1 && y == N - 1) return 1;
  if (dp[x][y] != -1) return dp[x][y];

  dp[x][y] = 0;
  if (x > 0 && map[x][y] > map[x - 1][y]) dp[x][y] += dfs(x - 1, y);
  if (x < M - 1 && map[x][y] > map[x + 1][y]) dp[x][y] += dfs(x + 1, y);
  if (y > 0 && map[x][y] > map[x][y - 1]) dp[x][y] += dfs(x, y - 1);
  if (y < N - 1 && map[x][y] > map[x][y + 1]) dp[x][y] += dfs(x, y + 1);

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