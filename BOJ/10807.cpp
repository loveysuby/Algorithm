#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, v, r = 0;
    cin >> N;
    int a[N + 1];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cin >> v;
    for (int i = 0; i < N; i++) {
        if (a[i] == v) r++;
    }
    cout << r;
    return 0;
}
