#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
  double xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  cout << fixed;
  cout.precision(10);
  if ((xa - xb) * (ya - yc) == (ya - yb) * (xa - xc)) {
    cout << -1;
    return 0;
  }
  double ab = dist(xa, ya, xb, yb);
  double bc = dist(xb, yb, xc, yc);
  double ac = dist(xa, ya, xc, yc);
  double max_dist = max(ab, max(bc, ac));
  double min_dist = min(ab, min(bc, ac));
  cout << 2.0 * (max_dist - min_dist) << '\n';
  return 0;
}