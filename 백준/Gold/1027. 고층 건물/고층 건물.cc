#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> buildings;
vector<int> result;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  buildings.resize(N);
  result.resize(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> buildings[i];
  }

  for (int i = 0; i < N; i++) {
    double max_gradient = -1e9;
    for (int j = i + 1; j < N; j++) {
      int k = buildings[j] - buildings[i];
      int l = j - i;
      double slope = k * (1.0) / l;

      if (slope <= max_gradient) continue;

      max_gradient = slope;
      result[i]++;
      result[j]++;
    }
  }
  cout << *max_element(result.begin(), result.end()) << '\n';
  return 0;
}