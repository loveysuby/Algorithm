#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int dp[1001];
    dp[1] = 1;
    dp[2] = 2;
    cin >> n;
    for (int i = 3; i <= n; i++)
        //mod 연산값을 저장하지 않으면 int 표현 한계 넘을 수도 있고, 메모리 소모도 크다.
        // => 답을 구하는게 목적이므로, dp로 해결
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    cout << dp[n];
    return 0;
}