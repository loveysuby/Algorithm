#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  int cnt = 0;
  while (s.length() > 1) {
    int val = 0;
    for (auto c : s) val += c - '0';
    s = to_string(val);
    cnt++;
  }

  cout << cnt << "\n" << ((s == "3" || s == "6" || s == "9") ? "YES" : "NO");
  return 0;
}