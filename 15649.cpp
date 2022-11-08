#include <bits/stdc++.h>
using namespace std;

int N, M;
int curr[10], vis[10];
void foo(int arrLen) {
    if (arrLen == M) {
        for (int i = 0; i < M; i++) {
            cout << curr[i] + 1 << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        curr[arrLen] = i;
        foo(arrLen + 1);
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    foo(0);
}