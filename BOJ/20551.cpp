#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, Q, a[200002];
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a, a + N);
    for (int i = 0; i < M; i++) {
        cin >> Q;
        int qs = lower_bound(a, a + N, Q) - a;
        cout << ((a[qs] == Q && qs != N) ? qs : -1) << '\n';
    }
    return 0;
}