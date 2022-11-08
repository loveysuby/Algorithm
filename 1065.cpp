#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, R = 0;
    cin >> N;
    int* arr = new int[N + 1];
    for (int i = 1; i <= N; i++) {
        if (i < 100) {
            R++;
            continue;
        } else if (i / 100 - (i % 100) / 10 ==
                   (i % 100) / 10 - (i % 100) % 10)
            R++;
    }
    cout << R;
    return 0;
}