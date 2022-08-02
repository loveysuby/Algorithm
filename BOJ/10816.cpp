#include <bits/stdc++.h>
using namespace std;
int N, M, a[500001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    cin >> M;
    sort(a, a + N);
    while (M--) {
        int target;
        cin >> target;
        cout << upper_bound(a, a + N, target) - lower_bound(a, a + N, target) << ' ';
    }
    return 0;
}