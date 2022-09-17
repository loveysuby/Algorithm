#include <bits/stdc++.h>
using namespace std;
int prefixNum[1001];
bool isTri(int num) {
    for (int i = 1; i <= 46; i++)
        for (int j = 1; j <= 46; j++)
            for (int k = 1; k <= 46; k++)
                if (prefixNum[i] + prefixNum[j] + prefixNum[k] == num) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    for (int i = 1; i <= 1000; i++)
        prefixNum[i] = prefixNum[i - 1] + i;

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        cout << isTri(N) << '\n';
    }
    return 0;
}