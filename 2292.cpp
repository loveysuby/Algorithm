#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    int layer = 0;
    for (int sum = 2; sum <= N; layer++)
        sum += 6 * layer;
    if (N == 1) layer = 1;
    cout << layer;
    return 0;
}