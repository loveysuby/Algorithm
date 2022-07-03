#include <bits/stdc++.h>
using namespace std;

int N, M, sum;

vector<int> v;

bool chk(int k) {
    int fill = 1, tk = k;

    for (int i = 0; i < N; i++) {
        if (k < v[i])
            return false;

        if (tk < v[i]) {  //돈채워야함
            fill++;
            tk = k;
        }
        tk -= v[i];
    }
    return fill <= M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0, num; i < N; i++) {
        cin >> num;
        v.push_back(num);
        sum += num;
    }

    int maxc = sum, minc = 1, res = 0;

    while (minc <= maxc) {
        int mid = (minc + maxc) / 2;

        if (chk(mid)) {  // mid down
            res = mid;
            maxc = mid - 1;
        } else  // mid up
            minc = mid + 1;
    }

    cout << res << '\n';
    return 0;
}
