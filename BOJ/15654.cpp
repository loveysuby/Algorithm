#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> v, r;
bool isChk[9];
void dfs(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < r.size(); i++)
            cout << r[i] << ' ';
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; i++) {
        if (isChk[i]) continue;
        isChk[i] = true;
        r.push_back(v[i]);
        dfs(cnt + 1);
        r.pop_back();
        isChk[i] = false;
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
    dfs(0);
}