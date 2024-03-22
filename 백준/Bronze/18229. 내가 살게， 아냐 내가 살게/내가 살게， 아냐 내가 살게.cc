#include <iostream>
using namespace std;

int N, M;
long long K;
pair<int, int> res;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  res = pair<int, int>(101, 101);

  cin >> N >> M >> K;

  for (int i = 0; i < N; ++i) {
    long long temp = 0;
    for (int j = 0; j < M; ++j) {
      long long num;
      cin >> num;
      temp += num;

      if (temp >= K)
        if (j < res.second) res = pair<int, int>(i, j);
    }
  }

  cout << res.first + 1 << ' ' << res.second + 1 << '\n';
  return 0;
}