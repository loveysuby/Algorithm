#include <bits/stdc++.h>
#define node pair<pair<int, int>, int>
using namespace std;

bool cmp(node& ln, node& rn) {
    if (ln.first.second < rn.first.second)
        return true;
    else if (ln.first.second == rn.first.second)
        return ln.first.first < rn.first.first;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C, M, truck[2001];
    int R = 0;
    node v[10001];

    cin >> N >> C >> M;
    for (int i = 0; i < M; i++)
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    sort(v, v + M, cmp);
    for (int i = 0; i < M; i++) {
        int tmax = 0;
        for (int j = v[i].first.first; j < v[i].first.second; j++)
            tmax = max(tmax, truck[j]);
        int now = min(C - tmax, v[i].second);
        R += now;
        for (int j = v[i].first.first; j < v[i].first.second; j++)
            truck[j] += now;
    }
    cout << R;
    return 0;
}