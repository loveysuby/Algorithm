#include <bits/stdc++.h>
using namespace std;
int N, v[11], op[4];
int r_min = 1e9, r_max = -1e9;
void solve(int result, int idx) {
    if (idx == N) {
        if (result > r_max)
            r_max = result;
        if (result < r_min)
            r_min = result;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            op[i]--;
            switch (i) {	
                case 0:
                    solve(result + v[idx], idx + 1);
                    break;
                case 1:
                    solve(result - v[idx], idx + 1);
                    break;
                case 2:
                    solve(result * v[idx], idx + 1);
                    break;
                case 3:
                    solve(result / v[idx], idx + 1);
                    break;
            }
            op[i]++;
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> v[i];
    for (int i = 0; i < 4; i++)
        cin >> op[i];
    solve(v[0], 1);
    cout << r_max << '\n'
         << r_min;
    return 0;
}