#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;
    int cnt = 0, X = N;
    do {
        X = (X % 10) * 10 + (X / 10 + X % 10) % 10;
        cnt++;
    } while (X != N);
    cout << cnt << '\n';
    return 0;
}