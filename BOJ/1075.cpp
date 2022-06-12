#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, F;
    cin >> N >> F;

    N -= N % 100;
    for (int i = 0; i < 100; i++) {
        if (!((N + i) % F)) {
            if (i < 10)
                cout << '0' << i << '\n';
            else
                cout << i << '\n';
            return 0;
        } else
            continue;
    }

    return 0;
}