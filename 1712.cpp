#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int A, B, C;
    cin >> A >> B >> C;
    if (B >= C) {
        cout << -1;
        return 0;
    }
    cout << (A / (C - B)) + 1;
    return 0;
}