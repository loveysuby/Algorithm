#include <bits/stdc++.h>
#define pli pair<long long, int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<pli> q;
    int a, b;
    cin >> a >> b;
    q.push(make_pair(a, 0));
    while (!q.empty()) {
        pli c = q.front();
        q.pop();
        if (c.first == b) {
            cout << c.second + 1;
            return 0;
        }
        if (c.first * 10 + 1 <= b) {
            q.push(make_pair(c.first * 10 + 1, c.second + 1));
        }
        if (c.first * 2 <= b) {
            q.push(make_pair(c.first * 2, c.second + 1));
        }
    }
    cout << -1;
    return 0;
}