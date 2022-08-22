#include <bits/stdc++.h>
using namespace std;
int N, M;
int v[8], r[8], isChk[8];
void dfs(int curr, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++)
            cout << r[i] << ' ';
        cout << "\n";
        return;
    }
    for (int i = curr; i < N; i++) {
        r[cnt] = v[i];
        dfs(i, cnt + 1);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v, v + N);
    dfs(0, 0);
}