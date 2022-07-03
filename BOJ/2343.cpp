#include <bits/stdc++.h>
using namespace std;

int V[100001];
int N, M;

int calc(int piv) {
    int cut = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        sum += V[i];
        if (piv < sum) {  //일정 구간 넘긴경우 -> 한 타임 뒤로 빼고 구간 나눔
            i--;
            sum = 0;
            cut++;
        }
    }
    return cut;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> V[i];

    int st = *max_element(V, V + N), end = 1e9;

    while (st <= end) {
        int mid = (st + end) / 2;
        int cnt = calc(mid);
        if (cnt >= M)
            st = mid + 1;
        else
            end = mid - 1;
    }
    cout << st;

    return 0;
}