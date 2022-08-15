#include <bits/stdc++.h>
#define MIN (-1ll << 62) - 1
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, cnt = 1, maxc = 0;
    long long a[100001], maxv = MIN;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    a[N] = (1ll << 62) + 1;  // MAX+1(out of range) -> exception point
    sort(a, a + N);

    for (int i = 1; i <= N; i++) {
        if (a[i] != a[i - 1]) {
            if (cnt > maxc) {  // base
                maxc = cnt;
                maxv = a[i - 1];
            }
            cnt = 1;
        } else
            cnt++;
    }
    cout << maxv;
    return 0;
}