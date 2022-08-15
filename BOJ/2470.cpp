#include <bits/stdc++.h>
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(), (x).end()

using namespace std;
#define MAX 2e9
int N;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    vector<int> v;
    for0(i, N) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int minV = MAX, minX, minY;
    int st = 0, en = N - 1;
    while (st < en) {
        int mix = v[st] + v[en];
        if (abs(mix) < abs(minV)) {
            minV = mix;
            minX = v[st];
            minY = v[en];
            if (mix == 0) break;
        }
        if (mix < 0)
            st++;
        else if (mix == 0)
            break;
        else
            en--;
    }
    cout << minX << ' ' << minY;
    return 0;
}