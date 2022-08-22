#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> v, r;
bool isChk[8];
void dfs(int curr, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++)
            cout << r[i] << ' ';
        cout << "\n";
    } else {
        for (int i = curr; i < N; i++) {
            if (isChk[i]) continue;
            isChk[i] = true;
            r.push_back(v[i]);
            dfs(i + 1, cnt + 1);
            r.pop_back();
            isChk[i] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    dfs(0, 0);
}