#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll s_min, s_max;
int notSquare[1000001];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans = 0;
    cin >> s_min >> s_max;
    //제곱수가 max보다 커서는 안됨
    for (ll i = 2; i * i <= s_max; i++) {
        //무조건 제곱ㄴㄴ수 찾기: 이게 0 or i^2가 아니라면, smin은 무조건 제곱수가 아님
        ll st = i * i - s_min % (i * i);
        // 제곱ㄴㄴ수에 제곱수 계속 더해주면 제곱ㄴㄴ수와 서로소인 수를 거름: 에라토스테네스체
        // 제곱수면 0부터 돌아줘야 필요없는 범위가 안쪽 반복에서 스킵됨
        if (st == i * i) st = 0;
        for (ll k = st; k <= s_max - s_min; k += i * i) {
            notSquare[k] = 1;
            // cout << "i: " << i << " st: " << st << endl;
        }
    }
    for (int i = 0; i <= s_max - s_min; i++) {
        // if (notSquare[i])
        // cout << "notSquare[i]: " << i << endl;
        ans += !notSquare[i];
    }
    cout << ans;
    return 0;
}