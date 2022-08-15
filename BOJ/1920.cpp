#include <bits/stdc++.h>
using namespace std;
int N, M, a[100001];
int bs(int num) {
    int st = 0, end = N - 1;
    while (st <= end) {
        int mid = (st + end) / 2;
        if (a[mid] < num)
            st = mid + 1;
        else if (a[mid] > num)
            end = mid - 1;
        else
            return 1;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a, a + N);
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        cout << bs(x) << '\n';
    }
    return 0;
}