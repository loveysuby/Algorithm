#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    bool chk[30];
    for (int i : chk) chk[i] = false;
    for (int i = 0; i < 28; i++) {
        int tmp;
        cin >> tmp;
        chk[tmp] = true;
    }
    for (int i = 1; i <= 30; i++) {
        if (!chk[i]) cout << i << '\n';
    }
    return 0;
}