#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int cnt;
    cin >> cnt;
    int* arr = new int[cnt];
    for (int i = 0; i < cnt; i++)
        cin >> arr[i];
    int max = *max_element(arr, arr + cnt);
    bool* prime = new bool[max + 1];
    fill_n(prime, max + 1, 1);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= sqrt(max); i++) {
        if (prime[i] == false) continue;
        for (int j = i + i; j <= max; j += i)
            prime[j] = false;
    }
    for (int T = 0; T < cnt; T++) {
        for (int i = arr[T] / 2; i > 0; i--) {
            if (prime[i] && prime[arr[T] - i]) {
                cout << i << ' ' << arr[T] - i << '\n';
                break;
            }
        }
    }
    return 0;
}