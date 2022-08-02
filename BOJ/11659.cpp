#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, num[100001], psum[100001];
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
        psum[i] = psum[i - 1] + num[i];
    }
    while (M--) {
        int i, j;
        cin >> i >> j;
        cout << psum[j] - psum[i - 1] << '\n';
    }
    return 0;
}