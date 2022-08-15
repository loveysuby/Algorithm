#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N, K, R;
    cin >> N >> K;
    int st = 1, en = K;
    while (st <= en) {
        ll cnt = 0;
        int mid = (st + en) / 2;
        for (int i = 1; i <= N; i++)
            cnt += min(mid / i, N);
        if (cnt < K)
            st = mid + 1;
        else {
            R = mid;
            en = mid - 1;
        }
    }
    cout << R;
    return 0;
}