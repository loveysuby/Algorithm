#include <bits/stdc++.h>
using namespace std;
// Driver
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> dp(N + 1, 1e9);
    for (int i = 1; i <= N; i++)
        if ((int)sqrt(i) * (int)sqrt(i) == i)
            dp[i] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= (int)sqrt(i); j++)
            dp[i] = min(dp[i], dp[i - j * j] + dp[j * j]);
    cout << dp[N];
    return 0;
}