#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, K;
    cin >> N >> K;
    int a[1001];
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a, a + N);
    cout << a[N - K];
    return 0;
}