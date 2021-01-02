#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    //결과값에서는 필요한 연산 수가 없다.
    memset(dp, 0, sizeof(dp) * (num + 1));

    for (int i = 2; i <= num; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        dp[i] = dp[i / 3] + 1;
        dp[i] = dp[i / 2] + 1;
    }
    return 0;
}