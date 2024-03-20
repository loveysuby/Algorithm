#include <cmath>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int m;
    cin >> m;
    double digits = 0;
    for (int i = 1; i <= m; i++) digits += log10(i);
    cout << (int)digits + 1 << "\n";
  }
  return 0;
}