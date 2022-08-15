#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C;
    cin >> N >> C;
    vector<int> v;
    for (int i = 0, num; i < N; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int st = 1, end = v[N - 1] - v[0], R = 0;

    while (st <= end) {
        int dist = (st + end) / 2;
        int tc = 1, prev = v[0];
        for (int i = 0; i < N; i++) {
            if (v[i] - prev >= dist) {  // search max dist
                tc++;
                prev = v[i];
            }
        }
        if (tc >= C) {  // tc dwn -> dist range up
            st = dist + 1;
            R = max(R, dist);
        } else
            end = dist - 1;
    }

    cout << R << '\n';
    return 0;
}