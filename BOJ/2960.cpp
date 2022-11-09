#include <bits/stdc++.h>
using namespace std;
int N, K, R, a[1001], C;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K;
    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            if (!a[j]) {
                a[j] = 1;
                C++;
                if (K == C) {
                    R = j;
                    break;
                }
            }
            if (C == K) break;
        }
    }
    cout << R;
}