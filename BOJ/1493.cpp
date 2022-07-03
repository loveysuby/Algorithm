#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll length, width, height, N, c[21];
    ll res = 0, blocks = 0, cnt = 0;
    cin >> length >> width >> height;
    cin >> N;

    for (int i = 0, x, y; i < N; i++) {
        cin >> x >> y;
        c[x] = y;
    }
    for (int i = N - 1; i >= 0; i--) {
        blocks <<= 3;
        ll curr = ((length >> i) * (width >> i) * (height >> i)) - blocks;
        cnt = min(c[i], curr);
        blocks += cnt;
        res += cnt;
    }
    if ((ll)length * width * height == blocks)
        cout << res;
    else
        cout << -1;

    return 0;
}