#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int x1, y1, x2, y2, N, res = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> N;
    for (int j = 0; j < N; j++) {
      int cx, cy, r;
      cin >> cx >> cy >> r;

      int radiosPow = r * r;
      int d1 = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy);
      int d2 = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy);
      if (d1 < radiosPow && d2 < radiosPow)
        continue;
      else if (d1 < radiosPow || d2 < radiosPow)
        res++;
    }
    cout << res << "\n";
  }
}