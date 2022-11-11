#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    bool prime[500000];
    // 소수의 합-> 절반기준으로 나눠서 탐색하면됨
    for (int i = 3; i <= MAX; i += 2) {
        if (prime[i / 2]) continue;
        // if (prime[i]) continue;
        for (int j = i * i; j <= MAX * MAX; j += i * 2)
            // 최대 크기까지 소수 표현할 필요없으므로 index 반땡 -> 구간 내에서 무조건 답 있음
            prime[j / 2] = true;
    }

    int N;
    while (1) {
        cin >> N;
        if (N == 0) break;
        // ONLY ODD
        for (int i = 3; i <= N; i += 2) {
            if (!prime[i / 2] && !prime[(N - i) / 2]) {
                cout << N << " = " << i << " + " << N - i << '\n';
                break;
            }
        }
    }
    return 0;
}