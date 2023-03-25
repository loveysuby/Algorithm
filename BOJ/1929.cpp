#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int M, N;
    cin >> M >> N;
    bool prime[N + 1];
    fill_n(prime, N + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= N; i++)
        if (prime[i] == true)
            for (int j = i * 2; j <= N; j += i)
                prime[j] = false;
    for (int i = M; i <= N; i++)
        if (prime[i] == true)
            cout << i << '\n';
    return 0;
}