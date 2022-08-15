#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;
    vector<int> prime;

    prime.push_back(2);

    for (int i = 3; i <= 100000; i += 2) {
        bool isPrime = true;
        for (int j = 3; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            prime.push_back(i);
    }

    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 0; i <= prime.size(); i++) {
            if (N == 1) break;
            int mtCnt = 0;

            while ((N % prime[i]) == 0) {
                N /= prime[i];
                mtCnt++;
            }

            if (mtCnt)
                cout << prime[i] << ' ' << mtCnt << '\n';
        }
    }

    return 0;
}