#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, T, v[10001];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> v[i];
    cin >> T;

    int st = 0, end = *max_element(v, v + N);

    while (st <= end) {
        int tmp = 0,
            mid = (st + end) / 2;
        for (int i = 0; i < N; i++) {
            if (v[i] >= mid)
                tmp += mid;
            else
                tmp += v[i];
        }
        if (tmp > T)
            end = mid - 1;
        else
            st = mid + 1;
    }
    cout << end << '\n';
    return 0;
}