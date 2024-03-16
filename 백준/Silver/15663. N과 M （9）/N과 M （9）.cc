#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
vector<int> ans;
vector<bool> visited;

void dfs(int cnt) {
  if (cnt == M) {
    for (int i = 0; i < M; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
    return;
  }

  int prev = -1;
  for (int i = 0; i < N; i++) {
    if (visited[i] || prev == arr[i]) continue;
    visited[i] = true;
    ans[cnt] = arr[i];
    prev = arr[i];
    dfs(cnt + 1);
    visited[i] = false;
  }
}

int main() {
  cin >> N >> M;
  arr.resize(N);
  ans.resize(M);
  visited.resize(N, false);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  dfs(0);
  return 0;
}