#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin >> num;
    //결과값에서는 필요한 연산 수가 없다.
    memset(dp, 0, sizeof(int) * (num + 1));

    for (int i = 2; i <= num; ++i) {
        dp[i] = dp[i - 1] + 1;  // 1 빼주기
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
        // 바로 2 나눈거랑 1뺀거 (기존) 중에 더 작은 연산수 dp배열에 저장
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);  // ``
    }
    cout << dp[num];
    return 0;
}