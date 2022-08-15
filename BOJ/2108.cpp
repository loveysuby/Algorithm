#include <bits/stdc++.h>
using namespace std;

int N, mostCnt = -8999, mostNum, sum = 0;
int cnt[8002];
vector<int> v;
bool flag = false;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        cnt[tmp + 4000]++;
        sum += tmp;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 8001; i++) {
        if (cnt[i] == 0)
            continue;
        if (cnt[i] == mostCnt && flag) {
            mostNum = i - 4000;
            flag = false;
        }
        if (cnt[i] > mostCnt) {
            mostCnt = cnt[i];
            mostNum = i - 4000;
            flag = true;
        }
    }

    int avg = round((double)sum / N);
    if (avg == -0) avg = 0;

    cout << avg << '\n';
    cout << v[N / 2] << '\n';
    cout << mostNum << '\n';
    cout << v.back() - v.front() << '\n';

    return 0;
}