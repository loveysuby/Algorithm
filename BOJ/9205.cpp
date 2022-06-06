#include <bits/stdc++.h>
using namespace std;
int dp[25];
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t, p;
        cin >> t >> p;
        if (dp[i + 1] < dp[i])
            dp[i + 1] = dp[i];
        if (dp[i + t] < dp[i] + p)
            dp[i + t] = dp[i] + p;
    }
    cout << dp[N];
    return 0;
}