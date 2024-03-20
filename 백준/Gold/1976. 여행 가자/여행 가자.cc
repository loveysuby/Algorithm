#include <iostream>

using namespace std;

int root(int i);
void merge(int i, int j);
int node[1001];
int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 1; i <= N; i++) node[i] = i;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int temp;
      cin >> temp;
      if (temp == 1) merge(i, j);
    }
  }
  int start;
  cin >> start;
  start = root(start);
  for (int i = 1; i < M; i++) {
    int temp;
    cin >> temp;
    if (start != root(temp)) {
      while (M--) {
        int temp;
        cin >> temp;
      }
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}

int root(int i) {
  while (i != node[i]) i = node[i];
  return i;
}

void merge(int i, int j) {
  i = root(i);
  j = root(j);
  node[i] = j;
}