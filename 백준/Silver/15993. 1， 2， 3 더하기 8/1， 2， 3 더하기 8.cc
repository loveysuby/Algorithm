#include <iostream>
#define ll long long
#define MOD 1000000009
using namespace std;

ll dp[100001][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  dp[1][1] = dp[2][0] = dp[2][1] = 1;
  dp[3][0] = dp[3][1] = 2;
  for (int i = 4; i <= 100000; i++) {
    dp[i][0] = (dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1]) % MOD;
    dp[i][1] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 3][0]) % MOD;
  }

  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;
    cout << dp[n][1] % MOD << " " << dp[n][0] % MOD << "\n";
  }
  return 0;
}