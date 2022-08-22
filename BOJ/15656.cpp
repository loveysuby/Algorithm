#include <bits/stdc++.h>
using namespace std;
int N, M;
int r[8], v[8];
void dfs(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++)
            cout << r[i] << ' ';
        cout << "\n";
    } else {
        for (int i = 0; i < N; i++) {
            r[cnt] = v[i];
            dfs(cnt + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v, v + N);
    dfs(0);
}